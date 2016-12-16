//
// Created by Sergej Zuyev on 12/16/2016.
//

#pragma once

#include "arithmetic.hpp"
#include "bitwise.hpp"
#include "conditional.hpp"
#include "common.hpp"
#include "logical.hpp"
#include "../common/printable.hpp"

namespace zacc {
    namespace sse {


        struct __zfloat32 : public zval<__m128, float, 4, 16> {
            __zfloat32(__m128 value)
                    : zval(value) {}

            __zfloat32(__m128d value)
                    : zval(_mm_cvtpd_ps(value)) {}

            __zfloat32(__m128i value)
                    : zval(_mm_cvtepi32_ps(value)) {}

            __zfloat32(float value)
                    : zval(_mm_set1_ps(value)) {}

            __zfloat32(float *value)
                    : zval(_mm_load_ps(value)) {}

            __zfloat32(float a, float b, float c, float d)
                    : zval(_mm_set_ps(d, c, b, a)) {}
        };


        struct zfloat32;

        namespace f32 {
            using arithmetic    = float32_policies::arithmetic<zfloat32>;
            using commonf32     = float32_policies::common<zfloat32>;
            using common        = common_policies::common<zfloat32>;
            using conditional   = float32_policies::conditional<zfloat32>;
            using bitwise       = float32_policies::bitwise<zfloat32>;
            using logical       = float32_policies::logical<zfloat32>;
        }

        struct zfloat32 : public compose<
                f32::arithmetic::negate_policy,
                f32::arithmetic::add_policy,
                f32::arithmetic::sub_policy,
                f32::arithmetic::mul_policy,
                f32::arithmetic::div_policy,

                f32::common::print_policy,
                f32::commonf32::extract_policy,

                f32::conditional::if_policy,

                f32::logical::negate_policy,
                f32::logical::or_policy,
                f32::logical::and_policy,

                f32::logical::compare_eq_policy,
                f32::logical::compare_neq_policy,
                f32::logical::compare_gt_policy,
                f32::logical::compare_lt_policy,
                f32::logical::compare_ge_policy,
                f32::logical::compare_le_policy,

                f32::bitwise::negate_policy,
                f32::bitwise::or_policy,
                f32::bitwise::and_policy,
                f32::bitwise::xor_policy,

                converting_arithmetic<zfloat32>::template inject,
                composable<__zfloat32>::template type> {
            FORWARD2(zfloat32, compose);
        };
    }
}