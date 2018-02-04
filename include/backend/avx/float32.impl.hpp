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
#include "traits/numeric.hpp"
#include "traits/math.hpp"
#include "traits/arithmetic.hpp"
#include "traits/bitwise.hpp"
#include "traits/logical.hpp"
#include "traits/comparable.hpp"
#include "traits/conditional.hpp"

/**
 * @brief float32 implementation for the avx branch
 * provides unified access to 8 'float' values
 */

namespace zacc { namespace backend { namespace avx {

    template<uint64_t arch>
    struct bfloat32;

    template<uint64_t arch>
    struct zfloat32;


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
            using mask_t = typename base_t::mask_t;



            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl() : base_t() {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "CONS()");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(__m256 value) : base_t(value) {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "CONS(__m256 value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(__m256d value) : base_t(_mm256_castps128_ps256(_mm256_cvtpd_ps(value))) {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "CONS(__m256d value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(__m256i value) : base_t(_mm256_cvtepi32_ps(value)) {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "CONS(__m256i value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(float value) : base_t(_mm256_set1_ps(value)) {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "CONS(float value)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(std::array<typename base_t::scalar_t, base_t::dim> value) : base_t(_mm256_loadu_ps(value.data())) {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "CONS(std::array<typename base_t::scal..)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(std::array<sse::zint32<base_t::arch>, 2> value) : base_t(_mm256_set_m128(_mm_cvtepi32_ps(value[1]), _mm_cvtepi32_ps(value[0]))) {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "CONS(std::array<sse::zint32<base_t::c..)");

            }


            /**
             * @brief construction default branch
             * @relates float32
             * @remark avx - default
             */
            __impl(float arg7, float arg6, float arg5, float arg4, float arg3, float arg2, float arg1, float arg0) : base_t(_mm256_set_ps(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7)) {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "CONS(float arg7, float arg6, float ar..)");

            }

        };

        /**
         * @brief construction public interface implementation
         * @relates float32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::construction<__impl<base_t>, zfloat32<base_t::arch>>;

        using impl = traits::construction<__impl<base_t>, zfloat32<base_t::arch>>;

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
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief io default branch
             * @relates float32
             * @remark avx - default
             */
            friend void vstore(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vstore");

                _mm256_store_ps(target.data(), source);
            }


            /**
             * @brief io default branch
             * @relates float32
             * @remark avx - default
             */
            friend void vstream(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vstream");

                _mm256_stream_ps(target.data(), source);
            }


            /**
             * @brief io default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vgather(composed_t &target, raw_ptr<const float> source, zint32<base_t::arch> index)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vgather");

                return _mm256_set_m128(sse::zfloat32<base_t::arch>::gather(source, index.value()[1]), sse::zfloat32<base_t::arch>::gather(source, index.value()[0]));
            }

        };

        /**
         * @brief io public interface implementation
         * @relates float32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::io<__impl<base_t>, zfloat32<base_t::arch>>;

        using impl = traits::io<__impl<base_t>, zfloat32<base_t::arch>>;

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
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);

        };

        /**
         * @brief numeric public interface implementation
         * @relates float32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::numeric<__impl<base_t>, zfloat32<base_t::arch>>;

        using impl = traits::numeric<__impl<base_t>, zfloat32<base_t::arch>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct float32_math
    {

        /**
         * @brief math basic interface implementation
         * @relates float32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief math default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vabs(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vabs");

                return _mm256_max_ps(one, _mm256_sub_ps(_mm256_setzero_ps(), one));
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vmin(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vmin");

                return _mm256_min_ps(one, other);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vmax(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vmax");

                return _mm256_max_ps(one, other);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vclamp(composed_t self, composed_t from, composed_t to)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vclamp");

                return vmin(to, vmax(from, self));
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vrcp(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vrcp");

                return _mm256_rcp_ps(one);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vtrunc(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vtrunc");

                return _mm256_cvtepi32_ps(_mm256_cvtps_epi32(one));
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vfloor(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vfloor");

                return _mm256_floor_ps(one);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vceil(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vceil");

                return _mm256_ceil_ps(one);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vround(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vround");

                return _mm256_round_ps (one, _MM_FROUND_TO_NEAREST_INT |_MM_FROUND_NO_EXC);
            }


            /**
             * @brief math default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vsqrt(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vsqrt");

                return _mm256_sqrt_ps(one);
            }

        };

        /**
         * @brief math public interface implementation
         * @relates float32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::math<__impl<base_t>, zfloat32<base_t::arch>>;

        using impl = traits::math<__impl<base_t>, zfloat32<base_t::arch>>;

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
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vneg");

                return _mm256_sub_ps(_mm256_setzero_ps(), one);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vadd(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vadd");

                return _mm256_add_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vsub(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vsub");

                return _mm256_sub_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vmul(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vmul");

                return _mm256_mul_ps(one, other);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vdiv(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vdiv");

                return _mm256_div_ps(one, other);
            }


            /**
             * @brief arithmetic fma branch
             * @relates float32
             * @remark avx - fma
             */
            template<typename T = zfloat32<base_t::arch>> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::FMA3), T> vfmadd(composed_t multiplicand, composed_t multiplier, composed_t addendum)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "fma", "vfmadd");

