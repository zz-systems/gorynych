//---------------------------------------------------------------------------------
//
//  This is an autogenerated file. Do not edit!
//
//---------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2015-2018 Sergej Zuyev (sergej.zuyev - at - zz-systems.net)
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

#include <type_traits>
#include <cmath>

#include "backend/intrin.hpp"
#include "backend/zval.hpp"

#include "util/type/type_composition.hpp"
#include "util/type/type_traits.hpp"

#include "util/memory.hpp"
#include "util/macros.hpp"

#include "traits/common.hpp"
#include "traits/construction.hpp"
#include "traits/io.hpp"
#include "traits/arithmetic.hpp"
#include "traits/bitwise.hpp"
#include "traits/logical.hpp"
#include "traits/comparable.hpp"
#include "traits/conditional.hpp"

/**
 * @brief int8 implementation for the avx512 branch
 * provides unified access to 64 'int8_t' values
 */

namespace zacc { namespace backend { namespace avx512 {

    template<uint64_t arch>
    struct bint8;

    template<uint64_t arch>
    struct zint8;


    // =================================================================================================================
    /**
     * @name construction operations
     */
    ///@{

    /**
     * @brief construction
     * @relates int8
     * @remark avx512
     */
    template<typename composed_t>
    struct int8_construction
    {

        /**
         * @brief construction basic interface implementation
         * @relates int8
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;



            /**
             * @brief construction default branch
             * @relates int8
             * @remark avx512 - default
             */
            __impl() : base_t() {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "CONS()");

            }


            /**
             * @brief construction default branch
             * @relates int8
             * @remark avx512 - default
             */
            __impl(__m512i value) : base_t(value) {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "CONS(__m512i value)");

            }


            /**
             * @brief construction default branch
             * @relates int8
             * @remark avx512 - default
             */
            __impl(int8_t value) : base_t(_mm512_set1_epi8(value)) {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "CONS(int8_t value)");

            }


