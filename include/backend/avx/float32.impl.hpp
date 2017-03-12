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

#pragma once

#include <x86intrin.h>
#include <type_traits>

#include "util/type_composition.hpp"

#include "zval.hpp"
#include "common.hpp"
#include "type_traits.hpp"

#include "traits/common.hpp"
#include "traits/construction.hpp"
#include "traits/numeric.hpp"
#include "traits/io.hpp"
#include "traits/arithmetic.hpp"
#include "traits/bitwise.hpp"
#include "traits/logical.hpp"
#include "traits/comparison.hpp"
#include "traits/conditional.hpp"

/**
 * @brief float32 implementation for the avx branch
 * provides unified access to 8 'float' values
 */

namespace zacc { namespace avx {

    // =================================================================================================================
    /**
     * @name construction operations
     */
    ///@{

    /**
     * @brief construction
     * @relates float32
     * @remark avx
     */
    template<typename composed_t>
    struct float32_construction
    {

        /**
         * @brief construction basic interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(__m256 value) : base_t(value) {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "CONS(__m256 value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(__m256d value) : base_t(_mm256_castps128_ps256(_mm256_cvtpd_ps(value))) {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "CONS(__m256d value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(__m256i value) : base_t(_mm256_cvtepi32_ps(value)) {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "CONS(__m256i value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(float value) : base_t(_mm256_set1_ps(value)) {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "CONS(float value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(float *value) : base_t(_mm256_load_ps(value)) {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "CONS(float *value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(float arg7, float arg6, float arg5, float arg4, float arg3, float arg2, float arg1, float arg0) : base_t(_mm256_set_ps(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7)) {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "CONS(float arg7, float arg6, float ar..)");

            }

        };

        /**
         * @brief construction public interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        using impl = interface::construction<__impl<base_t>, composed_t>;
    };

    ///@}


    // =================================================================================================================
    /**
     * @name numeric operations
     */
    ///@{

    /**
     * @brief numeric
     * @relates float32
     * @remark avx
     */
    template<typename composed_t>
    struct float32_numeric
    {

        /**
         * @brief numeric basic interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);

        };

        /**
         * @brief numeric public interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        using impl = interface::numeric<__impl<base_t>, composed_t>;
    };

    ///@}


    // =================================================================================================================
    /**
     * @name io operations
     */
    ///@{

    /**
     * @brief io
     * @relates float32
     * @remark avx
     */
    template<typename composed_t>
    struct float32_io
    {

        /**
         * @brief io basic interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief io default branch
             * @relates float32
             * @remark avx - default
             */
            void vstore(typename base_t::extracted_t &target, composed_t source) const noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vstore");

                _mm256_store_ps(target.data(), source);
            }


            /**
             * @brief io default branch
             * @relates float32
             * @remark avx - default
             */
            void vstream(typename base_t::extracted_t &target, composed_t source) const noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vstream");

                _mm256_stream_ps(target.data(), source);
            }

        };

        /**
         * @brief io public interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        using impl = interface::io<__impl<base_t>, composed_t>;
    };

    ///@}


    // =================================================================================================================
    /**
     * @name arithmetic operations
     */
    ///@{

    /**
     * @brief arithmetic
     * @relates float32
     * @remark avx
     */
    template<typename composed_t>
    struct float32_arithmetic
    {

        /**
         * @brief arithmetic basic interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vneg(composed_t one)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vneg");

                return _mm256_sub_ps(_mm256_setzero_ps(), one);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vadd(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vadd");

                return _mm256_add_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vsub(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vsub");

                return _mm256_sub_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vmul(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vmul");

                return _mm256_mul_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vdiv(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vdiv");

                return _mm256_div_ps(one, other);
            }

        };

        /**
         * @brief arithmetic public interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        using impl = interface::arithmetic<__impl<base_t>, composed_t>;
    };

    ///@}


    // =================================================================================================================
    /**
     * @name bitwise operations
     */
    ///@{

    /**
     * @brief bitwise
     * @relates float32
     * @remark avx
     */
    template<typename composed_t>
    struct float32_bitwise
    {

