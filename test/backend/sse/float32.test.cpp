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
#include "system/dispatcher.hpp"

//namespace zacc { namespace sse { namespace test {
namespace zacc { namespace test {

// =====================================================================================================================
    TEST(sse_float32_arithmetic, vneg_default)
    {
        auto actual = -zfloat32(125);
        auto expected = (float) -125;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_arithmetic, vadd_default)
    {
        auto actual = zfloat32(12) + zfloat32(105);
        auto expected = (float) 117;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_arithmetic, vsub_default)
    {
        auto actual = zfloat32(124) - zfloat32(125);
        auto expected = (float) -1;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_arithmetic, vmul_default)
    {
        zfloat32 actual = zfloat32(12) * zfloat32(9);
        auto expected = (float) 108;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_arithmetic, vdiv_default)
    {
        auto actual = zfloat32(124) / zfloat32(124);
        auto expected = (float) 1;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_float32_logical, vlneg_default)
    {
        auto actual = (!zfloat32(1)).as_bool();
        auto expected = (float) false;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_logical, vlor_default)
    {
        auto actual = zfloat32(0) || zfloat32(8);
        auto expected = (float) 8;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_logical, vland_default)
    {
        auto actual = zfloat32(0) && zfloat32(8);
        auto expected = (float) 0;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_float32_comparison, veq_default)
    {
        auto actual = zfloat32(0) == zfloat32(8);
        auto expected = (float) 0;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_comparison, vneq_default)
    {
        auto actual = zfloat32(0) != zfloat32(0);
        auto expected = (float) 0;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_comparison, vgt_default)
    {
        auto actual = zfloat32(0) > zfloat32(8);
        auto expected = (float) 0;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_comparison, vlt_default)
    {
        auto actual = zfloat32(8) < zfloat32(0);
        auto expected = (float) 0;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_comparison, vge_default)
    {
        auto actual = (zfloat32(0) >= zfloat32(0)).as_bool();
        auto expected = (float) true;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_comparison, vle_default)
    {
        auto actual = (zfloat32(0) <= zfloat32(0)).as_bool();
        auto expected = (float) true;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_float32_conditional, vsel_sse4)
    {
        auto actual = vsel(zfloat32(1) == zfloat32(1), zfloat32(2), zfloat32(3));
        auto expected = (float) 2;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

    TEST(sse_float32_conditional, vsel_default)
    {
        auto actual = vsel(zfloat32(1) == zfloat32(1), zfloat32(2), zfloat32(3));
        auto expected = (float) 2;

        for(float value : actual)
        {
            ASSERT_FLOAT_EQ(value, expected);
        }
    }

// =====================================================================================================================

}}