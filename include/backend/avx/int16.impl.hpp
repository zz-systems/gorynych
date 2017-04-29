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
#include "traits/arithmetic.hpp"
#include "traits/bitwise.hpp"
#include "traits/bitwise_shift.hpp"
#include "traits/logical.hpp"
#include "traits/comparison.hpp"
#include "traits/conditional.hpp"

// emulation
#include "backend/sse/int8.impl.hpp"
#include "backend/sse/int16.impl.hpp"
#include "backend/sse/int32.impl.hpp"

/**
 * @brief int16 implementation for the avx branch
 * provides unified access to 16 'int16_t' values
 */

namespace zacc { namespace avx {

    template<uint64_t capability>
    struct bint16;

    template<uint64_t capability>
    struct zint16;


    // =================================================================================================================
    /**
     * @name construction operations
     */
    ///@{

    /**
     * @brief construction
     * @relates int16
     * @remark avx
     */
    template<typename composed_t>
    struct int16_construction
    {

        /**
         * @brief construction basic interface implementation
         * @relates int16
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;



            /**
             * @brief construction default branch
             * @relates int16
             * @remark avx - default
             */
            __impl() : base_t() {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "CONS()");

            }


            /**
             * @brief construction default branch
             * @relates int16
             * @remark avx - default
             */
            __impl(std::array<sse::zint16<base_t::capability>, 2> value) : base_t(value) {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "CONS(std::array<sse::zint16<base_t::c..)");

            }


