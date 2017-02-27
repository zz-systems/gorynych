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
#include "dispatch/dispatcher.hpp"

//namespace zacc { namespace sse { namespace test {
namespace zacc { namespace test {
// =====================================================================================================================
    TEST(sse_int32_arithmetic, arithmetic_negate_default)
    {
        auto actual = -zint32(125);
        auto expected = (int) -125;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_arithmetic, arithmetic_add_default)
    {
        auto actual = zint32(12) + zint32(105);
        auto expected = (int) 117;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_arithmetic, arithmetic_sub_default)
    {
        auto actual = zint32(124) - zint32(125);
        auto expected = (int) -1;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_arithmetic, arithmetic_mul_sse4)
    {
        auto actual = zint32(12) * zint32(9);
        auto expected = (int) 108;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_arithmetic, arithmetic_mul_default)
    {
        auto actual = zint32(12) * zint32(9);
        auto expected = (int) 108;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_arithmetic, arithmetic_div_default)
    {
        auto actual = zint32(124) / zint32(124);
        auto expected = (int) 1;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_int32_bitwise, bitwise_negate_default)
    {
        auto actual = ~zint32(100);
        auto expected = (int) ~100;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_bitwise, bitwise_or_default)
    {
        auto actual = zint32(127) | zint32(64);
        auto expected = (int) (127 | 64);

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_bitwise, bitwise_and_default)
    {
        auto actual = zint32(127) & zint32(64);
        auto expected = (int) (127 & 64);

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_bitwise, bitwise_xor_default)
    {
        auto actual = zint32(127) ^ zint32(64);
        auto expected = (int) (127 ^ 64);

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_int32_bitwise_shift, bitwise_shift_slli_default)
    {
        auto actual = zint32(1) << (4);
        auto expected = (int) (1) << (4);

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_bitwise_shift, bitwise_shift_srli_default)
    {
        auto actual = zint32(109) >> (3);
        auto expected = (int) (109) >> (3);

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_int32_logical, logical_negate_default)
    {
        auto actual = (!zint32(1)).as_bool();
        auto expected = (int) false;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_logical, logical_or_default)
    {
        auto actual = zint32(0) || zint32(8);
        auto expected = (int) 8;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_logical, logical_and_default)
    {
        auto actual = zint32(0) && zint32(8);
        auto expected = (int) 0;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_int32_comparison, comparison_eq_default)
    {
        auto actual = zint32(0) == zint32(8);
        auto expected = (int) 0;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_comparison, comparison_neq_default)
    {
        auto actual = zint32(0) != zint32(0);
        auto expected = (int) 0;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_comparison, comparison_gt_default)
    {
        auto actual = zint32(0) > zint32(8);
        auto expected = (int) 0;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_comparison, comparison_lt_default)
    {
        auto actual = zint32(8) < zint32(0);
        auto expected = (int) 0;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_comparison, comparison_ge_default)
    {
        auto actual = (zint32(0) >= zint32(0)).as_bool();
        auto expected = (int) true;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_comparison, comparison_le_default)
    {
        auto actual = (zint32(0) <= zint32(0)).as_bool();
        auto expected = (int) true;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_int32_conditional, vsel_sse4)
    {
        auto actual = vsel(zint32(1) == zint32(1), zint32(2), zint32(3));
        auto expected = (int) 2;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int32_conditional, vsel_default)
    {
        auto actual = vsel(zint32(1) == zint32(1), zint32(2), zint32(3));
        auto expected = (int) 2;

        for(int value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================

}}