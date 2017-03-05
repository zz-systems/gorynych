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
 * @brief int16 implementation for the sse branch
 * provides unified access to 8 'short' values
 */

namespace zacc { namespace sse {

    // =================================================================================================================
    /**
     * @name construction operations
     */
    ///@{

    /**
     * @brief construction
     * @relates int16
     * @remark sse
     */
    template<typename composed_t>
    struct int16_construction
    {

        /**
         * @brief construction basic interface implementation
         * @relates int16
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {


            /**
             * @brief construction default branch
             * @relates int16
             * @remark sse - default
             */
            __impl(__m128i value) : base_t(value) {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "CONS(__m128i value)");

            }


            /**
             * @brief construction default branch
             * @relates int16
             * @remark sse - default
             */
            __impl(short value) : base_t(_mm_set1_epi16(value)) {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "CONS(short value)");

            }


            /**
             * @brief construction default branch
             * @relates int16
             * @remark sse - default
             */
            __impl(short* value) : base_t(_mm_load_si128((__m128i *) value)) {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "CONS(short* value)");

            }


            /**
             * @brief construction default branch
             * @relates int16
             * @remark sse - default
             */
            __impl(short arg7, short arg6, short arg5, short arg4, short arg3, short arg2, short arg1, short arg0) : base_t(_mm_set_epi16(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7)) {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "CONS(short arg7, short arg6, short ar..)");

            }

        };

        /**
         * @brief construction public interface implementation
         * @relates int16
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
     * @relates int16
     * @remark sse
     */
    template<typename composed_t>
    struct int16_io
    {

        /**
         * @brief io basic interface implementation
         * @relates int16
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief io default branch
             * @relates int16
             * @remark sse - default
             */
            void io_store(typename base_t::extracted_t &target) const noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "store");

                _mm_store_si128((__m128i*)target.data(), base_t::_value);
            }


            /**
             * @brief io default branch
             * @relates int16
             * @remark sse - default
             */
            void io_stream(typename base_t::extracted_t &target) const noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "stream");

                _mm_stream_si128((__m128i*)target.data(), base_t::_value);
            }

        };

        /**
         * @brief io public interface implementation
         * @relates int16
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
     * @relates int16
     * @remark sse
     */
    template<typename composed_t>
    struct int16_arithmetic
    {

        /**
         * @brief arithmetic basic interface implementation
         * @relates int16
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief arithmetic default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t arithmetic_negate(composed_t one)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "negate");

                return _mm_sub_epi16(_mm_setzero_si128(), one.get_value());
            }


            /**
             * @brief arithmetic default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t arithmetic_add(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "add");

                return _mm_add_epi16(one.get_value(), other.get_value());
            }


            /**
             * @brief arithmetic default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t arithmetic_sub(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "sub");

                return _mm_sub_epi16(one.get_value(), other.get_value());
            }


            /**
             * @brief arithmetic default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t arithmetic_mul(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "mul");

                return _mm_mullo_epi16(one.get_value(), other.get_value());
            }

        };

        /**
         * @brief arithmetic public interface implementation
         * @relates int16
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
     * @relates int16
     * @remark sse
     */
    template<typename composed_t>
    struct int16_bitwise
    {

        /**
         * @brief bitwise basic interface implementation
         * @relates int16
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief bitwise default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t bitwise_negate(composed_t one)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "negate");

                __m128i junk;
                auto ones = _mm_cmpeq_epi16(junk, junk);
                return _mm_xor_si128(one.get_value(), ones);
            }


            /**
             * @brief bitwise default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t bitwise_or(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "or");

                return _mm_or_si128(one.get_value(), other.get_value());
            }


            /**
             * @brief bitwise default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t bitwise_and(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "and");

                return _mm_and_si128(one.get_value(), other.get_value());
            }


            /**
             * @brief bitwise default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t bitwise_xor(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "xor");

                return _mm_xor_si128(one.get_value(), other.get_value());
            }

        };

        /**
         * @brief bitwise public interface implementation
         * @relates int16
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
     * @relates int16
     * @remark sse
     */
    template<typename composed_t>
    struct int16_bitwise_shift
    {

        /**
         * @brief bitwise_shift basic interface implementation
         * @relates int16
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief bitwise_shift default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t bitwise_shift_sll(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "sll");

                return _mm_sll_epi16(one.get_value(), other.get_value());
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t bitwise_shift_srl(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "srl");

                return _mm_srl_epi16(one.get_value(), other.get_value());
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t bitwise_shift_slli(const composed_t one, const size_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "slli");

                return _mm_slli_epi16(one.get_value(), other);
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t bitwise_shift_srli(const composed_t one, const size_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "srli");

                return _mm_srli_epi16(one.get_value(), other);
            }

        };

        /**
         * @brief bitwise_shift public interface implementation
         * @relates int16
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
     * @relates int16
     * @remark sse
     */
    template<typename composed_t>
    struct int16_logical
    {

        /**
         * @brief logical basic interface implementation
         * @relates int16
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief logical default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t logical_negate(composed_t one)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "negate");

                return _mm_cmpeq_epi16(one.get_value(), _mm_setzero_si128());
            }


            /**
             * @brief logical default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t logical_or(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "or");

                return _mm_or_si128(one.get_value(), other.get_value());
            }


            /**
             * @brief logical default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t logical_and(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "and");

                return _mm_and_si128(one.get_value(), other.get_value());
            }

        };

        /**
         * @brief logical public interface implementation
         * @relates int16
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
     * @relates int16
     * @remark sse
     */
    template<typename composed_t>
    struct int16_comparison
    {

        /**
         * @brief comparison basic interface implementation
         * @relates int16
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t comparison_eq(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "eq");

                return _mm_cmpeq_epi16(one.get_value(), other.get_value());
            }


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t comparison_neq(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "neq");

                return !(one == other);
            }


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t comparison_gt(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "gt");

                return _mm_cmpgt_epi16(one.get_value(), other.get_value());
            }


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t comparison_lt(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "lt");

                return _mm_cmplt_epi16(one.get_value(), other.get_value());
            }


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t comparison_ge(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "ge");

                return !(one < other);
            }


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t comparison_le(composed_t one, composed_t other)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "le");

                return !(one > other);
            }

        };

        /**
         * @brief comparison public interface implementation
         * @relates int16
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
     * @relates int16
     * @remark sse
     */
    template<typename composed_t>
    struct int16_conditional
    {

        /**
         * @brief conditional basic interface implementation
         * @relates int16
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            FORWARD(__impl);


            /**
             * @brief conditional default branch
             * @relates int16
             * @remark sse - default
             */
            friend composed_t vsel(composed_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE(std::left << std::setw(32) << "sse.int16.impl line " STRINGIZE(__LINE__) ":" << std::left << std::setw(24) << " zint16(short[8]) " << std::left << std::setw(10) << "default" << "vsel");

                return _mm_or_si128(_mm_andnot_si128(condition.get_value(), else_value.get_value()), _mm_and_si128(condition.get_value(), if_value.get_value()));
            }

        };

        /**
         * @brief conditional public interface implementation
         * @relates int16
         * @remark sse
         */
        template<typename base_t>
        using impl = interface::conditional<__impl<base_t>, composed_t>;
    };

    ///@}


    // Type composition ================================================================================================

    /**
     * @name int16 composition
     */
    ///@{

    /**
     * @brief zval parametrization using
     * - '__m128i' as underlying vector type
     * - 'short' as scalar type
     * - '8' as vector size
     * - '16' as alignment
     * @relates int16
     * @remark sse
     */
    template<uint64_t capability>
    struct __zval_int16
    {
        using zval_t = zval<__m128i, short, 8, 16, capability>;

        struct impl : public zval_t
        {
            FORWARD2(impl, zval_t);
        };
    };
    /**
     * @brief zval composition
     * @relates int16
     * @remark sse
     */
    template<uint64_t capability>
    struct __zint16
    {
        struct impl;

        using zval_t = typename __zval_int16<capability>::impl;
        using composition_t = compose
        <
            printable::impl,
            iteratable::impl,
            convertable::impl,
            int16_io<impl>::template impl,
            int16_arithmetic<impl>::template impl,
            int16_bitwise<impl>::template impl,
            int16_bitwise_shift<impl>::template impl,
            int16_logical<impl>::template impl,
            int16_comparison<impl>::template impl,
            int16_conditional<impl>::template impl,
            int16_construction<impl>::template impl,

            composable<zval_t>::template type
        >;

        struct impl : public composition_t
        {
            FORWARD2(impl, composition_t);
        };
    };

    template<uint64_t capability = 0xFFFF'FFFF'FFFF'FFFF>
    using zint16 = typename __zint16<capability>::impl;

    ///@}
}}