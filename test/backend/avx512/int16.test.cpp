//---------------------------------------------------------------------------------
//
//  This is an autogenerated file. Do not edit!
//
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

#include "gtest/gtest.h"
#include "util/testing/gtest_ext.hpp"
#include "system/branch.hpp"
#include <random>

namespace zacc { namespace test {

// =====================================================================================================================
    TEST(avx512_int16_arithmetic, vneg_default)
    {
        REQUIRES(ZACC_ARCH);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        alignas(64) std::array<int16_t, 32> a, b, expected;
        for(int i = 0; i < 32; i++)
        {
            a[i] = static_cast<int16_t>(distribution2(generator));
            b[i] = static_cast<int16_t>(distribution1(generator));

            expected[i] = (int16_t) (-a[i]);
        }

        VASSERT_EQ((-zint16(a)), zint16(expected));
    }

    TEST(avx512_int16_arithmetic, vadd_default)
    {
        REQUIRES(ZACC_ARCH);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        alignas(64) std::array<int16_t, 32> a, b, expected;
        for(int i = 0; i < 32; i++)
        {
            a[i] = static_cast<int16_t>(distribution2(generator));
            b[i] = static_cast<int16_t>(distribution1(generator));

            expected[i] = (int16_t) (a[i] + b[i]);
        }

        VASSERT_EQ((zint16(a) + zint16(b)), zint16(expected));
    }

    TEST(avx512_int16_arithmetic, vsub_default)
    {
        REQUIRES(ZACC_ARCH);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        alignas(64) std::array<int16_t, 32> a, b, expected;
        for(int i = 0; i < 32; i++)
        {
            a[i] = static_cast<int16_t>(distribution2(generator));
            b[i] = static_cast<int16_t>(distribution1(generator));

            expected[i] = (int16_t) (a[i] - b[i]);
        }

        VASSERT_EQ((zint16(a) - zint16(b)), zint16(expected));
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(avx512_int16_comparison, veq_default)
    {
        REQUIRES(ZACC_ARCH);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        alignas(64) std::array<int16_t, 32> a, b, expected;
        for(int i = 0; i < 32; i++)
        {
            a[i] = static_cast<int16_t>(distribution2(generator));
            b[i] = static_cast<int16_t>(distribution1(generator));

            expected[i] = (int16_t) (0);
        }

        VASSERT_EQ((zint16(0) == zint16(a)), zint16(expected));
    }

    TEST(avx512_int16_comparison, vneq_default)
    {
        REQUIRES(ZACC_ARCH);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        alignas(64) std::array<int16_t, 32> a, b, expected;
        for(int i = 0; i < 32; i++)
        {
            a[i] = static_cast<int16_t>(distribution2(generator));
            b[i] = static_cast<int16_t>(distribution1(generator));

            expected[i] = (int16_t) (0);
        }

        VASSERT_EQ((zint16(a) != zint16(a)), zint16(expected));
    }

    TEST(avx512_int16_comparison, vgt_default)
    {
        REQUIRES(ZACC_ARCH);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        alignas(64) std::array<int16_t, 32> a, b, expected;
        for(int i = 0; i < 32; i++)
        {
            a[i] = static_cast<int16_t>(distribution2(generator));
            b[i] = static_cast<int16_t>(distribution1(generator));

            expected[i] = (int16_t) (0);
        }

        VASSERT_EQ((zint16(0) > zint16(a)), zint16(expected));
    }

    TEST(avx512_int16_comparison, vlt_default)
    {
        REQUIRES(ZACC_ARCH);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        alignas(64) std::array<int16_t, 32> a, b, expected;
        for(int i = 0; i < 32; i++)
        {
            a[i] = static_cast<int16_t>(distribution2(generator));
            b[i] = static_cast<int16_t>(distribution1(generator));

            expected[i] = (int16_t) (0);
        }

        VASSERT_EQ((zint16(a) < zint16(0)), zint16(expected));
    }

    TEST(avx512_int16_comparison, vge_default)
    {
        REQUIRES(ZACC_ARCH);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        alignas(64) std::array<int16_t, 32> a, b, expected;
        for(int i = 0; i < 32; i++)
        {
            a[i] = static_cast<int16_t>(distribution2(generator));
            b[i] = static_cast<int16_t>(distribution1(generator));

            expected[i] = (int16_t) (true);
        }

        VASSERT_EQ(((zint16(b) >= zint16(b)).as_bool()), zint16(expected));
    }

    TEST(avx512_int16_comparison, vle_default)
    {
        REQUIRES(ZACC_ARCH);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        alignas(64) std::array<int16_t, 32> a, b, expected;
        for(int i = 0; i < 32; i++)
        {
            a[i] = static_cast<int16_t>(distribution2(generator));
            b[i] = static_cast<int16_t>(distribution1(generator));

            expected[i] = (int16_t) (true);
        }

        VASSERT_EQ(((zint16(b) <= zint16(b)).as_bool()), zint16(expected));
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(avx512_int16_conditional, vsel_default)
    {
        REQUIRES(ZACC_ARCH);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        alignas(64) std::array<int16_t, 32> a, b, expected;
        for(int i = 0; i < 32; i++)
        {
            a[i] = static_cast<int16_t>(distribution2(generator));
            b[i] = static_cast<int16_t>(distribution1(generator));

            expected[i] = (int16_t) (2);
        }

        VASSERT_EQ((zint16(2).when(zint16(1) == zint16(1)).otherwise(zint16(3))), zint16(expected));
    }

// =====================================================================================================================

}}