        /**
         * @brief bitwise basic interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vneg(composed_t one)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vneg");

                __m256 junk;
                auto ones = _mm256_cmp_ps(junk, junk, _CMP_EQ_OQ);
                return _mm256_xor_ps(one, ones);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vand(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vand");

                return _mm256_or_ps(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t or(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "or");

                return _mm256_and_ps(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t xor(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "xor");

                return _mm256_xor_ps(one, other);
            }

        };

        /**
         * @brief bitwise public interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        using impl = interface::bitwise<__impl<base_t>, composed_t>;
    };

    ///@}


    // =================================================================================================================
    /**
     * @name logical operations
     */
    ///@{

    /**
     * @brief logical
     * @relates float32
     * @remark avx
     */
    template<typename composed_t>
    struct float32_logical
    {

        /**
         * @brief logical basic interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief logical default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vneg(composed_t one)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vneg");

                return _mm256_cmp_ps(one, _mm256_setzero_ps(), _CMP_EQ_OQ);
            }


            /**
             * @brief logical default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t or(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "or");

                return _mm256_or_ps(one, other);
            }


            /**
             * @brief logical default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vand(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vand");

                return _mm256_and_ps(one, other);
            }

        };

        /**
         * @brief logical public interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        using impl = interface::logical<__impl<base_t>, composed_t>;
    };

    ///@}


    // =================================================================================================================
    /**
     * @name comparison operations
     */
    ///@{

    /**
     * @brief comparison
     * @relates float32
     * @remark avx
     */
    template<typename composed_t>
    struct float32_comparison
    {

        /**
         * @brief comparison basic interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t veq(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "veq");

                return _mm256_cmp_ps(one, other, _CMP_EQ_OQ);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vneq(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vneq");

                return _mm256_cmp_ps(one, other, _CMP_NEQ_OQ);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vgt(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vgt");

                return _mm256_cmp_ps(one, other, _CMP_GT_OQ);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vlt(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vlt");

                return _mm256_cmp_ps(one, other, _CMP_LT_OQ);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vge(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vge");

                return _mm256_cmp_ps(one, other, _CMP_GE_OQ);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vle(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vle");

                return _mm256_cmp_ps(one, other, _CMP_LE_OQ);
            }

        };

        /**
         * @brief comparison public interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        using impl = interface::comparison<__impl<base_t>, composed_t>;
    };

    ///@}


    // =================================================================================================================
    /**
     * @name conditional operations
     */
    ///@{

    /**
     * @brief conditional
     * @relates float32
     * @remark avx
     */
    template<typename composed_t>
    struct float32_conditional
    {

        /**
         * @brief conditional basic interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief conditional default branch
             * @relates float32
             * @remark avx - default
             */
            friend composed_t vsel(composed_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE(std::left << std::setw(32) << "avx.float32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zfloat32(float[8]) " << std::left << std::setw(10) << "default" << "vsel");

                auto mask = _mm256_cmp_ps(_mm256_setzero_ps(), condition, _CMP_EQ_OQ);
                return _mm256_blendv_ps(if_value, else_value, mask);
            }

        };

        /**
         * @brief conditional public interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        using impl = interface::conditional<__impl<base_t>, composed_t>;
    };

    ///@}


    // Type composition ================================================================================================

    /**
     * @name float32 composition
     */
    ///@{

    /**
     * @brief zval parametrization using
     * - '__m256' as underlying vector type
     * - 'float' as scalar type
     * - '8' as vector size
     * - '32' as alignment
     * @relates float32
     * @remark avx
     */
    template<uint64_t capability>
    struct __zval_float32
    {
        using zval_t = zval<__m256, float, 8, 32, capability>;

        struct impl : public zval_t
        {
            FORWARD2(impl, zval_t);
        };
    };
    /**
     * @brief zval composition
     * @relates float32
     * @remark avx
     */
    template<uint64_t capability>
    struct __zfloat32
    {
        struct impl;

        using zval_t = typename __zval_float32<capability>::impl;
        using composition_t = compose
        <
            printable::impl,
            iteratable::impl,
            convertable::impl,
            float32_io<impl>::template impl,
            float32_numeric<impl>::template impl,
            float32_arithmetic<impl>::template impl,
            float32_bitwise<impl>::template impl,
            float32_logical<impl>::template impl,
            float32_comparison<impl>::template impl,
            float32_conditional<impl>::template impl,
            float32_construction<impl>::template impl,

            composable<zval_t>::template type
        >;

        struct impl : public composition_t
        {
            FORWARD2(impl, composition_t);
        };
    };

    template<uint64_t capability = 0xFFFF'FFFF'FFFF'FFFF>
    using zfloat32 = typename __zfloat32<capability>::impl;

    ///@}
}}