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
#include "traits/io.hpp"
#include "traits/arithmetic.hpp"
#include "traits/bitwise.hpp"
#include "traits/bitwise_shift.hpp"
#include "traits/logical.hpp"
#include "traits/comparison.hpp"
#include "traits/conditional.hpp"

/**
 * @brief int32 implementation for the sse branch
 * provides unified access to 4 'int' values
 */

namespace zacc { namespace sse {

    // =================================================================================================================
    /**
     * @name construction operations
     */
    ///@{

    /**
     * @brief construction
     * @relates int32
     * @remark sse
     */
    template<typename composed_t>
    struct int32_construction
    {

        /**
         * @brief construction basic interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {


            /**
             * @brief construction default branch
             * @relates int32
             * @remark sse - default
             */
            __impl(__m128 value) : base_t(_mm_cvtps_epi32(value)) {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "CONS(__m128 value)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark sse - default
             */
            __impl(__m128d value) : base_t(_mm_cvtpd_epi32(value)) {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "CONS(__m128d value)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark sse - default
             */
            __impl(__m128i value) : base_t(value) {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "CONS(__m128i value)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark sse - default
             */
            __impl(int value) : base_t(_mm_set1_epi32(value)) {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "CONS(int value)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark sse - default
             */
            __impl(int *value) : base_t(_mm_load_si128((__m128i*)value)) {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "CONS(int *value)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark sse - default
             */
            __impl(int arg3, int arg2, int arg1, int arg0) : base_t(_mm_set_ps(arg0, arg1, arg2, arg3)) {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "CONS(int arg3, int arg2, int arg1, in..)");

            }

        };

        /**
         * @brief construction public interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        using impl = interface::construction<__impl<base_t>, composed_t>;
    };

    ///@}


    // =================================================================================================================
    /**
     * @name io operations
     */
    ///@{

    /**
     * @brief io
     * @relates int32
     * @remark sse
     */
    template<typename composed_t>
    struct int32_io
    {

        /**
         * @brief io basic interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief io default branch
             * @relates int32
             * @remark sse - default
             */
            friend void vstore(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vstore");

                _mm_store_si128((__m128i*)target.data(), source);
            }


            /**
             * @brief io default branch
             * @relates int32
             * @remark sse - default
             */
            friend void vstream(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vstream");

                _mm_stream_si128((__m128i*)target.data(), source);
            }

        };

        /**
         * @brief io public interface implementation
         * @relates int32
         * @remark sse
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
     * @relates int32
     * @remark sse
     */
    template<typename composed_t>
    struct int32_arithmetic
    {

        /**
         * @brief arithmetic basic interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vneg(composed_t one)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vneg");

                return _mm_sub_epi32(_mm_setzero_si128(), one);
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vadd(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vadd");

                return _mm_add_epi32(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vsub(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vsub");

                return _mm_sub_epi32(one, other);
            }


            /**
             * @brief arithmetic sse4 branch
             * @relates int32
             * @remark sse - sse4
             */
            template<typename T = composed_t> friend std::enable_if_t<base_t::dispatcher::has_SSE4, T> vmul(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "sse4" << "vmul");

                return _mm_mullo_epi32(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark sse - default
             */
            template<typename T = composed_t> friend std::enable_if_t<!base_t::dispatcher::has_SSE4, T> vmul(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vmul");

                /* vmul 2,0*/;
                auto tmp1 = _mm_castsi128_ps(_mm_mul_epu32(one, other));
                /* vmul 3,1 */;
                auto tmp2 = _mm_castsi128_ps(_mm_mul_epu32(_mm_srli_si128(one, 4), _mm_srli_si128(other, 4)));
                return _mm_castps_si128(_mm_shuffle_ps(tmp1, tmp2, _MM_SHUFFLE(2, 0, 2, 0)));
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vdiv(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vdiv");

                return _mm_div_ps(_mm_cvtepi32_ps(one), _mm_cvtepi32_ps(other));
            }

        };

        /**
         * @brief arithmetic public interface implementation
         * @relates int32
         * @remark sse
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
     * @relates int32
     * @remark sse
     */
    template<typename composed_t>
    struct int32_bitwise
    {

        /**
         * @brief bitwise basic interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vbneg(composed_t one)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vbneg");

                __m128i junk;
                auto ones = _mm_cmpeq_epi32(junk, junk);
                return _mm_xor_si128(one, ones);
            }


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vbor(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vbor");

                return _mm_or_si128(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vband(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vband");

                return _mm_and_si128(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vbxor(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vbxor");

                return _mm_xor_si128(one, other);
            }

        };

        /**
         * @brief bitwise public interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        using impl = interface::bitwise<__impl<base_t>, composed_t>;
    };

    ///@}


    // =================================================================================================================
    /**
     * @name bitwise_shift operations
     */
    ///@{

    /**
     * @brief bitwise_shift
     * @relates int32
     * @remark sse
     */
    template<typename composed_t>
    struct int32_bitwise_shift
    {

        /**
         * @brief bitwise_shift basic interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief bitwise_shift default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vbsll(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vbsll");

                return _mm_sll_epi32(one, other);
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vbsrl(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vbsrl");

                return _mm_srl_epi32(one, other);
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vbslli(const composed_t one, const size_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vbslli");

                return _mm_slli_epi32(one, other);
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vbsrli(const composed_t one, const size_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vbsrli");

                return _mm_srli_epi32(one, other);
            }

        };

        /**
         * @brief bitwise_shift public interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        using impl = interface::bitwise_shift<__impl<base_t>, composed_t>;
    };

    ///@}


    // =================================================================================================================
    /**
     * @name logical operations
     */
    ///@{

    /**
     * @brief logical
     * @relates int32
     * @remark sse
     */
    template<typename composed_t>
    struct int32_logical
    {

        /**
         * @brief logical basic interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief logical default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vlneg(composed_t one)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vlneg");

                return _mm_cmpeq_epi32(one, _mm_setzero_si128());
            }


            /**
             * @brief logical default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vlor(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vlor");

                return _mm_or_si128(one, other);
            }


            /**
             * @brief logical default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vland(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vland");

                return _mm_and_si128(one, other);
            }

        };

        /**
         * @brief logical public interface implementation
         * @relates int32
         * @remark sse
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
     * @relates int32
     * @remark sse
     */
    template<typename composed_t>
    struct int32_comparison
    {

        /**
         * @brief comparison basic interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t veq(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "veq");

                return _mm_cmpeq_epi32(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vneq(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vneq");

                return !(one == other);
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vgt(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vgt");

                return _mm_cmpgt_epi32(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vlt(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vlt");

                return _mm_cmplt_epi32(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vge(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vge");

                return !(one < other);
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark sse - default
             */
            friend composed_t vle(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vle");

                return !(one > other);
            }

        };

        /**
         * @brief comparison public interface implementation
         * @relates int32
         * @remark sse
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
     * @relates int32
     * @remark sse
     */
    template<typename composed_t>
    struct int32_conditional
    {

        /**
         * @brief conditional basic interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief conditional sse4 branch
             * @relates int32
             * @remark sse - sse4
             */
            template<typename T = composed_t> friend std::enable_if_t<base_t::dispatcher::has_SSE4, T> vsel(composed_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "sse4" << "vsel");

                auto mask = _mm_cmpeq_epi32(_mm_setzero_si128(), condition);
                return _mm_blendv_epi8(if_value, else_value, mask);
            }


            /**
             * @brief conditional default branch
             * @relates int32
             * @remark sse - default
             */
            template<typename T = composed_t> friend std::enable_if_t<!base_t::dispatcher::has_SSE4, T> vsel(composed_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int32.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint32(int[4]) " << std::left << std::setw(10) << "default" << "vsel");

                return _mm_or_si128(_mm_andnot_si128(condition, else_value), _mm_and_si128(condition, if_value));
            }

        };

        /**
         * @brief conditional public interface implementation
         * @relates int32
         * @remark sse
         */
        template<typename base_t>
        using impl = interface::conditional<__impl<base_t>, composed_t>;
    };

    ///@}


    // Type composition ================================================================================================

    /**
     * @name int32 composition
     */
    ///@{

    /**
     * @brief zval parametrization using
     * - '__m128i' as underlying vector type
     * - 'int' as scalar type
     * - '4' as vector size
     * - '16' as alignment
     * @relates int32
     * @remark sse
     */
    template<uint64_t capability>
    struct __zval_int32
    {
        using zval_t = zval<__m128i, int, 4, 16, capability>;

        struct impl : public zval_t
        {
            FORWARD2(impl, zval_t);
        };
    };
    /**
     * @brief zval composition
     * @relates int32
     * @remark sse
     */
    template<uint64_t capability>
    struct __zint32
    {
        struct impl;

        using zval_t = typename __zval_int32<capability>::impl;
        using composition_t = compose
        <
            printable::impl,
            iteratable::impl,
            convertable::impl,
            int32_io<impl>::template impl,
            int32_arithmetic<impl>::template impl,
            int32_bitwise<impl>::template impl,
            int32_bitwise_shift<impl>::template impl,
            int32_logical<impl>::template impl,
            int32_comparison<impl>::template impl,
            int32_conditional<impl>::template impl,
            int32_construction<impl>::template impl,

            composable<zval_t>::template type
        >;

        struct impl : public composition_t
        {
            FORWARD2(impl, composition_t);
        };
    };

    template<uint64_t capability = 0xFFFF'FFFF'FFFF'FFFF>
    using zint32 = typename __zint32<capability>::impl;

    ///@}
}}