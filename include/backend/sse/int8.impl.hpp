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

#include "intrin.hpp"
#include <type_traits>
#include <cmath>

#include "util/type_composition.hpp"
#include "util/memory.hpp"
#include "zval.hpp"
#include "common.hpp"
#include "type_traits.hpp"

#include "traits/common.hpp"
#include "traits/construction.hpp"
#include "traits/io.hpp"
#include "traits/numeric.hpp"
#include "traits/math.hpp"
#include "traits/arithmetic.hpp"
#include "traits/bitwise.hpp"
#include "traits/logical.hpp"
#include "traits/comparison.hpp"
#include "traits/conditional.hpp"

/**
 * @brief int8 implementation for the sse branch
 * provides unified access to 16 'int8_t' values
 */

namespace zacc { namespace backend { namespace sse {

    template<uint64_t capability>
    struct bint8;

    template<uint64_t capability>
    struct zint8;


    // =================================================================================================================
    /**
     * @name construction operations
     */
    ///@{

    /**
     * @brief construction
     * @relates int8
     * @remark sse
     */
    template<typename composed_t>
    struct int8_construction
    {

        /**
         * @brief construction basic interface implementation
         * @relates int8
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;



            /**
             * @brief construction default branch
             * @relates int8
             * @remark sse - default
             */
            __impl() : base_t() {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "CONS()");

            }


            /**
             * @brief construction default branch
             * @relates int8
             * @remark sse - default
             */
            __impl(__m128i value) : base_t(value) {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "CONS(__m128i value)");

            }


            /**
             * @brief construction default branch
             * @relates int8
             * @remark sse - default
             */
            __impl(int8_t value) : base_t(_mm_set1_epi8(value)) {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "CONS(int8_t value)");

            }


