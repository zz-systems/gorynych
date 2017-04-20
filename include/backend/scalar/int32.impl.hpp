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
#include "traits/arithmetic.hpp"
#include "traits/bitwise.hpp"
#include "traits/bitwise_shift.hpp"
#include "traits/logical.hpp"
#include "traits/comparison.hpp"
#include "traits/conditional.hpp"

/**
 * @brief int32 implementation for the scalar branch
 * provides unified access to 1 'int32_t' values
 */

namespace zacc { namespace scalar {

    // =================================================================================================================
    /**
     * @name construction operations
     */
    ///@{

    /**
     * @brief construction
     * @relates int32
     * @remark scalar
     */
    template<typename composed_t>
    struct int32_construction
    {

        /**
         * @brief construction basic interface implementation
         * @relates int32
         * @remark scalar
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;



            /**
             * @brief construction default branch
             * @relates int32
             * @remark scalar - default
             */
            __impl() : base_t() {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "CONS()");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark scalar - default
             */
            __impl(int32_t value) : base_t(value) {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "CONS(int32_t value)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark scalar - default
             */
            template <typename T, typename enable = std::enable_if_t<std::is_base_of<zval_base, T>::value, T>> __impl(const T &value) : base_t(value.get_value()) {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "CONS(const T &value)");

            }


            /**
             * @brief construction default branch
             * @relates int32
             * @remark scalar - default
             */
            __impl(int32_t *value) : base_t(*value) {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "CONS(int32_t *value)");

            }

        };

        /**
         * @brief construction public interface implementation
         * @relates int32
         * @remark scalar
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
     * @remark scalar
     */
    template<typename composed_t>
    struct int32_io
    {

        /**
         * @brief io basic interface implementation
         * @relates int32
         * @remark scalar
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief io default branch
             * @relates int32
             * @remark scalar - default
             */
            friend void vstore(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vstore");

                target.data()[0] = source.get_value();
            }


            /**
             * @brief io default branch
             * @relates int32
             * @remark scalar - default
             */
            friend void vstream(typename base_t::extracted_t &target, composed_t source)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vstream");

