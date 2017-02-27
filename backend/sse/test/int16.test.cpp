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
    TEST(sse_int16_arithmetic, arithmetic_negate_default)
    {
        auto actual = -zint16(125);
        auto expected = (short) -125;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_arithmetic, arithmetic_add_default)
    {
        auto actual = zint16(12) + zint16(105);
        auto expected = (short) 117;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_arithmetic, arithmetic_sub_default)
    {
        auto actual = zint16(124) - zint16(125);
        auto expected = (short) -1;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_arithmetic, arithmetic_mul_default)
    {
        auto actual = zint16(12) * zint16(9);
        auto expected = (short) 108;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_int16_bitwise, bitwise_negate_default)
    {
        auto actual = ~zint16(100);
        auto expected = (short) ~100;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_bitwise, bitwise_or_default)
    {
        auto actual = zint16(127) | zint16(64);
        auto expected = (short) (127 | 64);

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_bitwise, bitwise_and_default)
    {
        auto actual = zint16(127) & zint16(64);
        auto expected = (short) (127 & 64);

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_bitwise, bitwise_xor_default)
    {
        auto actual = zint16(127) ^ zint16(64);
        auto expected = (short) (127 ^ 64);

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_int16_bitwise_shift, bitwise_shift_slli_default)
    {
        auto actual = zint16(1) << (4);
        auto expected = (short) (1) << (4);

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_bitwise_shift, bitwise_shift_srli_default)
    {
        auto actual = zint16(109) >> (3);
        auto expected = (short) (109) >> (3);

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_int16_logical, logical_negate_default)
    {
        auto actual = (!zint16(1)).as_bool();
        auto expected = (short) false;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_logical, logical_or_default)
    {
        auto actual = zint16(0) || zint16(8);
        auto expected = (short) 8;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_logical, logical_and_default)
    {
        auto actual = zint16(0) && zint16(8);
        auto expected = (short) 0;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_int16_comparison, comparison_eq_default)
    {
        auto actual = zint16(0) == zint16(8);
        auto expected = (short) 0;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_comparison, comparison_neq_default)
    {
        auto actual = zint16(0) != zint16(0);
        auto expected = (short) 0;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_comparison, comparison_gt_default)
    {
        auto actual = zint16(0) > zint16(8);
        auto expected = (short) 0;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_comparison, comparison_lt_default)
    {
        auto actual = zint16(8) < zint16(0);
        auto expected = (short) 0;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_comparison, comparison_ge_default)
    {
        auto actual = (zint16(0) >= zint16(0)).as_bool();
        auto expected = (short) true;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

    TEST(sse_int16_comparison, comparison_le_default)
    {
        auto actual = (zint16(0) <= zint16(0)).as_bool();
        auto expected = (short) true;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================
// =====================================================================================================================
    TEST(sse_int16_conditional, vsel_default)
    {
        auto actual = vsel(zint16(1) == zint16(1), zint16(2), zint16(3));
        auto expected = (short) 2;

        for(short value : actual)
        {
            ASSERT_EQ(value, expected);
        }
    }

// =====================================================================================================================

}}