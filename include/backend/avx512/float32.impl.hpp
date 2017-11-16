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
 * @brief float32 implementation for the avx512 branch
 * provides unified access to 16 'float' values
 */

namespace zacc { namespace backend { namespace avx512 {

    template<uint64_t capability>
    struct bfloat32;

    template<uint64_t capability>
    struct zfloat32;


    // =================================================================================================================
    /**
     * @name construction operations
     */
    ///@{

    /**
     * @brief construction
     * @relates float32
     * @remark avx512
     */
    template<typename composed_t>
    struct float32_construction
    {

        /**
         * @brief construction basic interface implementation
         * @relates float32
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;



            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx512 - default
             */
            __impl() : base_t() {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "CONS()");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx512 - default
             */
            __impl(__m512 value) : base_t(value) {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "CONS(__m512 value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx512 - default
             */
            __impl(__m512d value) : base_t(_mm512_cvtpd_ps(value)) {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "CONS(__m512d value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx512 - default
             */
            __impl(__m512i value) : base_t(_mm512_cvtepi32_ps(value)) {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "CONS(__m512i value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx512 - default
             */
            __impl(float value) : base_t(_mm512_set1_ps(value)) {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "CONS(float value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx512 - default
             */
            __impl(std::array<typename base_t::scalar_t, base_t::dim> value) : base_t(_mm512_load_ps(value.data())) {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "CONS(std::array<typename base_t::scal..)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx512 - default
             */
            __impl(float arg15, float arg14, float arg13, float arg12, float arg11, float arg10, float arg9, float arg8, float arg7, float arg6, float arg5, float arg4, float arg3, float arg2, float arg1, float arg0) : base_t(_mm512_set_ps(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15)) {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "CONS(float arg15, float arg14, float ..)");

            }

        };

        /**
         * @brief construction public interface implementation
         * @relates float32
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::construction<__impl<base_t>, zfloat32<base_t::capability>>;

        using impl = traits::construction<__impl<base_t>, zfloat32<base_t::capability>>;

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
     * @remark avx512
     */
    template<typename composed_t>
    struct float32_io
    {

        /**
         * @brief io basic interface implementation
         * @relates float32
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief io default branch
             * @relates float32
             * @remark avx512 - default
             */
            void vstore(typename base_t::extracted_t &target, composed_t source) const noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vstore");

                _mm512_store_ps(target.data(), source);
            }


            /**
             * @brief io default branch
             * @relates float32
             * @remark avx512 - default
             */
            void vstream(typename base_t::extracted_t &target, composed_t source) const noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vstream");

                _mm512_stream_ps(target.data(), source);
            }

        };

        /**
         * @brief io public interface implementation
         * @relates float32
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::io<__impl<base_t>, zfloat32<base_t::capability>>;

        using impl = traits::io<__impl<base_t>, zfloat32<base_t::capability>>;

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
     * @remark avx512
     */
    template<typename composed_t>
    struct float32_arithmetic
    {

        /**
         * @brief arithmetic basic interface implementation
         * @relates float32
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vneg");

                return _mm512_sub_ps(_mm512_setzero_ps(), one);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vadd(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vadd");

                return _mm512_add_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vsub(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vsub");

                return _mm512_sub_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vmul(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vmul");

                return _mm512_mul_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vdiv(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vdiv");

                return _mm512_div_ps(one, other);
            }

        };

        /**
         * @brief arithmetic public interface implementation
         * @relates float32
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::arithmetic<__impl<base_t>, zfloat32<base_t::capability>>;

        using impl = traits::arithmetic<__impl<base_t>, zfloat32<base_t::capability>>;

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
     * @remark avx512
     */
    template<typename composed_t>
    struct float32_bitwise
    {

        /**
         * @brief bitwise basic interface implementation
         * @relates float32
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vneg");

                auto zero = _mm512_setzero_ps();
                auto ones = _mm512_cmpeq_ps(zero, zero);
                return _mm512_xor_ps(one, ones);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vand(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vand");

                return _mm512_or_ps(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> or(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "or");

                return _mm512_and_ps(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> xor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "xor");

                return _mm512_xor_ps(one, other);
            }

        };

        /**
         * @brief bitwise public interface implementation
         * @relates float32
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::bitwise<__impl<base_t>, zfloat32<base_t::capability>>;

        using impl = traits::bitwise<__impl<base_t>, zfloat32<base_t::capability>>;

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
     * @remark avx512
     */
    template<typename composed_t>
    struct float32_logical
    {

        /**
         * @brief logical basic interface implementation
         * @relates float32
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief logical default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vneg");

                auto zero = _mm512_setzero_ps();
                auto ones = _mm512_cmpeq_ps(zero, zero);
                return _mm512_xor_ps(one, ones);
            }


            /**
             * @brief logical default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> or(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "or");

                return _mm512_or_ps(one, other);
            }


            /**
             * @brief logical default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vand(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vand");

                return _mm512_and_ps(one, other);
            }

        };

        /**
         * @brief logical public interface implementation
         * @relates float32
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::logical<__impl<base_t>, bfloat32<base_t::capability>>;

        using impl = traits::logical<__impl<base_t>, zfloat32<base_t::capability>>;

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
     * @remark avx512
     */
    template<typename composed_t>
    struct float32_comparison
    {

        /**
         * @brief comparison basic interface implementation
         * @relates float32
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> veq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "veq");

                return _mm512_cmpeq_ps(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vneq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vneq");

                return _mm512_cmpneq_ps(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vgt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vgt");

                return _mm512_cmpgt_ps(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vlt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vlt");

                return _mm512_cmplt_ps(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vge(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vge");

                return _mm512_cmpge_ps(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vle(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vle");

                return _mm512_cmple_ps(one, other);
            }

        };

        /**
         * @brief comparison public interface implementation
         * @relates float32
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::comparable<__impl<base_t>, zfloat32<base_t::capability>>;

        using impl = traits::comparable<__impl<base_t>, zfloat32<base_t::capability>>;

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
     * @remark avx512
     */
    template<typename composed_t>
    struct float32_conditional
    {

        /**
         * @brief conditional basic interface implementation
         * @relates float32
         * @remark avx512
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief conditional default branch
             * @relates float32
             * @remark avx512 - default
             */
            friend zfloat32<base_t::capability> vsel(composed_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE_BACKEND("avx512.float32.impl", __LINE__, "zfloat32(float[16])", "default", "vsel");

                return _mm512_or_ps(_mm512_andnot_ps(condition, else_value), _mm512_and_ps(condition, if_value));
            }

        };

        /**
         * @brief conditional public interface implementation
         * @relates float32
         * @remark avx512
         */


        template<typename base_t>
        //using impl = traits::conditional<__impl<base_t>, zfloat32<base_t::capability>>;

        using impl = traits::conditional<__impl<base_t>, zfloat32<base_t::capability>>;

    };

    ///@}


    // Type composition ================================================================================================

    /**
     * @name float32 composition
     */
    ///@{

    //namespace composition {

        /**
         * @brief zval parametrization using
         * - '__m512' as underlying vector type
         * - 'float' as scalar type
         * - '16' as vector size
         * - '64' as alignment
         * @relates float32
         * @remark avx512
         */
        template<uint64_t capability>
        struct __zval_float32
        {
            using zval_t = zval<__m512, __mmask16, float, 16, 64, capability>;

            struct impl : public zval_t
            {
                FORWARD2(impl, zval_t);
            };
        };
        /**
         * @brief zval composition
         * @relates float32
         * @remark avx512
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

        template<uint64_t capability>
        struct __bfloat32
        {
            using bval_t = bval<typename __zfloat32<capability>::impl, __mmask16>;
            struct impl : public bval_t
            {
                FORWARD2(impl, bval_t);
            };
        };
    //}

    template<uint64_t capability>
    struct zfloat32 : public /*composition::*/__zfloat32<capability>::impl
    {
        FORWARD2(zfloat32, /*composition::*/__zfloat32<capability>::impl);
    };

    template<uint64_t capability>
    struct bfloat32 : public /*composition::*/__bfloat32<capability>::impl
    {
        FORWARD2(bfloat32, /*composition::*/__bfloat32<capability>::impl);
    };

    static_assert(is_zval<zfloat32<0>>::value, "is_zval for zfloat32 failed.");
    static_assert(is_bval<bfloat32<0>>::value, "is_bval for bfloat32 failed.");

    static_assert(is_floating_point<zfloat32<0>>::value, "is_floating_point for zfloat32 failed.");
    static_assert(!is_integral<zfloat32<0>>::value, "is_integral for zfloat32 failed.");

    static_assert(is_float<zfloat32<0>>::value, "is_float for zfloat32 failed.");
    static_assert(!is_double<zfloat32<0>>::value, "is_double for zfloat32 failed.");

    ///@}
}}}