            /**
             * @brief construction default branch
             * @relates int8
             * @remark avx512 - default
             */
            __impl(std::array<typename base_t::scalar_t, base_t::dim> value) : base_t(_mm512_load_si512(value.data())) {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "CONS(std::array<typename base_t::scal..)");

            }


            /**
             * @brief construction default branch
             * @relates int8
             * @remark avx512 - default
             */
            __impl(int8_t arg63, int8_t arg62, int8_t arg61, int8_t arg60, int8_t arg59, int8_t arg58, int8_t arg57, int8_t arg56, int8_t arg55, int8_t arg54, int8_t arg53, int8_t arg52, int8_t arg51, int8_t arg50, int8_t arg49, int8_t arg48, int8_t arg47, int8_t arg46, int8_t arg45, int8_t arg44, int8_t arg43, int8_t arg42, int8_t arg41, int8_t arg40, int8_t arg39, int8_t arg38, int8_t arg37, int8_t arg36, int8_t arg35, int8_t arg34, int8_t arg33, int8_t arg32, int8_t arg31, int8_t arg30, int8_t arg29, int8_t arg28, int8_t arg27, int8_t arg26, int8_t arg25, int8_t arg24, int8_t arg23, int8_t arg22, int8_t arg21, int8_t arg20, int8_t arg19, int8_t arg18, int8_t arg17, int8_t arg16, int8_t arg15, int8_t arg14, int8_t arg13, int8_t arg12, int8_t arg11, int8_t arg10, int8_t arg9, int8_t arg8, int8_t arg7, int8_t arg6, int8_t arg5, int8_t arg4, int8_t arg3, int8_t arg2, int8_t arg1, int8_t arg0) : base_t(_mm512_set_epi8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32, arg33, arg34, arg35, arg36, arg37, arg38, arg39, arg40, arg41, arg42, arg43, arg44, arg45, arg46, arg47, arg48, arg49, arg50, arg51, arg52, arg53, arg54, arg55, arg56, arg57, arg58, arg59, arg60, arg61, arg62, arg63)) {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "CONS(int8_t arg63, int8_t arg62, int8..)");

            }

        };

        /**
         * @brief construction public interface implementation
         * @relates int8
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::construction<__impl<base_t>, zint8<base_t::arch>>;

        using impl = traits::construction<__impl<base_t>, zint8<base_t::arch>>;

    };

    ///@}


    // =================================================================================================================
    /**
     * @name io operations
     */
    ///@{

    /**
     * @brief io
     * @relates int8
     * @remark avx512
     */
    template<typename composed_t>
    struct int8_io
    {

        /**
         * @brief io basic interface implementation
         * @relates int8
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief io default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend void vstore(typename base_t::extracted_t &target, composed_t source) const noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vstore");

                _mm512_store_si512(target.data(), source);
            }


            /**
             * @brief io default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend void vstream(typename base_t::extracted_t &target, composed_t source) const noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vstream");

                _mm512_stream_si512(target.data(), source);
            }

        };

        /**
         * @brief io public interface implementation
         * @relates int8
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::io<__impl<base_t>, zint8<base_t::arch>>;

        using impl = traits::io<__impl<base_t>, zint8<base_t::arch>>;

    };

    ///@}


    // =================================================================================================================
    /**
     * @name arithmetic operations
     */
    ///@{

    /**
     * @brief arithmetic
     * @relates int8
     * @remark avx512
     */
    template<typename composed_t>
    struct int8_arithmetic
    {

        /**
         * @brief arithmetic basic interface implementation
         * @relates int8
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief arithmetic default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vneg");

                return _mm512_sub_epi8(_mm512_setzero_epi8(), one);
            }

        };

        /**
         * @brief arithmetic public interface implementation
         * @relates int8
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::arithmetic<__impl<base_t>, zint8<base_t::arch>>;

        using impl = traits::arithmetic<__impl<base_t>, zint8<base_t::arch>>;

    };

    ///@}


    // =================================================================================================================
    /**
     * @name bitwise operations
     */
    ///@{

    /**
     * @brief bitwise
     * @relates int8
     * @remark avx512
     */
    template<typename composed_t>
    struct int8_bitwise
    {

        /**
         * @brief bitwise basic interface implementation
         * @relates int8
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vneg");

                auto zero = _mm512_setzero_si128();
                auto ones = _mm512_cmpeq_epi8(zero, zero);
                return _mm512_xor_si128(one, ones);
            }


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vand(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vand");

                return _mm512_or_epi8(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> or(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "or");

                return _mm512_and_epi8(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> xor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "xor");

                return _mm512_xor_si128(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vsll(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vsll");

                return _mm512_sll_epi8(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vsrl(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vsrl");

                return _mm512_srl_epi8(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vslli(const composed_t one, const size_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vslli");

                return _mm512_slli_epi8(const composed_t one, const size_t other);
            }


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vsrli(const composed_t one, const size_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vsrli");

                return _mm512_srli_epi8(const composed_t one, const size_t other);
            }

        };

        /**
         * @brief bitwise public interface implementation
         * @relates int8
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::bitwise<__impl<base_t>, zint8<base_t::arch>>;

        using impl = traits::bitwise<__impl<base_t>, zint8<base_t::arch>>;

    };

    ///@}


    // =================================================================================================================
    /**
     * @name logical operations
     */
    ///@{

    /**
     * @brief logical
     * @relates int8
     * @remark avx512
     */
    template<typename composed_t>
    struct int8_logical
    {

        /**
         * @brief logical basic interface implementation
         * @relates int8
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief logical default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vneg");

                auto zero = _mm512_setzero_si128();
                auto ones = _mm512_cmpeq_epi8(zero, zero);
                return _mm512_xor_si128(one, ones);
            }


            /**
             * @brief logical default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> or(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "or");

                return _mm512_or_epi8(one, other);
            }


            /**
             * @brief logical default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vand(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vand");

                return _mm512_and_epi8(one, other);
            }

        };

        /**
         * @brief logical public interface implementation
         * @relates int8
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::logical<__impl<base_t>, bint8<base_t::arch>>;

        using impl = traits::logical<__impl<base_t>, zint8<base_t::arch>>;

    };

    ///@}


    // =================================================================================================================
    /**
     * @name comparison operations
     */
    ///@{

    /**
     * @brief comparison
     * @relates int8
     * @remark avx512
     */
    template<typename composed_t>
    struct int8_comparison
    {

        /**
         * @brief comparison basic interface implementation
         * @relates int8
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> veq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "veq");

                return _mm512_cmpeq_epi8(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vneq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vneq");

                return _mm512_cmpneq_epi8(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vgt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vgt");

                return _mm512_cmpgt_epi8(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vlt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vlt");

                return _mm512_cmplt_epi8(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vge(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vge");

                return _mm512_cmpge_epi8(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vle(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vle");

                return _mm512_cmple_epi8(one, other);
            }

        };

        /**
         * @brief comparison public interface implementation
         * @relates int8
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::comparable<__impl<base_t>, zint8<base_t::arch>>;

        using impl = traits::comparable<__impl<base_t>, zint8<base_t::arch>>;

    };

    ///@}


    // =================================================================================================================
    /**
     * @name conditional operations
     */
    ///@{

    /**
     * @brief conditional
     * @relates int8
     * @remark avx512
     */
    template<typename composed_t>
    struct int8_conditional
    {

        /**
         * @brief conditional basic interface implementation
         * @relates int8
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief conditional default branch
             * @relates int8
             * @remark avx512 - default
             */
            friend zint8<base_t::arch> vsel(composed_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE_BACKEND("avx512.int8.impl", __LINE__, "zint8(int8_t[64])", "default", "vsel");

                return _mm512_or_si128(_mm512_andnot_si128(condition, else_value), _mm512_and_si128(condition, if_value));
            }

        };

        /**
         * @brief conditional public interface implementation
         * @relates int8
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::conditional<__impl<base_t>, zint8<base_t::arch>>;

        using impl = traits::conditional<__impl<base_t>, zint8<base_t::arch>>;

    };

    ///@}


    // Type composition ================================================================================================

    /**
     * @name int8 composition
     */
    ///@{

    //namespace composition {

        /**
         * @brief zval parametrization using
         * - '__m512i' as underlying vector type
         * - 'int8_t' as scalar type
         * - '64' as vector size
         * - '64' as alignment
         * @relates int8
         * @remark avx512
         */
        template<uint64_t arch>
        struct __zval_int8
        {
            using zval_t = zval<__m512i, __mmask64, int8_t, 64, 64, arch>;

            struct impl : public zval_t
            {
                FORWARD2(impl, zval_t);
            };
        };
        /**
         * @brief zval composition
         * @relates int8
         * @remark avx512
         */
        template<uint64_t arch>
        struct __zint8
        {
            struct impl;

            using zval_t = typename __zval_int8<arch>::impl;
            using composition_t = compose
            <
                printable::impl,
                iteratable::impl,
                convertable::impl,
                int8_io<impl>::template impl,
                int8_arithmetic<impl>::template impl,
                int8_bitwise<impl>::template impl,
                int8_logical<impl>::template impl,
                int8_comparison<impl>::template impl,
                int8_conditional<impl>::template impl,
                int8_construction<impl>::template impl,

                composable<zval_t>::template type
            >;

            struct impl : public composition_t
            {
                FORWARD2(impl, composition_t);
            };
        };

        template<uint64_t arch>
        struct __bint8
        {
            using bval_t = bval<typename __zint8<arch>::impl, __mmask64>;
            struct impl : public bval_t
            {
                FORWARD2(impl, bval_t);
            };
        };
    //}

    template<uint64_t arch>
    struct zint8 : public /*composition::*/__zint8<arch>::impl
    {
        FORWARD2(zint8, /*composition::*/__zint8<arch>::impl);
    };

    template<uint64_t arch>
    struct bint8 : public /*composition::*/__bint8<arch>::impl
    {
        FORWARD2(bint8, /*composition::*/__bint8<arch>::impl);
    };

    static_assert(is_zval<zint8<0>>::value, "is_zval for zint8 failed.");
    static_assert(is_bval<bint8<0>>::value, "is_bval for bint8 failed.");

    static_assert(!is_floating_point<zint8<0>>::value, "is_floating_point for zint8 failed.");
    static_assert(is_integral<zint8<0>>::value, "is_integral for zint8 failed.");

    static_assert(!is_float<zint8<0>>::value, "is_float for zint8 failed.");
    static_assert(!is_double<zint8<0>>::value, "is_double for zint8 failed.");

    ///@}
}}}