            /**
             * @brief construction default branch
             * @relates int16
             * @remark avx - default
             */
            __impl(sse::zint16<base_t::capability> hi, sse::zint16<base_t::capability> lo) : base_t(std::array<sse::zint16<base_t::capability>, 2> ({ hi, lo })) {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "CONS(sse::zint16<base_t::capability> ..)");

            }


            /**
             * @brief construction default branch
             * @relates int16
             * @remark avx - default
             */
            __impl(int16_t value) : base_t(std::array<sse::zint16<base_t::capability>, 2> ({ _mm_set1_epi16(value), _mm_set1_epi16(value) })) {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "CONS(int16_t value)");

            }


            /**
             * @brief construction default branch
             * @relates int16
             * @remark avx - default
             */
            __impl(std::array<typename base_t::scalar_t, base_t::dim> value) : base_t(std::array<sse::zint16<base_t::capability>, 2> ({ _mm_loadu_si128((__m128i*)value.data()), _mm_loadu_si128((__m128i*)(value.data() + 4)) })) {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "CONS(std::array<typename base_t::scal..)");

            }

        };

        /**
         * @brief construction public interface implementation
         * @relates int16
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::construction<__impl<base_t>, zint16<base_t::capability>>;

        using impl = traits::construction<__impl<base_t>, zint16<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int16_io
    {

        /**
         * @brief io basic interface implementation
         * @relates int16
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief io default branch
             * @relates int16
             * @remark avx - default
             */
            friend void vstore(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vstore");

                _mm_store_si128((__m128i*)(target.data()), source.get_value()[1]);
                _mm_store_si128((__m128i*)(target.data() + base_t::dim / 2), source.get_value()[0]);
            }


            /**
             * @brief io default branch
             * @relates int16
             * @remark avx - default
             */
            friend void vstream(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vstream");

                _mm_stream_si128((__m128i*)(target.data()), source.get_value()[1]);
                _mm_stream_si128((__m128i*)(target.data() + base_t::dim / 2), source.get_value()[0]);
            }

        };

        /**
         * @brief io public interface implementation
         * @relates int16
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::io<__impl<base_t>, zint16<base_t::capability>>;

        using impl = traits::io<__impl<base_t>, zint16<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int16_arithmetic
    {

        /**
         * @brief arithmetic basic interface implementation
         * @relates int16
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief arithmetic default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vneg");

                return zint16<base_t::capability> ({ -one.get_value()[1], -one.get_value()[0] });
            }


            /**
             * @brief arithmetic default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vadd(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vadd");

                return zint16<base_t::capability> ({ one.get_value()[1] + other.get_value()[1], one.get_value()[0] + other.get_value()[0] });
            }


            /**
             * @brief arithmetic default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vsub(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vsub");

                return zint16<base_t::capability> ({ one.get_value()[1] - other.get_value()[1], one.get_value()[0] - other.get_value()[0] });
            }


            /**
             * @brief arithmetic default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vmul(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vmul");

                return zint16<base_t::capability> ({ one.get_value()[1] * other.get_value()[1], one.get_value()[0] * other.get_value()[0] });
            }

        };

        /**
         * @brief arithmetic public interface implementation
         * @relates int16
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::arithmetic<__impl<base_t>, zint16<base_t::capability>>;

        using impl = traits::arithmetic<__impl<base_t>, zint16<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int16_bitwise
    {

        /**
         * @brief bitwise basic interface implementation
         * @relates int16
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief bitwise default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vbneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vbneg");

                return zint16<base_t::capability> ({ ~one.get_value()[1], ~one.get_value()[1] });
            }


            /**
             * @brief bitwise default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vbor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vbor");

                return zint16<base_t::capability> ({ one.get_value()[1] | other.get_value()[1], one.get_value()[0] | other.get_value()[0] });
            }


            /**
             * @brief bitwise default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vband(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vband");

                return zint16<base_t::capability> ({ one.get_value()[1] & other.get_value()[1], one.get_value()[0] & other.get_value()[0] });
            }


            /**
             * @brief bitwise default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vbxor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vbxor");

                return zint16<base_t::capability> ({ one.get_value()[1] ^ other.get_value()[1], one.get_value()[0] ^ other.get_value()[0] });
            }


            /**
             * @brief bitwise default branch
             * @relates int16
             * @remark avx - default
             */
            friend bool is_set(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "is_set");

                return is_set(one.get_value()[1]) && is_set(one.get_value()[0]);
            }

        };

        /**
         * @brief bitwise public interface implementation
         * @relates int16
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::bitwise<__impl<base_t>, zint16<base_t::capability>>;

        using impl = traits::bitwise<__impl<base_t>, zint16<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int16_bitwise_shift
    {

        /**
         * @brief bitwise_shift basic interface implementation
         * @relates int16
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief bitwise_shift default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vbsll(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vbsll");

                return zint16<base_t::capability> ({ one.get_value()[1] << other.get_value()[1], one.get_value()[0] << other.get_value()[0] });
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vbsrl(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vbsrl");

                return zint16<base_t::capability> ({ one.get_value()[1] >> other.get_value()[1], one.get_value()[0] >> other.get_value()[0] });
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vbslli(const composed_t one, const size_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vbslli");

                return zint16<base_t::capability> ({ one.get_value()[1] << other, one.get_value()[0] << other });
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vbsrli(const composed_t one, const size_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vbsrli");

                return zint16<base_t::capability> ({ one.get_value()[1] >> other, one.get_value()[0] >> other });
            }

        };

        /**
         * @brief bitwise_shift public interface implementation
         * @relates int16
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::bitwise_shift<__impl<base_t>, zint16<base_t::capability>>;

        using impl = traits::bitwise_shift<__impl<base_t>, zint16<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int16_logical
    {

        /**
         * @brief logical basic interface implementation
         * @relates int16
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief logical default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vlneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vlneg");

                return zint16<base_t::capability> ({ !one.get_value()[1], !one.get_value()[1] });
            }


            /**
             * @brief logical default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vlor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vlor");

                return zint16<base_t::capability> ({ one.get_value()[1] || other.get_value()[1], one.get_value()[0] || other.get_value()[0] });
            }


            /**
             * @brief logical default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vland(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vland");

                return zint16<base_t::capability> ({ one.get_value()[1] && other.get_value()[1], one.get_value()[0] && other.get_value()[0] });
            }

        };

        /**
         * @brief logical public interface implementation
         * @relates int16
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::logical<__impl<base_t>, bint16<base_t::capability>>;

        using impl = traits::logical<__impl<base_t>, zint16<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int16_comparison
    {

        /**
         * @brief comparison basic interface implementation
         * @relates int16
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> veq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "veq");

                return zint16<base_t::capability> ({ one.get_value()[1] == other.get_value()[1], one.get_value()[0] == other.get_value()[0] });
            }


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vneq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vneq");

                return zint16<base_t::capability> ({ one.get_value()[1] != other.get_value()[1], one.get_value()[0] != other.get_value()[0] });
            }


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vgt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vgt");

                return zint16<base_t::capability> ({ one.get_value()[1] > other.get_value()[1], one.get_value()[0] > other.get_value()[0] });
            }


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vlt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vlt");

                return zint16<base_t::capability> ({ one.get_value()[1] < other.get_value()[1], one.get_value()[0] < other.get_value()[0] });
            }


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vge(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vge");

                return zint16<base_t::capability> ({ one.get_value()[1] >= other.get_value()[1], one.get_value()[0] >= other.get_value()[0] });
            }


            /**
             * @brief comparison default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vle(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vle");

                return zint16<base_t::capability> ({ one.get_value()[1] <= other.get_value()[1], one.get_value()[0] <= other.get_value()[0] });
            }

        };

        /**
         * @brief comparison public interface implementation
         * @relates int16
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::comparison<__impl<base_t>, zint16<base_t::capability>>;

        using impl = traits::comparison<__impl<base_t>, zint16<base_t::capability>>;

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
     * @remark avx
     */
    template<typename composed_t>
    struct int16_conditional
    {

        /**
         * @brief conditional basic interface implementation
         * @relates int16
         * @remark avx
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief conditional default branch
             * @relates int16
             * @remark avx - default
             */
            friend zint16<base_t::capability> vsel(composed_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE_BACKEND("avx.int16.impl", __LINE__, "zint16(int16_t[16])", "default", "vsel");

                return zint16<base_t::capability> ({ vsel(condition.get_value()[1], if_value.get_value()[1], else_value.get_value()[1]), vsel(condition.get_value()[0], if_value.get_value()[0], else_value.get_value()[0]) });
            }

        };

        /**
         * @brief conditional public interface implementation
         * @relates int16
         * @remark avx
         */


        template<typename base_t>
        //using impl = traits::conditional<__impl<base_t>, zint16<base_t::capability>>;

        using impl = traits::conditional<__impl<base_t>, zint16<base_t::capability>>;

    };

    ///@}


    // Type composition ================================================================================================

    /**
     * @name int16 composition
     */
    ///@{

    //namespace composition {

        /**
         * @brief zval parametrization using
         * - 'std::array<sse::zint16<capability>, 2>' as underlying vector type
         * - 'int16_t' as scalar type
         * - '16' as vector size
         * - '32' as alignment
         * @relates int16
         * @remark avx
         */
        template<uint64_t capability>
        struct __zval_int16
        {
            using zval_t = zval<std::array<sse::zint16<capability>, 2>, std::array<sse::zint16<capability>, 2>, int16_t, 16, 32, capability>;

            struct impl : public zval_t
            {
                FORWARD2(impl, zval_t);
            };
        };
        /**
         * @brief zval composition
         * @relates int16
         * @remark avx
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

        template<uint64_t capability>
        struct __bint16
        {
            using bval_t = bval<typename __zint16<capability>::impl, std::array<sse::zint16<capability>, 2>>;
            struct impl : public bval_t
            {
                FORWARD2(impl, bval_t);
            };
        };
    //}

    template<uint64_t capability>
    struct zint16 : public /*composition::*/__zint16<capability>::impl
    {
        FORWARD2(zint16, /*composition::*/__zint16<capability>::impl);
    };

    template<uint64_t capability>
    struct bint16 : public /*composition::*/__bint16<capability>::impl
    {
        FORWARD2(bint16, /*composition::*/__bint16<capability>::impl);
    };

    static_assert(is_zval<zint16<0>>::value, "is_zval for zint16 failed.");
    static_assert(is_bval<bint16<0>>::value, "is_bval for bint16 failed.");

    static_assert(!is_floating_point<zint16<0>>::value, "is_floating_point for zint16 failed.");
    static_assert(is_integral<zint16<0>>::value, "is_integral for zint16 failed.");

    static_assert(!is_float<zint16<0>>::value, "is_float for zint16 failed.");
    static_assert(!is_double<zint16<0>>::value, "is_double for zint16 failed.");

    ///@}
}}