                target.data()[0] = source.get_value();
            }

        };

        /**
         * @brief io public interface implementation
         * @relates int32
         * @remark scalar
         */
        template<typename base_t>
        using impl = interface::io<__impl<base_t>, composed_t>;
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
     * @remark scalar
     */
    template<typename composed_t>
    struct int32_numeric
    {

        /**
         * @brief numeric basic interface implementation
         * @relates int32
         * @remark scalar
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
         * @remark scalar
         */
        template<typename base_t>
        using impl = interface::numeric<__impl<base_t>, composed_t>;
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
     * @remark scalar
     */
    template<typename composed_t>
    struct int32_arithmetic
    {

        /**
         * @brief arithmetic basic interface implementation
         * @relates int32
         * @remark scalar
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vneg");

                return (-one.get_value());
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vadd(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vadd");

                return (one.get_value() + other.get_value());
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vsub(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vsub");

                return (one.get_value() - other.get_value());
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vmul(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vmul");

                return (one.get_value() * other.get_value());
            }


            /**
             * @brief arithmetic default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vdiv(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vdiv");

                return (one.get_value() / other.get_value());
            }

        };

        /**
         * @brief arithmetic public interface implementation
         * @relates int32
         * @remark scalar
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
     * @remark scalar
     */
    template<typename composed_t>
    struct int32_bitwise
    {

        /**
         * @brief bitwise basic interface implementation
         * @relates int32
         * @remark scalar
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vbneg(composed_t one)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vbneg");

                return (~one.get_value());
            }


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vband(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vband");

                return (one.get_value() & other.get_value());
            }


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vbor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vbor");

                return (one.get_value() | other.get_value());
            }


            /**
             * @brief bitwise default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vbxor(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vbxor");

                return (one.get_value() ^ other.get_value());
            }

        };

        /**
         * @brief bitwise public interface implementation
         * @relates int32
         * @remark scalar
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
     * @remark scalar
     */
    template<typename composed_t>
    struct int32_bitwise_shift
    {

        /**
         * @brief bitwise_shift basic interface implementation
         * @relates int32
         * @remark scalar
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief bitwise_shift default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vbsll(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vbsll");

                return (one.get_value() << other.get_value());
            }


            /**
             * @brief bitwise_shift default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vbsrl(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vbsrl");

                return (one.get_value() >> other.get_value());
            }

        };

        /**
         * @brief bitwise_shift public interface implementation
         * @relates int32
         * @remark scalar
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
     * @remark scalar
     */
    template<typename composed_t>
    struct int32_logical
    {

        /**
         * @brief logical basic interface implementation
         * @relates int32
         * @remark scalar
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief logical default branch
             * @relates int32
             * @remark scalar - default
             */
            friend bval<composed_t, mask_t> vlneg(bval<composed_t, mask_t> one)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vlneg");

                return (!one.get_value());
            }


            /**
             * @brief logical default branch
             * @relates int32
             * @remark scalar - default
             */
            friend bval<composed_t, mask_t> vlor(bval<composed_t, mask_t> one, bval<composed_t, mask_t> other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vlor");

                return (one.get_value() || other.get_value());
            }


            /**
             * @brief logical default branch
             * @relates int32
             * @remark scalar - default
             */
            friend bval<composed_t, mask_t> vland(bval<composed_t, mask_t> one, bval<composed_t, mask_t> other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vland");

                return (one.get_value() && other.get_value());
            }

        };

        /**
         * @brief logical public interface implementation
         * @relates int32
         * @remark scalar
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
     * @remark scalar
     */
    template<typename composed_t>
    struct int32_comparison
    {

        /**
         * @brief comparison basic interface implementation
         * @relates int32
         * @remark scalar
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark scalar - default
             */
            friend bval<composed_t, mask_t> veq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "veq");

                return (one.get_value() == other.get_value());
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark scalar - default
             */
            friend bval<composed_t, mask_t> vneq(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vneq");

                return (one.get_value() != other.get_value());
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark scalar - default
             */
            friend bval<composed_t, mask_t> vgt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vgt");

                return (one.get_value() > other.get_value());
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark scalar - default
             */
            friend bval<composed_t, mask_t> vlt(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vlt");

                return (one.get_value() < other.get_value());
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark scalar - default
             */
            friend bval<composed_t, mask_t> vge(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vge");

                return (one.get_value() >= other.get_value());
            }


            /**
             * @brief comparison default branch
             * @relates int32
             * @remark scalar - default
             */
            friend bval<composed_t, mask_t> vle(composed_t one, composed_t other)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vle");

                return (one.get_value() <= other.get_value());
            }

        };

        /**
         * @brief comparison public interface implementation
         * @relates int32
         * @remark scalar
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
     * @remark scalar
     */
    template<typename composed_t>
    struct int32_conditional
    {

        /**
         * @brief conditional basic interface implementation
         * @relates int32
         * @remark scalar
         */
        template<typename base_t>
        struct __impl : base_t
        {
            using mask_t = typename base_t::mask_t;

            FORWARD(__impl);


            /**
             * @brief conditional default branch
             * @relates int32
             * @remark scalar - default
             */
            friend composed_t vsel(composed_t condition, composed_t if_value, composed_t else_value)  noexcept {

                ZTRACE_BACKEND("scalar.int32.impl", __LINE__, "zint32(int32_t[1])", "default", "vsel");

                return (condition.get_value() != 0 ? if_value : else_value);
            }

        };

        /**
         * @brief conditional public interface implementation
         * @relates int32
         * @remark scalar
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
     * - 'int32_t' as underlying vector type
     * - 'int32_t' as scalar type
     * - '1' as vector size
     * - '8' as alignment
     * @relates int32
     * @remark scalar
     */
    template<uint64_t capability>
    struct __zval_int32
    {
        using zval_t = zval<int32_t, bool, int32_t, 1, 8, capability>;

        struct impl : public zval_t
        {
            FORWARD2(impl, zval_t);
        };
    };
    /**
     * @brief zval composition
     * @relates int32
     * @remark scalar
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

    template<uint64_t capability = 0xFFFF'FFFF'FFFF'FFFF>
    using zint32 = typename __zint32<capability>::impl;

    ///@}
}}