                return _mm256_fmadd_ps(multiplicand, multiplier, addendum);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            template<typename T = zfloat32<base_t::arch>> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::FMA3), T> vfmadd(composed_t multiplicand, composed_t multiplier, composed_t addendum)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vfmadd");

                return vadd(vmul(multiplicand, multiplier), addendum);
            }


            /**
             * @brief arithmetic fma branch
             * @relates float32
             * @remark avx - fma
             */
            template<typename T = zfloat32<base_t::arch>> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::FMA3), T> vfmsub(composed_t multiplicand, composed_t multiplier, composed_t addendum)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "fma", "vfmsub");

                return _mm256_fmsub_ps(multiplicand, multiplier, addendum);
            }


            /**
             * @brief arithmetic default branch
             * @relates float32
             * @remark avx - default
             */
            template<typename T = zfloat32<base_t::arch>> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::FMA3), T> vfmsub(composed_t multiplicand, composed_t multiplier, composed_t addendum)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vfmsub");

                return vsub(vmul(multiplicand, multiplier), addendum);
            }

        };

        /**
         * @brief arithmetic public interface implementation
         * @relates float32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::arithmetic<__impl<base_t>, zfloat32<base_t::arch>>;

        using impl = traits::arithmetic<__impl<base_t>, zfloat32<base_t::arch>>;

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
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vbneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vbneg");

                auto zero = _mm256_setzero_ps();
                auto ones = _mm256_cmp_ps(zero, zero, _CMP_EQ_OQ);
                return _mm256_xor_ps(one, ones);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vband(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vband");

                return _mm256_or_ps(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vbor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vbor");

                return _mm256_and_ps(one, other);
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vbxor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vbxor");

                return _mm256_xor_ps(one, other);
            }


            /**
             * @brief bitwise avx2 branch
             * @relates float32
             * @remark avx - avx2
             */
            template<typename T = bool> friend std::enable_if_t<base_t::dispatcher::is_set(capabilities::AVX2), T> is_set(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "avx2", "is_set");

                auto ival =  _mm256_castps_si256(one);
                return _mm256_testc_si256(ival, _mm256_cmpeq_epi32(ival,ival));
            }


            /**
             * @brief bitwise default branch
             * @relates float32
             * @remark avx - default
             */
            template<typename T = bool> friend std::enable_if_t<!base_t::dispatcher::is_set(capabilities::AVX2), T> is_set(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "is_set");

                auto hi = _mm_castps_si128(_mm256_extractf128_ps(one, 1));
                auto lo = _mm_castps_si128(_mm256_extractf128_ps(one, 0));
                return _mm_test_all_ones(hi) != 0 && _mm_test_all_ones(lo) != 0;
            }

        };

        /**
         * @brief bitwise public interface implementation
         * @relates float32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::bitwise<__impl<base_t>, zfloat32<base_t::arch>>;

        using impl = traits::bitwise<__impl<base_t>, zfloat32<base_t::arch>>;

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
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief logical default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vlneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vlneg");

                return _mm256_cmp_ps(one, _mm256_setzero_ps(), _CMP_EQ_OQ);
            }


            /**
             * @brief logical default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vlor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vlor");

                return _mm256_or_ps(one, other);
            }


            /**
             * @brief logical default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vland(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vland");

                return _mm256_and_ps(one, other);
            }

        };

        /**
         * @brief logical public interface implementation
         * @relates float32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::logical<__impl<base_t>, bfloat32<base_t::arch>>;

        using impl = traits::logical<__impl<base_t>, zfloat32<base_t::arch>>;

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
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> veq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "veq");

                return _mm256_cmp_ps(one, other, _CMP_EQ_OQ);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vneq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vneq");

                return _mm256_cmp_ps(one, other, _CMP_NEQ_OQ);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vgt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vgt");

                return _mm256_cmp_ps(one, other, _CMP_GT_OQ);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vlt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vlt");

                return _mm256_cmp_ps(one, other, _CMP_LT_OQ);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vge(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vge");

                return _mm256_cmp_ps(one, other, _CMP_GE_OQ);
            }


            /**
             * @brief comparison default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vle(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vle");

                return _mm256_cmp_ps(one, other, _CMP_LE_OQ);
            }

        };

        /**
         * @brief comparison public interface implementation
         * @relates float32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::comparable<__impl<base_t>, zfloat32<base_t::arch>>;

        using impl = traits::comparable<__impl<base_t>, zfloat32<base_t::arch>>;

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
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief conditional default branch
             * @relates float32
             * @remark avx - default
             */
            friend zfloat32<base_t::arch> vsel(composed_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE_BACKEND("avx.float32.impl", __LINE__, "zfloat32(float[8])", "default", "vsel");

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
        //using impl = traits::conditional<__impl<base_t>, zfloat32<base_t::arch>>;

        using impl = traits::conditional<__impl<base_t>, zfloat32<base_t::arch>>;

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
         * - '__m256' as underlying vector type
         * - 'float' as scalar type
         * - '8' as vector size
         * - '32' as alignment
         * @relates float32
         * @remark avx
         */
        template<uint64_t arch>
        struct __zval_float32
        {
            using zval_t = zval<__m256, __m256, float, 8, 32, arch>;

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
        template<uint64_t arch>
        struct __zfloat32
        {
            struct impl;

            using zval_t = typename __zval_float32<arch>::impl;
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

        template<uint64_t arch>
        struct __bfloat32
        {
            using bval_t = bval<typename __zfloat32<arch>::impl, __m256>;
            struct impl : public bval_t
            {
                FORWARD2(impl, bval_t);
            };
        };
    //}

    template<uint64_t arch>
    struct zfloat32 : public /*composition::*/__zfloat32<arch>::impl
    {
        FORWARD2(zfloat32, /*composition::*/__zfloat32<arch>::impl);
    };

    template<uint64_t arch>
    struct bfloat32 : public /*composition::*/__bfloat32<arch>::impl
    {
        FORWARD2(bfloat32, /*composition::*/__bfloat32<arch>::impl);
    };

    static_assert(is_zval<zfloat32<0>>::value, "is_zval for zfloat32 failed.");
    static_assert(is_bval<bfloat32<0>>::value, "is_bval for bfloat32 failed.");

    static_assert(is_floating_point<zfloat32<0>>::value, "is_floating_point for zfloat32 failed.");
    static_assert(!is_integral<zfloat32<0>>::value, "is_integral for zfloat32 failed.");

    static_assert(is_float<zfloat32<0>>::value, "is_float for zfloat32 failed.");
    static_assert(!is_double<zfloat32<0>>::value, "is_double for zfloat32 failed.");

    ///@}
}}}