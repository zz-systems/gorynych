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
#include "util/gtest_ext.hpp"
#include "system/dispatcher.hpp"
#include <random>

namespace zacc { namespace test {

// =====================================================================================================================
    TEST(sse_float32_arithmetic, vneg_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (-a[i]);
        }

        VASSERT_EQ((-zfloat32(a)), zfloat32(expected));
    }

    TEST(sse_float32_arithmetic, vadd_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (a[i] + b[i]);
        }

        VASSERT_EQ((zfloat32(a) + zfloat32(b)), zfloat32(expected));
    }

    TEST(sse_float32_arithmetic, vsub_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (a[i] - b[i]);
        }

        VASSERT_EQ((zfloat32(a) - zfloat32(b)), zfloat32(expected));
    }

    TEST(sse_float32_arithmetic, vmul_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (a[i] * b[i]);
        }

        VASSERT_EQ((zfloat32(a) * zfloat32(b)), zfloat32(expected));
    }

    TEST(sse_float32_arithmetic, vdiv_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (1);
        }

        VASSERT_EQ((zfloat32(a) / zfloat32(a)), zfloat32(expected));
    }

// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_float32_logical, vlneg_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (false);
        }

        VASSERT_EQ(((!zfloat32(a)).as_bool()), zfloat32(expected));
    }

    TEST(sse_float32_logical, vlor_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (true);
        }

        VASSERT_EQ(((zfloat32(0) || zfloat32(a)).as_bool()), zfloat32(expected));
    }

    TEST(sse_float32_logical, vland_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (false);
        }

        VASSERT_EQ(((zfloat32(0) && zfloat32(a)).as_bool()), zfloat32(expected));
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_float32_comparison, veq_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (0);
        }

        VASSERT_EQ((zfloat32(0) == zfloat32(a)), zfloat32(expected));
    }

    TEST(sse_float32_comparison, vneq_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (0);
        }

        VASSERT_EQ((zfloat32(a) != zfloat32(a)), zfloat32(expected));
    }

    TEST(sse_float32_comparison, vgt_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (0);
        }

        VASSERT_EQ((zfloat32(0) > zfloat32(a)), zfloat32(expected));
    }

    TEST(sse_float32_comparison, vlt_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (0);
        }

        VASSERT_EQ((zfloat32(a) < zfloat32(0)), zfloat32(expected));
    }

    TEST(sse_float32_comparison, vge_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (true);
        }

        VASSERT_EQ(((zfloat32(b) >= zfloat32(b)).as_bool()), zfloat32(expected));
    }

    TEST(sse_float32_comparison, vle_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (true);
        }

        VASSERT_EQ(((zfloat32(b) <= zfloat32(b)).as_bool()), zfloat32(expected));
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_float32_conditional, vsel_sse4)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (2);
        }

        VASSERT_EQ((vsel(zfloat32(1) == zfloat32(1), zfloat32(2), zfloat32(3))), zfloat32(expected));
    }

    TEST(sse_float32_conditional, vsel_default)
    {
        REQUIRES(ZACC_CAPABILITIES);

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution1(1, 3);
        std::uniform_int_distribution<int> distribution2(3, 60);

        std::array<float, 4> a, b, expected;
        for(int i = 0; i < 4; i++)
        {
            a[i] = distribution2(generator);
            b[i] = distribution1(generator);

            expected[i] = (float) (2);
        }

        VASSERT_EQ((vsel(zfloat32(1) == zfloat32(1), zfloat32(2), zfloat32(3))), zfloat32(expected));
    }

// =====================================================================================================================

}}