import yasha
import copy

class Struct:
    def __init__(self, entries):
        self.__dict__.update(entries)

class Type:
    def __init__(self, config, test_config):
        tconfig                 = config.get("type")
        self.type               = tconfig.get("type")
        self.branch             = tconfig.get("branch")
        self.vector_t           = tconfig.get("vector_t")
        self.scalar_t           = tconfig.get("scalar_t")
        self.vec_size           = tconfig.get("vec_size")
        self.alignment          = tconfig.get("alignment")

        self.traits             = Struct(tconfig.get("traits"))

        self.test_config        = test_config.get("modules")

        self.construction       = [Module.make_construction(self, config["modules"], "construction") ]
        self.modules            = { m.name:m for m in [Module.make_module(self, k, v) for (k, v) in config["modules"].items() if k != "construction" ]}


    def get_modules(self):
        return self.construction + list(self.modules.values())

    def get_traits(self):
        return [ "{}::impl".format(module) for module in self.traits.external] \
               + [ "{}<impl>::template impl".format(self.modules[module].mangled_name()) for module in self.traits.internal ] \
               + [ "{}<impl>::template impl".format(self.construction[0].mangled_name()) ]

class Module:
    def __init__(self, parent, name, functions):
        self.parent         = parent
        self.type           = parent.type
        self.functions      = functions
        self.name           = name
        self.test_config    = parent.test_config and parent.test_config.get(name)
        self.mangling       = bool(1)
        #print("Building module", self.name)

    @classmethod
    def make_module(cls, parent, name, entries):
        result =  cls(parent, name, [])
        result.mangling  = entries.get("mangling", bool(1))
        result.functions = [Func(result, k, v) for k,v in entries.items() if k != "mangling"]

        return result

    @classmethod
    def make_construction(cls, parent, modules, sector):
        result =  cls(parent, sector, [])
        result.functions = [Func.make_constructor(result, entry) for entry in modules.get(sector, []) or []]

        return result

    def mangled_name(self):
        return "{}_{}".format(self.parent.type, self.name)

    def has_tests(self):
        return any(func.has_tests() for func in self.functions)

class Func:

    func_template       = "{prefix} {returns} {name}({args}) {suffix} noexcept"
    cons_template       = "{name}({args}) {suffix}"
    cons_template_init  = "{name}({args}) : {initializer} {suffix}"

    default_branch      = "default"

    def __init__(self, parent, name, entries):
        if type(entries) is str:
            entries = { "body": entries }

        is_copy = type(entries) is Func # Prototype copy

        self.args = entries.args if is_copy else Args(entries.get("args", ["one", "other"]))
        self.body = entries.body if is_copy else entries.get("body", "")

        self.branch_name = entries.branch_name if is_copy else "default"
        self.is_branched= type(self.body) is dict

        assert not self.is_branched or self.default_branch in self.body, "default branch required"

        self.inits      = entries.inits if is_copy else Inits(entries.get("init", ""))
        self.requires   = entries.requires if is_copy else entries.get("requires", [])
        self.parent     = entries.parent if is_copy else parent
        self.name       = entries.name if is_copy else name

        self.mangling   = entries.mangling if is_copy else entries.get("mangling", parent.mangling)

        self.is_member = entries.is_member if is_copy else entries.get("member")

        self.prefix     = entries.prefix if is_copy else "friend" if not self.is_member else ""
        self.suffix     = entries.suffix if is_copy else entries.get("suffix", "const" if self.is_member else "")
        self.returns    = entries.returns if is_copy else entries.get("returns", "composed_t")

        test       = parent.test_config and parent.test_config.get(self.name)

        if test and type(test) == list and len(test) == 2:
            self.actual     = test[0].format(type = "z"+parent.parent.type)#+"<>")
            self.expected   = test[1]
            self.test = [self.actual, self.expected]
        else:
            self.test = None

    def summarized_args(self):
        args = self.args.declaration()
        #return textwrap.shorten(self.args, width = 20)
        return args[:32] + (args[32:] and '..')

    def signature(self):
        name = self.mangled_name()

        if self.name:
            return self.func_template.format(prefix     = self.prefix,
                                             returns    = self.returns,
                                             name       = name,
                                             args       = self.args,
                                             suffix     = self.suffix).strip()
        elif self.inits:
            return self.cons_template_init.format(  name          = "__impl",
                                                    args          = self.args,
                                                    initializer   = self.inits,
                                                    suffix        = self.suffix).strip()
        else:
            return self.cons_template.format(   name   = "__impl",
                                                args   = self.args,
                                                suffix = self.suffix).strip()

    def mangled_name(self):
        if self.mangling:
            return "{}_{}".format(self.parent.name, self.name)

        return self.name

    def has_tests(self):
        return self.test != None

    def get_instructions(self):
        return Body(self, self.body).get_instructions();

    def branch_defs(self):
        if not self.is_branched:
            yield self.default_branch, self.body
        else:
            return iter(self.body)

    def branches(self):
        if not self.is_branched:
            yield self
        else:
            for (branch, body) in self.body.items():
                yield Func.__make_branch(self, branch, body)


    def __repr__(self):
        return self.signature()

    def is_constructor(self):
        return not self.name

    @classmethod
    def make_constructor(cls, parent, entries):
        return cls(parent, "", entries)

    @classmethod
    def make_func(cls, parent, name, entries):
        return cls(parent, name, entries)

    @classmethod
    def __make_branch(cls, prototype, branch, body):

        pp = copy.deepcopy(prototype);
        pp.branch_name = branch;



        dispatch_if = "{0}base_t::dispatcher::has_{1}"
        returns = "std::enable_if_t<{condition}, T>"

        def map_requirement(requirement):
            requirement = cleanup(requirement)[0]
            if requirement.startswith("not"):
                requirement = requirement.replace("not", "", 1).strip()
                return dispatch_if.format("!", requirement)
            else:
                return dispatch_if.format("", requirement)

        if type(body) is dict: # specific config
            pp.body      = body.get("body", "")
            pp.requires  = body.get("requires", [])
        else:
            pp.body = body
            pp.requires = []

        condition = " && ".join([map_requirement(req) for req in pp.requires])

        pp.prefix = "template<typename T = {type}> {prefix}".format(type=pp.returns, prefix =pp.prefix)
        pp.returns   = returns.format(condition = condition)

        return cls(prototype.parent, pp.name, pp)

