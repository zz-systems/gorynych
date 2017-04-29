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
#include <cmath>

#include "util/type_composition.hpp"

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

// emulation
#include "backend/sse/int8.impl.hpp"
#include "backend/sse/int16.impl.hpp"
#include "backend/sse/int32.impl.hpp"

/**
 * @brief float32 implementation for the sse branch
 * provides unified access to 4 'float' values
 */

namespace zacc { namespace sse {

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
     * @remark sse
     */
    template<typename composed_t>
    struct float32_construction
    {

        /**
         * @brief construction basic interface implementation
         * @relates float32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;



            /**
             * @brief construction default branch
             * @relates float32
             * @remark sse - default
             */
            __impl() : base_t() {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "CONS()");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark sse - default
             */
            __impl(__m128 value) : base_t(value) {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "CONS(__m128 value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark sse - default
             */
            __impl(__m128d value) : base_t(_mm_cvtpd_ps(value)) {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "CONS(__m128d value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark sse - default
             */
            __impl(__m128i value) : base_t(_mm_cvtepi32_ps(value)) {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "CONS(__m128i value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark sse - default
             */
            __impl(float value) : base_t(_mm_set1_ps(value)) {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "CONS(float value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark sse - default
             */
            __impl(std::array<typename base_t::scalar_t, base_t::dim> value) : base_t(_mm_load_ps(value.data())) {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "CONS(std::array<typename base_t::scal..)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark sse - default
             */
            __impl(float arg3, float arg2, float arg1, float arg0) : base_t(_mm_set_ps(arg0, arg1, arg2, arg3)) {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "CONS(float arg3, float arg2, float ar..)");

            }

        };

        /**
         * @brief construction public interface implementation
         * @relates float32
         * @remark sse
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
     * @remark sse
     */
    template<typename composed_t>
    struct float32_io
    {

        /**
         * @brief io basic interface implementation
         * @relates float32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief io default branch
             * @relates float32
             * @remark sse - default
             */
            friend void vstore(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vstore");

                _mm_store_ps(target.data(), source);
            }


            /**
             * @brief io default branch
             * @relates float32
             * @remark sse - default
             */
            friend void vstream(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vstream");

                _mm_stream_ps(target.data(), source);
            }


            /**
             * @brief io default branch
             * @relates float32
             * @remark sse - default
             */
            template<typename T> friend zfloat32<base_t::capability> vgather(T* source, zint32<base_t::capability> index)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vgather");

                auto i = index.data();
                return _mm_set_ps(source[i[3]], source[i[2]], source[i[1]], source[i[0]]);
            }

        };

        /**
         * @brief io public interface implementation
         * @relates float32
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::io<__impl<base_t>, zfloat32<base_t::capability>>;

        using impl = traits::io<__impl<base_t>, zfloat32<base_t::capability>>;

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
     * @remark sse
     */
    template<typename composed_t>
    struct float32_numeric
    {

        /**
         * @brief numeric basic interface implementation
         * @relates float32
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
         * @relates float32
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::numeric<__impl<base_t>, zfloat32<base_t::capability>>;

        using impl = traits::numeric<__impl<base_t>, zfloat32<base_t::capability>>;

    };

    ///@}


    // =================================================================================================================
    /**
     * @name math operations
     */
    ///@{

    /**
     * @brief math
     * @relates float32
     * @remark sse
     */
    template<typename composed_t>
    struct float32_math
    {

        /**
         * @brief math basic interface implementation
         * @relates float32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief math default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vabs(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vabs");

                return _mm_max_ps(one, -one);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vmin(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vmin");

                return _mm_min_ps(one, other);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vmax(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vmax");

                return _mm_max_ps(one, other);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vclamp(composed_t self, composed_t from, composed_t to)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vclamp");

                return vmin(to, vmax(from, self));
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vrcp(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vrcp");

                return _mm_rcp_ps(one);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vtrunc(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vtrunc");

                return _mm_cvtepi32_ps(_mm_cvtps_epi32(one));
            }


            /**
             * @brief math sse4 branch
             * @relates float32
             * @remark sse - sse4
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::SSE41), T> vfloor(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "sse4", "vfloor");

                return _mm_floor_ps(one);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark sse - default
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::SSE41), T> vfloor(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vfloor");

                __m128i junk;
                auto _1  = _mm_srli_epi32(_mm_cmpeq_epi32(junk, junk), 31);
                auto fi = vtrunc(one);
                return vsel(vgt(fi, one), vsub(fi, _1), fi);
            }


            /**
             * @brief math sse4 branch
             * @relates float32
             * @remark sse - sse4
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::SSE41), T> vceil(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "sse4", "vceil");

                return _mm_ceil_ps(one);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark sse - default
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::SSE41), T> vceil(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vceil");

                __m128i junk;
                auto _1  = _mm_srli_epi32(_mm_cmpeq_epi32(junk, junk), 31);
                auto fi = vtrunc(one);
                return vsel(vlt(fi, one), vadd(fi, _1), fi);
            }


            /**
             * @brief math sse4 branch
             * @relates float32
             * @remark sse - sse4
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::SSE41), T> vround(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "sse4", "vround");

                return _mm_round_ps (one, _MM_FROUND_TO_NEAREST_INT |_MM_FROUND_NO_EXC);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark sse - default
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::SSE41), T> vround(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vround");

                auto zero = _mm_setzero_si128();
                auto ones = _mm_cmpeq_epi32(zero, zero);
                // generate the highest value < 2;
                auto nearest = _mm_castsi128_ps(_mm_srli_epi32(ones, 2));
                auto tr = vtrunc(one);
                // get remainder;
                auto rmd = one - tr;
                // mul remainder by near 2 will yield the needed offset;
                auto rmd2 = vmul(rmd, nearest);
                // after being truncated of course;
                auto rmd2tr = vtrunc(rmd2);
                return tr + rmd2tr;
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vsqrt(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vsqrt");

                return _mm_sqrt_ps(one);
            }

        };

        /**
         * @brief math public interface implementation
         * @relates float32
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::math<__impl<base_t>, zfloat32<base_t::capability>>;

        using impl = traits::math<__impl<base_t>, zfloat32<base_t::capability>>;

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
     * @remark sse
     */
    template<typename composed_t>
    struct float32_arithmetic
    {

        /**
         * @brief arithmetic basic interface implementation
         * @relates float32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vneg");

                return _mm_sub_ps(_mm_setzero_ps(), one);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vadd(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vadd");

                return _mm_add_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vsub(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vsub");

                return _mm_sub_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vmul(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vmul");

                return _mm_mul_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vdiv(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vdiv");

                return _mm_div_ps(one, other);
            }


            /**
             * @brief arithmetic fma branch
             * @relates float32
             * @remark sse - fma
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::FMA3), T> vfmadd(composed_t multiplicand, composed_t multiplier, composed_t addendum)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "fma", "vfmadd");

                return _mm_fmadd_ps(multiplicand, multiplier, addendum);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark sse - default
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::FMA3), T> vfmadd(composed_t multiplicand, composed_t multiplier, composed_t addendum)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vfmadd");

                return vadd(vmul(multiplicand, multiplier), addendum);
            }


            /**
             * @brief arithmetic fma branch
             * @relates float32
             * @remark sse - fma
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::FMA3), T> vfmsub(composed_t multiplicand, composed_t multiplier, composed_t addendum)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "fma", "vfmsub");

                return _mm_fmsub_ps(multiplicand, multiplier, addendum);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark sse - default
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::FMA3), T> vfmsub(composed_t multiplicand, composed_t multiplier, composed_t addendum)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vfmsub");

                return vsub(vmul(multiplicand, multiplier), addendum);
            }

        };

        /**
         * @brief arithmetic public interface implementation
         * @relates float32
         * @remark sse
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
     * @remark sse
     */
    template<typename composed_t>
    struct float32_bitwise
    {

        /**
         * @brief bitwise basic interface implementation
         * @relates float32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vbneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vbneg");

                __m128 junk;
                auto ones = _mm_cmpeq_ps(junk, junk);
                return _mm_xor_ps(one, ones);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vband(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vband");

                return _mm_or_ps(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vbor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vbor");

                return _mm_and_ps(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vbxor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vbxor");

                return _mm_xor_ps(one, other);
            }


            /**
             * @brief bitwise sse4 branch
             * @relates float32
             * @remark sse - sse4
             */
            template<typename T = bool> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::SSE41), T> is_set(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "sse4", "is_set");

                return _mm_test_all_ones(_mm_castps_si128(one)) != 0;
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark sse - default
             */
            template<typename T = bool> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::SSE41), T> is_set(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "is_set");

                __m128 junk;
                auto ones = _mm_cmpeq_ps(junk, junk);
                return _mm_movemask_ps(_mm_cmpeq_ps(one, ones)) == 0xFFFF;
            }

        };

        /**
         * @brief bitwise public interface implementation
         * @relates float32
         * @remark sse
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
     * @remark sse
     */
    template<typename composed_t>
    struct float32_logical
    {

        /**
         * @brief logical basic interface implementation
         * @relates float32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief logical default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vlneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vlneg");

                return _mm_cmpeq_ps(one, _mm_setzero_ps());
            }


            /**
             * @brief logical default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vlor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vlor");

                return _mm_or_ps(one, other);
            }


            /**
             * @brief logical default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vland(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vland");

                return _mm_and_ps(one, other);
            }

        };

        /**
         * @brief logical public interface implementation
         * @relates float32
         * @remark sse
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
     * @remark sse
     */
    template<typename composed_t>
    struct float32_comparison
    {

        /**
         * @brief comparison basic interface implementation
         * @relates float32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> veq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "veq");

                return _mm_cmpeq_ps(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vneq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vneq");

                return _mm_cmpneq_ps(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vgt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vgt");

                return _mm_cmpgt_ps(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vlt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vlt");

                return _mm_cmplt_ps(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vge(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vge");

                return _mm_cmpge_ps(one, other);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark sse - default
             */
            friend zfloat32<base_t::capability> vle(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vle");

                return _mm_cmple_ps(one, other);
            }

        };

        /**
         * @brief comparison public interface implementation
         * @relates float32
         * @remark sse
         */


        template<typename base_t>
        //using impl = traits::comparison<__impl<base_t>, zfloat32<base_t::capability>>;

        using impl = traits::comparison<__impl<base_t>, zfloat32<base_t::capability>>;

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
     * @remark sse
     */
    template<typename composed_t>
    struct float32_conditional
    {

        /**
         * @brief conditional basic interface implementation
         * @relates float32
         * @remark sse
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief conditional sse4 branch
             * @relates float32
             * @remark sse - sse4
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::SSE41), T> vsel(mask_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "sse4", "vsel");

                auto mask = _mm_cmpeq_ps(_mm_setzero_ps(), condition);
                return _mm_blendv_ps(if_value, else_value, mask);
            }


            /**
             * @brief conditional default branch
             * @relates float32
             * @remark sse - default
             */
            template<typename T = zfloat32<base_t::capability>> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::SSE41), T> vsel(mask_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE_BACKEND("sse.float32.impl", __LINE__, "zfloat32(float[4])", "default", "vsel");

                auto mask = _mm_cmpeq_ps(_mm_setzero_ps(), condition);
                return _mm_xor_ps(if_value, _mm_and_ps( mask, _mm_xor_ps(else_value, if_value)));
            }

        };

        /**
         * @brief conditional public interface implementation
         * @relates float32
         * @remark sse
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
         * - '__m128' as underlying vector type
         * - 'float' as scalar type
         * - '4' as vector size
         * - '16' as alignment
         * @relates float32
         * @remark sse
         */
        template<uint64_t capability>
        struct __zval_float32
        {
            using zval_t = zval<__m128, __m128, float, 4, 16, capability>;

            struct impl : public zval_t
            {
                FORWARD2(impl, zval_t);
            };
        };
        /**
         * @brief zval composition
         * @relates float32
         * @remark sse
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
                float32_math<impl>::template impl,
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

        template<uint64_t capability>
        struct __bfloat32
        {
            using bval_t = bval<typename __zfloat32<capability>::impl, __m128>;
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
}}