//---------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2015-2018 Sergej Zuyev (sergej.zuyev - at - zz-systems.net)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//---------------------------------------------------------------------------------


#include <iostream>

#include "util/testing/test_entry_point.hpp"

#include "system/managed_library.hpp"
#include "system/platform.hpp"

int main(int argc, char **argv) {
    std::cout << "Running main() from test_main.cpp" << std::endl;

    auto c = zacc::platform::global().match_capabilities(zacc::architectures::ZACC_ARCH::value);
    std::string str;

    if(c.size() != 0) {
        str = join(std::begin(c), std::end(c), ", ");
        ZTRACE_INTERNAL("SKIPPED: Features [" << str << "] not supported");
        return 0;
    }

    auto loader = zacc::system::managed_library(ZACC_DYLIBNAME);

    auto zacc_run_gtests = loader.resolve_symbol<int(int, char**)>("zacc_run_gtests");

    return zacc_run_gtests(argc, argv);
}
