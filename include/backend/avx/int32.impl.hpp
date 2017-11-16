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
#include "traits/numeric.hpp"
#include "traits/math.hpp"
#include "traits/arithmetic.hpp"
#include "traits/bitwise.hpp"
#include "traits/bitwise_shift.hpp"
#include "traits/logical.hpp"
#include "traits/comparable.hpp"
#include "traits/conditional.hpp"

/**
 * @brief int32 implementation for the avx branch
 * provides unified access to 8 'int32_t' values
 */

namespace zacc { namespace backend { namespace avx {

    template<uint64_t capability>
    struct bint32;

    template<uint64_t capability>
    struct zint32;


    // =================================================================================================================
    /**
     * @name construction operations
     */
    ///@{

    /**
     * @brief construction
     * @relates int32
     * @remark avx
     */
    template<typename composed_t>
    struct int32_construction
    {

        /**
         * @brief construction basic interface implementation
         * @relates int32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;



            /**
             * @brief construction default branch
             * @relates int32
             * @remark avx - default
             */
            __impl() : base_t() {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "CONS()");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark avx - default
             */
            __impl(__m256 value) : base_t(std::array<sse::zint32<base_t::capability>, 2> ({_mm256_extractf128_ps(value, 1), _mm256_extractf128_ps(value, 0) })) {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "CONS(__m256 value)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark avx - default
             */
            __impl(__m256d value) : base_t(std::array<sse::zint32<base_t::capability>, 2> ({_mm256_extractf128_pd(value, 1), _mm256_extractf128_pd(value, 0) })) {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "CONS(__m256d value)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark avx - default
             */
            __impl(std::array<sse::zint32<base_t::capability>, 2> value) : base_t(value) {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "CONS(std::array<sse::zint32<base_t::c..)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark avx - default
             */
            __impl(sse::zint32<base_t::capability> hi, sse::zint32<base_t::capability> lo) : base_t(std::array<sse::zint32<base_t::capability>, 2> ({ hi, lo })) {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "CONS(sse::zint32<base_t::capability> ..)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark avx - default
             */
            __impl(int32_t value) : base_t(std::array<sse::zint32<base_t::capability>, 2> ({ _mm_set1_epi32(value), _mm_set1_epi32(value) })) {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "CONS(int32_t value)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark avx - default
             */
            __impl(const std::array<typename base_t::scalar_t, base_t::dim> &value) : base_t(std::array<sse::zint32<base_t::capability>, 2> ({ _mm_loadu_si128((__m128i*)value.data()), _mm_loadu_si128((__m128i*)(value.data() + 4)) })) {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "CONS(const std::array<typename base_t..)");

            }

        };

        /**
         * @brief construction public interface implementation
         * @relates int32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::construction<__impl<base_t>, zint32<base_t::capability>>;

        using impl = traits::construction<__impl<base_t>, zint32<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int32_io
    {

        /**
         * @brief io basic interface implementation
         * @relates int32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief io default branch
             * @relates int32
             * @remark avx - default
             */
            friend void vstore(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vstore");

                _mm_store_si128((__m128i*)(target.data()), source.value()[1]);
                _mm_store_si128((__m128i*)(target.data() + base_t::dim / 2), source.value()[0]);
            }


            /**
             * @brief io default branch
             * @relates int32
             * @remark avx - default
             */
            friend void vstream(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vstream");

                _mm_stream_si128((__m128i*)(target.data()), source.value()[1]);
                _mm_stream_si128((__m128i*)(target.data() + base_t::dim / 2), source.value()[0]);
            }


            /**
             * @brief io default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vgather(composed_t &target, raw_ptr<const int> source, zint32<base_t::capability> index)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vgather");

                return zint32<base_t::capability> ({ sse::zint32<base_t::capability>::gather(source, index.value()[1]), sse::zint32<base_t::capability>::gather(source, index.value()[0]) });
            }

        };

        /**
         * @brief io public interface implementation
         * @relates int32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::io<__impl<base_t>, zint32<base_t::capability>>;

        using impl = traits::io<__impl<base_t>, zint32<base_t::capability>>;

    };

    ///@}


    // =================================================================================================================
    /**
     * @name numeric operations
     */
    ///@{

    /**
     * @brief numeric
     * @relates int32
     * @remark avx
     */
    template<typename composed_t>
    struct int32_numeric
    {

        /**
         * @brief numeric basic interface implementation
         * @relates int32
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
         * @relates int32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::numeric<__impl<base_t>, zint32<base_t::capability>>;

        using impl = traits::numeric<__impl<base_t>, zint32<base_t::capability>>;

    };

    ///@}


    // =================================================================================================================
    /**
     * @name math operations
     */
    ///@{

    /**
     * @brief math
     * @relates int32
     * @remark avx
     */
    template<typename composed_t>
    struct int32_math
    {

        /**
         * @brief math basic interface implementation
         * @relates int32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief math default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vabs(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vabs");

                return zint32<base_t::capability> ({ one.value()[1].abs(), one.value()[0].abs() });
            }


            /**
             * @brief math default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vmin(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vmin");

                return zint32<base_t::capability> ({ vmin(one.value()[1], other.value()[1]), vmin(one.value()[0], other.value()[0]) });
            }


            /**
             * @brief math default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vmax(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vmax");

                return zint32<base_t::capability> ({ vmax(one.value()[1], other.value()[1]), vmax(one.value()[0], other.value()[0]) });
            }


            /**
             * @brief math default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vclamp(composed_t self, composed_t from, composed_t to)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vclamp");

                return zint32<base_t::capability> ({ vclamp(self.value()[1], from.value()[1], to.value()[1]), vclamp(self.value()[0], from.value()[0], to.value()[0]) });
            }


            /**
             * @brief math default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vsqrt(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vsqrt");

                return zint32<base_t::capability> ({ vsqrt(one.value()[1]), vsqrt(one.value()[0])});
            }

        };

        /**
         * @brief math public interface implementation
         * @relates int32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::math<__impl<base_t>, zint32<base_t::capability>>;

        using impl = traits::math<__impl<base_t>, zint32<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int32_arithmetic
    {

        /**
         * @brief arithmetic basic interface implementation
         * @relates int32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vneg");

                return zint32<base_t::capability> ({ -one.value()[1], -one.value()[0] });
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vadd(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vadd");

                return zint32<base_t::capability> ({ one.value()[1] + other.value()[1], one.value()[0] + other.value()[0] });
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vsub(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vsub");

                return zint32<base_t::capability> ({ one.value()[1] - other.value()[1], one.value()[0] - other.value()[0] });
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vmul(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vmul");

                return zint32<base_t::capability> ({ one.value()[1] * other.value()[1], one.value()[0] * other.value()[0] });
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vdiv(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vdiv");

                return zint32<base_t::capability> ({ one.value()[1] / other.value()[1], one.value()[0] / other.value()[0] });
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vmod(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vmod");

                return zint32<base_t::capability> ({ one.value()[1] % other.value()[1], one.value()[0] % other.value()[0] });
            }

        };

        /**
         * @brief arithmetic public interface implementation
         * @relates int32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::arithmetic<__impl<base_t>, zint32<base_t::capability>>;

        using impl = traits::arithmetic<__impl<base_t>, zint32<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int32_bitwise
    {

        /**
         * @brief bitwise basic interface implementation
         * @relates int32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vbneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vbneg");

                return zint32<base_t::capability> ({ ~one.value()[1], ~one.value()[0] });
            }


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vbor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vbor");

                return zint32<base_t::capability> ({ one.value()[1] | other.value()[1], one.value()[0] | other.value()[0] });
            }


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vband(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vband");

                return zint32<base_t::capability> ({ one.value()[1] & other.value()[1], one.value()[0] & other.value()[0] });
            }


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vbxor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vbxor");

                return zint32<base_t::capability> ({ one.value()[1] ^ other.value()[1], one.value()[0] ^ other.value()[0] });
            }


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark avx - default
             */
            friend bool is_set(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "is_set");

                return is_set(one.value()[1]) && is_set(one.value()[0]);
            }

        };

        /**
         * @brief bitwise public interface implementation
         * @relates int32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::bitwise<__impl<base_t>, zint32<base_t::capability>>;

        using impl = traits::bitwise<__impl<base_t>, zint32<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int32_bitwise_shift
    {

        /**
         * @brief bitwise_shift basic interface implementation
         * @relates int32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief bitwise_shift default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vbsll(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vbsll");

                return zint32<base_t::capability> ({ one.value()[1] << other.value()[1], one.value()[0] << other.value()[0] });
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vbsrl(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vbsrl");

                return zint32<base_t::capability> ({ one.value()[1] >> other.value()[1], one.value()[0] >> other.value()[0] });
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vbslli(const composed_t one, const size_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vbslli");

                return zint32<base_t::capability> ({ one.value()[1] << other, one.value()[0] << other });
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vbsrli(const composed_t one, const size_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vbsrli");

                return zint32<base_t::capability> ({ one.value()[1] >> other, one.value()[0] >> other });
            }

        };

        /**
         * @brief bitwise_shift public interface implementation
         * @relates int32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::bitwise_shift<__impl<base_t>, zint32<base_t::capability>>;

        using impl = traits::bitwise_shift<__impl<base_t>, zint32<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int32_logical
    {

        /**
         * @brief logical basic interface implementation
         * @relates int32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief logical default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vlneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vlneg");

                return zint32<base_t::capability> ({ !one.value()[1], !one.value()[0] });
            }


            /**
             * @brief logical default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vlor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vlor");

                return zint32<base_t::capability> ({ one.value()[1] || other.value()[1], one.value()[0] || other.value()[0] });
            }


            /**
             * @brief logical default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vland(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vland");

                return zint32<base_t::capability> ({ one.value()[1] && other.value()[1], one.value()[0] && other.value()[0] });
            }

        };

        /**
         * @brief logical public interface implementation
         * @relates int32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::logical<__impl<base_t>, bint32<base_t::capability>>;

        using impl = traits::logical<__impl<base_t>, zint32<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int32_comparison
    {

        /**
         * @brief comparison basic interface implementation
         * @relates int32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> veq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "veq");

                return zint32<base_t::capability> ({ one.value()[1] == other.value()[1], one.value()[0] == other.value()[0] });
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vneq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vneq");

                return zint32<base_t::capability> ({ one.value()[1] != other.value()[1], one.value()[0] != other.value()[0] });
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vgt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vgt");

                return zint32<base_t::capability> ({ one.value()[1] > other.value()[1], one.value()[0] > other.value()[0] });
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vlt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vlt");

                return zint32<base_t::capability> ({ one.value()[1] < other.value()[1], one.value()[0] < other.value()[0] });
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vge(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vge");

                return zint32<base_t::capability> ({ one.value()[1] >= other.value()[1], one.value()[0] >= other.value()[0] });
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vle(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vle");

                return zint32<base_t::capability> ({ one.value()[1] <= other.value()[1], one.value()[0] <= other.value()[0] });
            }

        };

        /**
         * @brief comparison public interface implementation
         * @relates int32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::comparable<__impl<base_t>, zint32<base_t::capability>>;

        using impl = traits::comparable<__impl<base_t>, zint32<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int32_conditional
    {

        /**
         * @brief conditional basic interface implementation
         * @relates int32
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief conditional default branch
             * @relates int32
             * @remark avx - default
             */
            friend zint32<base_t::capability> vsel(composed_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE_BACKEND("avx.int32.impl", __LINE__, "zint32(int32_t[8])", "default", "vsel");

                return zint32<base_t::capability> ({ vsel(condition.value()[1], if_value.value()[1], else_value.value()[1]), vsel(condition.value()[0], if_value.value()[0], else_value.value()[0]) });
            }

        };

        /**
         * @brief conditional public interface implementation
         * @relates int32
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::conditional<__impl<base_t>, zint32<base_t::capability>>;

        using impl = traits::conditional<__impl<base_t>, zint32<base_t::capability>>;

    };

    ///@}


    // Type composition ================================================================================================

    /**
     * @name int32 composition
     */
    ///@{

    //namespace composition {

        /**
         * @brief zval parametrization using
         * - 'std::array<sse::zint32<capability>, 2>' as underlying vector type
         * - 'int32_t' as scalar type
         * - '8' as vector size
         * - '32' as alignment
         * @relates int32
         * @remark avx
         */
        template<uint64_t capability>
        struct __zval_int32
        {
            using zval_t = zval<std::array<sse::zint32<capability>, 2>, std::array<sse::zint32<capability>, 2>, int32_t, 8, 32, capability>;

            struct impl : public zval_t
            {
                FORWARD2(impl, zval_t);
            };
        };
        /**
         * @brief zval composition
         * @relates int32
         * @remark avx
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
                int32_math<impl>::template impl,
                int32_numeric<impl>::template impl,
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

        template<uint64_t capability>
        struct __bint32
        {
            using bval_t = bval<typename __zint32<capability>::impl, std::array<sse::zint32<capability>, 2>>;
            struct impl : public bval_t
            {
                FORWARD2(impl, bval_t);
            };
        };
    //}

    template<uint64_t capability>
    struct zint32 : public /*composition::*/__zint32<capability>::impl
    {
        FORWARD2(zint32, /*composition::*/__zint32<capability>::impl);
    };

    template<uint64_t capability>
    struct bint32 : public /*composition::*/__bint32<capability>::impl
    {
        FORWARD2(bint32, /*composition::*/__bint32<capability>::impl);
    };

    static_assert(is_zval<zint32<0>>::value, "is_zval for zint32 failed.");
    static_assert(is_bval<bint32<0>>::value, "is_bval for bint32 failed.");

    static_assert(!is_floating_point<zint32<0>>::value, "is_floating_point for zint32 failed.");
    static_assert(is_integral<zint32<0>>::value, "is_integral for zint32 failed.");

    static_assert(!is_float<zint32<0>>::value, "is_float for zint32 failed.");
    static_assert(!is_double<zint32<0>>::value, "is_double for zint32 failed.");

    ///@}
}}}