class Inits:
    def __init__(self, value):
        if type(value) == list:
            self.inits = [Init(i) for i in value]
        else:
            self.inits = Init(value)


    def __repr__(self):
        if type(self.inits) == list:
            return ", ".join(map(str, self.inits))
        else:
            return "base_t({})".format(self.inits)

class Init:
    def __init__(self, value):
        if type(value) == dict:
            args = Args(value.get("args"))
            body = value.get("body")

            self.value = "{}({})".format(body, args.invocation())
        else:
            self.value = value

    def __repr__(self):
        return self.value

class Body:
    def __init__(self, parent, instructions):
        self.parent         = parent

        self.instructions   = cleanup(instructions) if not self.parent.is_branched \
            else {k: cleanup(v) for (k, v) in instructions.items()}

    def get_instructions(self):
        body = self.instructions

        if len(body) == 1 and body[0].find('(') == -1:
            body[0] = "{}({})".format(body[0], self.parent.args.invocation())
        #print(self.parent.name, body)
        if not self.parent.is_constructor() and body[-1].find("return") == -1 and self.parent.returns.find("void") == -1:
            body[-1] = "return " + body[-1]

        return [b + ';' if not b.rstrip().endswith(';') else b for b in body]

    def __repr__(self):
        return "\n".join(self.get_instructions())

class Args:
    def __init__(self, args):
        if type(args) == dict:
            raw = args.get("raw")
            if raw:
                self.args = [Arg.raw(self, raw)]
            else:
                _from = args.get("from")
                _to = args.get("to")
                _type = args.get("type", Arg.default_type)

                if _from < _to:
                    ids = range(_from, _to)
                else:
                    ids = reversed(range(_to, _from))

                self.args = [Arg(self, _type, "arg" + str(a)) for a in ids]
        else:
            self.args = [Arg.unpack(self, a) for a in to_list(args)]

    def declaration(self):
        return ", ".join([a.declaration() for a in self.args])

    def invocation(self):
        return ", ".join([a.invocation() for a in self.args])

    def __repr__(self):
        return self.declaration()

class Arg:
    default_type = "composed_t"
    default_type_invocation = ".get_value()"

    def __init__(self, parent, type, name):
        self.type   = type
        self.name   = name
        self.parent = parent


    def declaration(self):
        return self.type + " " + self.name if self.type else self.name

    def invocation(self):
        if self.type == self.default_type:
            return self.name + self.default_type_invocation

        return self.name

    @classmethod
    def unpack(cls, parent, value):
        if type(value) == str:
            value = value.split()

        (t, n) = (value[0], value[1]) if len(value) > 1 \
            else (Arg.default_type, value[0])

        return cls(parent, t, n)

    @classmethod
    def raw(cls, parent, value):
        return cls(parent, "", value)

    def __repr__(self):
        return self.declaration()

def to_list(arg):
    if not arg or type(arg) is list:
        return arg
    else:
        return [arg]

def cleanup(strings) :
    return [str.strip(s) for s in to_list(strings)]


class YamlParser(yasha.YamlParser):
    def parse(self, file):
        #print(">>>Parsing template:", file.name)
        with open("codegen/config/type.test.yml", "rb") as f:
            test_functions = yasha.YamlParser().parse(f)

        variables = yasha.YamlParser.parse(self, file)
        return { "type": Type(variables, test_functions)    }