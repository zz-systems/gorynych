//---------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2016 Sergej Zuyev (sergej.zuyev - at - zz-systems.net)
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


#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif


const void* zacc_dlopen(const char* path)
{
#ifdef WIN32
    return LoadLibrary(path);
#else
    return dlopen(path, RTLD_LAZY);
#endif
}

const char* zacc_dlerror()
{
#ifdef WIN32
    return "";
#else
    return dlerror();
#endif
}

const void* zacc_dlsym(const void* handle, const char* symbol)
{
#ifdef WIN32
    return GetProcAddress(handle, symbol);
#else
    return dlsym(handle, symbol);
#endif
}

bool zacc_dlclose(const void* handle)
{
#ifdef WIN32
    return FreeLibrary(handle);
#else
    return dlclose(handle) == 0;
#endif
}