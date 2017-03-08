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

//namespace zacc { namespace avx { namespace test {
namespace zacc { namespace test {

// =====================================================================================================================
    TEST(avx_float64_arithmetic, arithmetic_negate_default)
    {
        auto actual = -zfloat64(125);
        auto expected = (double) -125;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

    TEST(avx_float64_arithmetic, arithmetic_add_default)
    {
        auto actual = zfloat64(12) + zfloat64(105);
        auto expected = (double) 117;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

    TEST(avx_float64_arithmetic, arithmetic_sub_default)
    {
        auto actual = zfloat64(124) - zfloat64(125);
        auto expected = (double) -1;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

    TEST(avx_float64_arithmetic, arithmetic_mul_default)
    {
        auto actual = zfloat64(12) * zfloat64(9);
        auto expected = (double) 108;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

    TEST(avx_float64_arithmetic, arithmetic_div_default)
    {
        auto actual = zfloat64(124) / zfloat64(124);
        auto expected = (double) 1;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
    TEST(avx_float64_logical, logical_negate_default)
    {
        auto actual = (!zfloat64(1)).as_bool();
        auto expected = (double) false;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

    TEST(avx_float64_logical, logical_or_default)
    {
        auto actual = zfloat64(0) || zfloat64(8);
        auto expected = (double) 8;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

    TEST(avx_float64_logical, logical_and_default)
    {
        auto actual = zfloat64(0) && zfloat64(8);
        auto expected = (double) 0;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(avx_float64_comparison, comparison_eq_default)
    {
        auto actual = zfloat64(0) == zfloat64(8);
        auto expected = (double) 0;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

    TEST(avx_float64_comparison, comparison_neq_default)
    {
        auto actual = zfloat64(0) != zfloat64(0);
        auto expected = (double) 0;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

    TEST(avx_float64_comparison, comparison_gt_default)
    {
        auto actual = zfloat64(0) > zfloat64(8);
        auto expected = (double) 0;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

    TEST(avx_float64_comparison, comparison_lt_default)
    {
        auto actual = zfloat64(8) < zfloat64(0);
        auto expected = (double) 0;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

    TEST(avx_float64_comparison, comparison_ge_default)
    {
        auto actual = (zfloat64(0) >= zfloat64(0)).as_bool();
        auto expected = (double) true;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

    TEST(avx_float64_comparison, comparison_le_default)
    {
        auto actual = (zfloat64(0) <= zfloat64(0)).as_bool();
        auto expected = (double) true;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(avx_float64_conditional, vsel_default)
    {
        auto actual = vsel(zfloat64(1) == zfloat64(1), zfloat64(2), zfloat64(3));
        auto expected = (double) 2;

        for(double value : actual)
        {
            ASSERT_DOUBLE_EQ(value, expected);
        }
    }

// =====================================================================================================================

}}