            /**
             * @brief construction default branch
             * @relates int8
             * @remark sse - default
             */
            __impl(const std::array<typename base_t::scalar_t, base_t::dim> &value) : base_t(_mm_loadu_si128((__m128i*)value.data())) {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "CONS(const std::array<typename base_t..)");

            }


            /**
             * @brief construction default branch
             * @relates int8
             * @remark sse - default
             */
            __impl(int8_t arg15, int8_t arg14, int8_t arg13, int8_t arg12, int8_t arg11, int8_t arg10, int8_t arg9, int8_t arg8, int8_t arg7, int8_t arg6, int8_t arg5, int8_t arg4, int8_t arg3, int8_t arg2, int8_t arg1, int8_t arg0) : base_t(_mm_set_epi8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15)) {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "CONS(int8_t arg15, int8_t arg14, int8..)");

            }

        };

        /**
         * @brief construction public interface implementation
         * @relates int8
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::construction<__impl<base_t>, zint8<base_t::capability>>;

        using impl = traits::construction<__impl<base_t>, zint8<base_t::capability>>;

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
     * @remark sse
     */
    template<typename composed_t>
    struct int8_io
    {

        /**
         * @brief io basic interface implementation
         * @relates int8
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief io default branch
             * @relates int8
             * @remark sse - default
             */
            friend void vstore(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vstore");

                _mm_storeu_si128((__m128i*)target.data(), source);
            }


            /**
             * @brief io default branch
             * @relates int8
             * @remark sse - default
             */
            friend void vstream(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vstream");

                _mm_stream_si128((__m128i*)target.data(), source);
            }

        };

        /**
         * @brief io public interface implementation
         * @relates int8
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::io<__impl<base_t>, zint8<base_t::capability>>;

        using impl = traits::io<__impl<base_t>, zint8<base_t::capability>>;

    };

    ///@}


    // =================================================================================================================
    /**
     * @name numeric operations
     */
    ///@{

    /**
     * @brief numeric
     * @relates int8
     * @remark sse
     */
    template<typename composed_t>
    struct int8_numeric
    {

        /**
         * @brief numeric basic interface implementation
         * @relates int8
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);

        };

        /**
         * @brief numeric public interface implementation
         * @relates int8
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::numeric<__impl<base_t>, zint8<base_t::capability>>;

        using impl = traits::numeric<__impl<base_t>, zint8<base_t::capability>>;

    };

    ///@}


    // =================================================================================================================
    /**
     * @name math operations
     */
    ///@{

    /**
     * @brief math
     * @relates int8
     * @remark sse
     */
    template<typename composed_t>
    struct int8_math
    {

        /**
         * @brief math basic interface implementation
         * @relates int8
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief math sse4 branch
             * @relates int8
             * @remark sse - sse4
             */
            template<typename T = zint8<base_t::capability>> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::SSE3), T> vabs(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "sse4", "vabs");

                return _mm_abs_epi8(one);
            }


            /**
             * @brief math default branch
             * @relates int8
             * @remark sse - default
             */
            template<typename T = zint8<base_t::capability>> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::SSE3), T> vabs(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vabs");

                return vmax(one, -one);
            }


            /**
             * @brief math sse4 branch
             * @relates int8
             * @remark sse - sse4
             */
            template<typename T = zint8<base_t::capability>> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::SSE41), T> vmin(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "sse4", "vmin");

                return _mm_min_epi8(one, other);
            }


            /**
             * @brief math default branch
             * @relates int8
             * @remark sse - default
             */
            template<typename T = zint8<base_t::capability>> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::SSE41), T> vmin(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vmin");

                return vsel(one < other, one, other);
            }


            /**
             * @brief math sse4 branch
             * @relates int8
             * @remark sse - sse4
             */
            template<typename T = zint8<base_t::capability>> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::SSE41), T> vmax(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "sse4", "vmax");

                return _mm_max_epi8(one, other);
            }


            /**
             * @brief math default branch
             * @relates int8
             * @remark sse - default
             */
            template<typename T = zint8<base_t::capability>> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::SSE41), T> vmax(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vmax");

                return vsel(one < other, one, other);
            }


            /**
             * @brief math default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vclamp(composed_t self, composed_t from, composed_t to)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vclamp");

                return vmin(to, vmax(from, self));
            }

        };

        /**
         * @brief math public interface implementation
         * @relates int8
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::math<__impl<base_t>, zint8<base_t::capability>>;

        using impl = traits::math<__impl<base_t>, zint8<base_t::capability>>;

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
     * @remark sse
     */
    template<typename composed_t>
    struct int8_arithmetic
    {

        /**
         * @brief arithmetic basic interface implementation
         * @relates int8
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief arithmetic default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vneg");

                return _mm_sub_epi8(_mm_setzero_si128(), one);
            }


            /**
             * @brief arithmetic default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vadd(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vadd");

                return _mm_add_epi8(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vsub(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vsub");

                return _mm_sub_epi8(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vmul(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vmul");

                /// @see http://stackoverflow.com/a/29155682/1261537;
                auto even = _mm_mullo_epi16(one, other);
                auto odd  = _mm_mullo_epi16(_mm_srli_epi16(one, 8),_mm_srli_epi16(other, 8));
                return _mm_or_si128(_mm_slli_epi16(odd, 8), _mm_and_si128(even, _mm_set1_epi16(0xFF)));
            }


            /**
             * @brief arithmetic default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vdiv(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vdiv");

                auto dividend = one.data();
                auto divisor = other.data();
                typename composed_t::extracted_t result;
                for (auto i = 0; i < composed_t::dim; i++) { result[i] = dividend[i] / divisor[i]; };
                return result;
            }


            /**
             * @brief arithmetic default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vmod(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vmod");

                return vsub(one, vmul(other, vdiv(one, other)));
            }

        };

        /**
         * @brief arithmetic public interface implementation
         * @relates int8
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::arithmetic<__impl<base_t>, zint8<base_t::capability>>;

        using impl = traits::arithmetic<__impl<base_t>, zint8<base_t::capability>>;

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
     * @remark sse
     */
    template<typename composed_t>
    struct int8_bitwise
    {

        /**
         * @brief bitwise basic interface implementation
         * @relates int8
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vbneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vbneg");

                auto zero = _mm_setzero_si128();
                auto ones = _mm_cmpeq_epi8(zero, zero);
                return _mm_xor_si128(one, ones);
            }


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vbor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vbor");

                return _mm_or_si128(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vband(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vband");

                return _mm_and_si128(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vbxor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vbxor");

                return _mm_xor_si128(one, other);
            }


            /**
             * @brief bitwise sse4 branch
             * @relates int8
             * @remark sse - sse4
             */
            template<typename T = bool> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::SSE41), T> is_set(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "sse4", "is_set");

                return _mm_test_all_ones(one) != 0;
            }


            /**
             * @brief bitwise default branch
             * @relates int8
             * @remark sse - default
             */
            template<typename T = bool> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::SSE41), T> is_set(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "is_set");

                auto zero = _mm_setzero_si128();
                auto ones = _mm_cmpeq_epi32(zero, zero);
                return _mm_movemask_epi8(_mm_cmpeq_epi8(one, ones)) == 0xFFFF;
            }

        };

        /**
         * @brief bitwise public interface implementation
         * @relates int8
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::bitwise<__impl<base_t>, zint8<base_t::capability>>;

        using impl = traits::bitwise<__impl<base_t>, zint8<base_t::capability>>;

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
     * @remark sse
     */
    template<typename composed_t>
    struct int8_logical
    {

        /**
         * @brief logical basic interface implementation
         * @relates int8
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief logical default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vlneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vlneg");

                return _mm_cmpeq_epi8(one, _mm_setzero_si128());
            }


            /**
             * @brief logical default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vlor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vlor");

                return _mm_or_si128(one, other);
            }


            /**
             * @brief logical default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vland(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vland");

                return _mm_and_si128(one, other);
            }

        };

        /**
         * @brief logical public interface implementation
         * @relates int8
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::logical<__impl<base_t>, bint8<base_t::capability>>;

        using impl = traits::logical<__impl<base_t>, zint8<base_t::capability>>;

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
     * @remark sse
     */
    template<typename composed_t>
    struct int8_comparison
    {

        /**
         * @brief comparison basic interface implementation
         * @relates int8
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> veq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "veq");

                return _mm_cmpeq_epi8(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vneq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vneq");

                return !(one == other);
            }


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vgt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vgt");

                return _mm_cmpgt_epi8(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vlt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vlt");

                return _mm_cmplt_epi8(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vge(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vge");

                return !(one < other);
            }


            /**
             * @brief comparison default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vle(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vle");

                return !(one > other);
            }

        };

        /**
         * @brief comparison public interface implementation
         * @relates int8
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::comparison<__impl<base_t>, zint8<base_t::capability>>;

        using impl = traits::comparison<__impl<base_t>, zint8<base_t::capability>>;

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
     * @remark sse
     */
    template<typename composed_t>
    struct int8_conditional
    {

        /**
         * @brief conditional basic interface implementation
         * @relates int8
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief conditional default branch
             * @relates int8
             * @remark sse - default
             */
            friend zint8<base_t::capability> vsel(composed_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE_BACKEND("sse.int8.impl", __LINE__, "zint8(int8_t[16])", "default", "vsel");

                return _mm_or_si128(_mm_andnot_si128(condition, else_value), _mm_and_si128(condition, if_value));
            }

        };

        /**
         * @brief conditional public interface implementation
         * @relates int8
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::conditional<__impl<base_t>, zint8<base_t::capability>>;

        using impl = traits::conditional<__impl<base_t>, zint8<base_t::capability>>;

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
         * - '__m128i' as underlying vector type
         * - 'int8_t' as scalar type
         * - '16' as vector size
         * - '16' as alignment
         * @relates int8
         * @remark sse
         */
        template<uint64_t capability>
        struct __zval_int8
        {
            using zval_t = zval<__m128i, __m128i, int8_t, 16, 16, capability>;

            struct impl : public zval_t
            {
                FORWARD2(impl, zval_t);
            };
        };
        /**
         * @brief zval composition
         * @relates int8
         * @remark sse
         */
        template<uint64_t capability>
        struct __zint8
        {
            struct impl;

            using zval_t = typename __zval_int8<capability>::impl;
            using composition_t = compose
            <
                printable::impl,
                iteratable::impl,
                convertable::impl,
                int8_io<impl>::template impl,
                int8_math<impl>::template impl,
                int8_numeric<impl>::template impl,
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

        template<uint64_t capability>
        struct __bint8
        {
            using bval_t = bval<typename __zint8<capability>::impl, __m128i>;
            struct impl : public bval_t
            {
                FORWARD2(impl, bval_t);
            };
        };
    //}

    template<uint64_t capability>
    struct zint8 : public /*composition::*/__zint8<capability>::impl
    {
        FORWARD2(zint8, /*composition::*/__zint8<capability>::impl);
    };

    template<uint64_t capability>
    struct bint8 : public /*composition::*/__bint8<capability>::impl
    {
        FORWARD2(bint8, /*composition::*/__bint8<capability>::impl);
    };

    static_assert(is_zval<zint8<0>>::value, "is_zval for zint8 failed.");
    static_assert(is_bval<bint8<0>>::value, "is_bval for bint8 failed.");

    static_assert(!is_floating_point<zint8<0>>::value, "is_floating_point for zint8 failed.");
    static_assert(is_integral<zint8<0>>::value, "is_integral for zint8 failed.");

    static_assert(!is_float<zint8<0>>::value, "is_float for zint8 failed.");
    static_assert(!is_double<zint8<0>>::value, "is_double for zint8 failed.");

    ///@}
}}}