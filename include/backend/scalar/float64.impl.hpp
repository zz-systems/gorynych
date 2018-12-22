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

/**
 * @file float64.impl.hpp
 * @brief
 * This file provides defines required components and logic for float64 scalar target.
 * Provides unified access to 1 'double' values
 * @remark
 * This is an autogenerated file. Changes will be lost on regeneration.
 */
#pragma once

#include <type_traits>
#include <cmath>

#include "backend/intrin.hpp"
#include "backend/zval.hpp"
#include "backend/zval_interface.hpp"

#include "util/type/type_composition.hpp"
#include "util/type/type_traits.hpp"

#include "util/memory.hpp"
#include "util/macros.hpp"

#include "traits/convertable.hpp"
#include "traits/printable.hpp"
#include "traits/io.hpp"
#include "traits/logical.hpp"
#include "traits/math.hpp"
#include "traits/numeric.hpp"
#include "traits/arithmetic.hpp"
#include "traits/comparable.hpp"
#include "traits/conditional.hpp"
#include "traits/equatable.hpp"
#include "traits/bitwise.hpp"

namespace zacc { namespace backend { namespace scalar
{
    /// @cond
    template<uint64_t features>
    struct bfloat64;

    template<uint64_t features>
    struct zfloat64;
    /// @endcond
    
    template<uint64_t FeatureMask>
    using izfloat64 = ztype<zval_tag, std::array<double, 1>, std::array<bool, 1>, double, 1, 16, FeatureMask>;

    template<uint64_t FeatureMask>
    using ibfloat64 = ztype<bval_tag, std::array<double, 1>, std::array<bool, 1>, double, 1, 16, FeatureMask>;
}}}

namespace zacc {

    /**
     * @brief ztraits type trait specialization for float64 [scalar branch]
     * @tparam T
     */
    template<typename T>
    struct ztraits<T, std::enable_if_t<
            std::is_base_of<backend::scalar::izfloat64<T::feature_mask>, T>::value
            || std::is_base_of<backend::scalar::ibfloat64<T::feature_mask>, T>::value>>
    {
        /// vector size (1 - scalar, 4, 8, 16, ...)
        static constexpr size_t size = 1;

        /// capabilities
        static constexpr uint64_t feature_mask = T::feature_mask;

        /// memory alignment
        static constexpr size_t alignment = 16;

        /// scalar type? vector type?
        static constexpr bool is_vector = size > 1;

        /// vector type, like __m128i for sse 4x integer vector
        using vector_type = std::array<double, 1>;

        /// scalar type, like int for sse 4x integer vector
        using element_type = double;

        /// mask type for boolean operations
        using mask_vector_type = std::array<bool, 1>;

        /// extracted std::array of (dim) scalar values
        using extracted_type = std::array<element_type, size>;

        using zval_t = backend::scalar::zfloat64<T::feature_mask>;
        using bval_t = backend::scalar::bfloat64<T::feature_mask>;

        using tag = select_t<
            when<std::is_base_of<backend::scalar::izfloat64<T::feature_mask>, T>::value, zval_tag>,
            when<std::is_base_of<backend::scalar::ibfloat64<T::feature_mask>, T>::value, bval_tag>>;
    };
}

namespace zacc { namespace backend { namespace scalar
{
    namespace float64_modules
    {
        /**
         * @brief io mixin implementation [scalar branch]
         * @relates float64
         */
        template<typename Interface, typename Composed>
        struct io : traits::io<Interface, Composed, bfloat64<Interface::feature_mask>>
        {
            /**
             * @brief io [default branch]
             * @relates float64
             */
            template<typename OutputIt> friend void vstore(OutputIt result, Composed input) 
            {
                result[0] = input.value();
            }
            
            /**
             * @brief io [default branch]
             * @relates float64
             */
            template<typename OutputIt> friend void vstream(OutputIt result, Composed input) 
            {
                result[0] = input.value();
            }
            
            /**
             * @brief io [default branch]
             * @relates float64
             */
            template<typename RandomIt> friend zfloat64<Interface::feature_mask> vgather(RandomIt input, const zint32<Interface::feature_mask> &index,  Composed) 
            {
                return input[index.value()];
            }
        };

        // =============================================================================================================

        /**
         * @brief math mixin implementation [scalar branch]
         * @relates float64
         */
        template<typename Interface, typename Composed>
        struct math : traits::math<Interface, Composed, bfloat64<Interface::feature_mask>>
        {
            /**
             * @brief math [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vabs(Composed one) 
            {
                return std::abs(one.value());
            }
            
            /**
             * @brief math [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vmin(Composed one, Composed other) 
            {
                return std::min(one.value(), other.value());
            }
            
            /**
             * @brief math [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vmax(Composed one, Composed other) 
            {
                return std::max(one.value(), other.value());
            }
            
            /**
             * @brief math [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vclamp(Composed self, Composed from, Composed to) 
            {
                return vmin(to, vmax(from, self));
            }
            
            /**
             * @brief math [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vrcp(Composed one) 
            {
                return (1 / one.value());
            }
            
            /**
             * @brief math [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vtrunc(Composed one) 
            {
                return std::trunc(one.value());
            }
            
            /**
             * @brief math [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vfloor(Composed one) 
            {
                return std::floor(one.value());
            }
            
            /**
             * @brief math [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vceil(Composed one) 
            {
                return std::ceil(one.value());
            }
            
            /**
             * @brief math [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vround(Composed one) 
            {
                return std::round(one.value());
            }
            
            /**
             * @brief math [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vsqrt(Composed one) 
            {
                return std::sqrt(one.value());
            }
        };

        // =============================================================================================================

        /**
         * @brief numeric mixin implementation [scalar branch]
         * @relates float64
         */
        template<typename Interface, typename Composed>
        struct numeric : traits::numeric<Interface, Composed, bfloat64<Interface::feature_mask>>
        {
        };

        // =============================================================================================================

        /**
         * @brief arithmetic mixin implementation [scalar branch]
         * @relates float64
         */
        template<typename Interface, typename Composed>
        struct arithmetic : traits::arithmetic<Interface, Composed, bfloat64<Interface::feature_mask>>
        {
            /**
             * @brief arithmetic [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vneg(Composed one) 
            {
                return (-one.value());
            }
            
            /**
             * @brief arithmetic [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vadd(Composed one, Composed other) 
            {
                return (one.value() + other.value());
            }
            
            /**
             * @brief arithmetic [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vsub(Composed one, Composed other) 
            {
                return (one.value() - other.value());
            }
            
            /**
             * @brief arithmetic [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vmul(Composed one, Composed other) 
            {
                return (one.value() * other.value());
            }
            
            /**
             * @brief arithmetic [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vdiv(Composed one, Composed other) 
            {
                return (one.value() / other.value());
            }
            
            /**
             * @brief arithmetic [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vfmadd(Composed multiplicand, Composed multiplier, Composed addendum) 
            {
                return multiplicand.value() * multiplier.value() + addendum.value();
            }
            
            /**
             * @brief arithmetic [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vfmsub(Composed multiplicand, Composed multiplier, Composed addendum) 
            {
                return multiplicand.value() * multiplier.value() - addendum.value();
            }
        };

        // =============================================================================================================

        /**
         * @brief bitwise mixin implementation [scalar branch]
         * @relates float64
         */
        template<typename Interface, typename Composed>
        struct bitwise : traits::bitwise<Interface, Composed, bfloat64<Interface::feature_mask>>
        {
            /**
             * @brief bitwise [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vbneg(Composed one) 
            {
                auto _one = one.value();
                double result;
                bitsof(result) = ~bitsof(_one);
                return result;
            }
            
            /**
             * @brief bitwise [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vband(Composed one, Composed other) 
            {
                auto _one = one.value();
                auto _other = other.value();
                double result;
                bitsof(result) = bitsof(_one) & bitsof(_other);
                return result;
            }
            
            /**
             * @brief bitwise [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vbor(Composed one, Composed other) 
            {
                auto _one = one.value();
                auto _other = other.value();
                double result;
                bitsof(result) = bitsof(_one) | bitsof(_other);
                return result;
            }
            
            /**
             * @brief bitwise [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vbxor(Composed one, Composed other) 
            {
                auto _one = one.value();
                auto _other = other.value();
                double result;
                bitsof(result) = bitsof(_one) ^ bitsof(_other);
                return result;
            }
            
            /**
             * @brief bitwise [default branch]
             * @relates float64
             */
            friend bool is_set(Composed one) 
            {
                return one.value() != 0;
            }
        };

        // =============================================================================================================

        /**
         * @brief comparable mixin implementation [scalar branch]
         * @relates float64
         */
        template<typename Interface, typename Composed>
        struct comparable : traits::comparable<Interface, Composed, bfloat64<Interface::feature_mask>>
        {
            /**
             * @brief comparable [default branch]
             * @relates float64
             */
            friend bfloat64<Interface::feature_mask> vgt(Composed one, Composed other) 
            {
                return (one.value() > other.value());
            }
            
            /**
             * @brief comparable [default branch]
             * @relates float64
             */
            friend bfloat64<Interface::feature_mask> vlt(Composed one, Composed other) 
            {
                return (one.value() < other.value());
            }
            
            /**
             * @brief comparable [default branch]
             * @relates float64
             */
            friend bfloat64<Interface::feature_mask> vge(Composed one, Composed other) 
            {
                return (one.value() >= other.value());
            }
            
            /**
             * @brief comparable [default branch]
             * @relates float64
             */
            friend bfloat64<Interface::feature_mask> vle(Composed one, Composed other) 
            {
                return (one.value() <= other.value());
            }
        };

        // =============================================================================================================

        /**
         * @brief logical mixin implementation [scalar branch]
         * @relates float64
         */
        template<typename Interface, typename Composed>
        struct logical : traits::logical<Interface, Composed, bfloat64<Interface::feature_mask>>
        {
            /**
             * @brief logical [default branch]
             * @relates float64
             */
            friend bfloat64<Interface::feature_mask> vlneg(Composed one) 
            {
                return (!one.value());
            }
            
            /**
             * @brief logical [default branch]
             * @relates float64
             */
            friend bfloat64<Interface::feature_mask> vlor(Composed one, Composed other) 
            {
                return (one.value() || other.value());
            }
            
            /**
             * @brief logical [default branch]
             * @relates float64
             */
            friend bfloat64<Interface::feature_mask> vland(Composed one, Composed other) 
            {
                return (one.value() && other.value());
            }
        };

        // =============================================================================================================

        /**
         * @brief equatable mixin implementation [scalar branch]
         * @relates float64
         */
        template<typename Interface, typename Composed>
        struct equatable : traits::equatable<Interface, Composed, bfloat64<Interface::feature_mask>>
        {
            /**
             * @brief equatable [default branch]
             * @relates float64
             */
            friend bfloat64<Interface::feature_mask> veq(Composed one, Composed other) 
            {
                return (one.value() == other.value());
            }
            
            /**
             * @brief equatable [default branch]
             * @relates float64
             */
            friend bfloat64<Interface::feature_mask> vneq(Composed one, Composed other) 
            {
                return (one.value() != other.value());
            }
        };

        // =============================================================================================================

        /**
         * @brief conditional mixin implementation [scalar branch]
         * @relates float64
         */
        template<typename Interface, typename Composed>
        struct conditional : traits::conditional<Interface, Composed, bfloat64<Interface::feature_mask>>
        {
            /**
             * @brief conditional [default branch]
             * @relates float64
             */
            friend zfloat64<Interface::feature_mask> vsel(bfloat64<Interface::feature_mask> condition, Composed if_value, Composed else_value) 
            {
                return (condition.value() ? if_value : else_value);
            }
        };
    } // end float64_modules

    // =================================================================================================================

    /// public zfloat64 implementation [scalar branch]
    /// @tparam FeatureMask feature mask
    template<uint64_t FeatureMask>
    struct zfloat64 : public zval<izfloat64<FeatureMask>>,

        // generic traits
        printable<izfloat64<FeatureMask>, zfloat64<FeatureMask>>,
        convertable<izfloat64<FeatureMask>, zfloat64<FeatureMask>>,

        // float64 traits
        float64_modules::io<izfloat64<FeatureMask>, zfloat64<FeatureMask>>,
        float64_modules::math<izfloat64<FeatureMask>, zfloat64<FeatureMask>>,
        float64_modules::numeric<izfloat64<FeatureMask>, zfloat64<FeatureMask>>,
        float64_modules::arithmetic<izfloat64<FeatureMask>, zfloat64<FeatureMask>>,
        float64_modules::bitwise<izfloat64<FeatureMask>, zfloat64<FeatureMask>>,
        float64_modules::comparable<izfloat64<FeatureMask>, zfloat64<FeatureMask>>,
        float64_modules::logical<izfloat64<FeatureMask>, zfloat64<FeatureMask>>,
        float64_modules::equatable<izfloat64<FeatureMask>, zfloat64<FeatureMask>>,
        float64_modules::conditional<izfloat64<FeatureMask>, zfloat64<FeatureMask>>
    {
        USING_ZTYPE(izfloat64<FeatureMask>);

        /// complete vector
        using zval_t = zfloat64<FeatureMask>;

        /// complete boolean vector
        using bval_t = bfloat64<FeatureMask>;

        /**
         * Copy constructor, forwards to base implementation
         * @tparam T any type convertable to std::array<double, 1>
         * @param other
         */
        template<typename T, typename = std::enable_if_t<std::is_convertible<T, std::array<double, 1>>::value>>
        constexpr zfloat64(const T& other) noexcept
            : zval<izfloat64<FeatureMask>>(other)
        {}

        /**
         * Move constructor, forwards to base implementation
         * @tparam T any type convertable to std::array<double, 1>
         * @param other
         */
        template<typename T, typename = std::enable_if_t<(size > 1) && std::is_convertible<T, std::array<double, 1>>::value>>
        constexpr zfloat64(T&& other) noexcept
            : zval<izfloat64<FeatureMask>>(std::forward<T>(other))
        {}

        /**
         * Converting constructor from bfloat64, forwards to base implementation 
         * @param other
         */
        constexpr zfloat64(const bfloat64<FeatureMask>& other) noexcept
            : zval<izfloat64<FeatureMask>>(other.value())
        {}

        /**
         * @brief zfloat64 constructor [scalar branch]
         * @relates zfloat64
         */
        constexpr zfloat64(  ) noexcept
            : zval<izfloat64<FeatureMask>>()
        {
        }

        /**
         * @brief zfloat64 constructor [scalar branch]
         * @relates zfloat64
         */
        constexpr zfloat64(double value) noexcept
            : zval<izfloat64<FeatureMask>>(value)
        {
        }

        /**
         * @brief zfloat64 constructor [scalar branch]
         * @relates zfloat64
         */
        constexpr zfloat64(extracted_type value) noexcept
            : zval<izfloat64<FeatureMask>>(value[0])
        {
        }
    };

    // =================================================================================================================

    /// public bfloat64 implementation [scalar branch]
    /// @tparam FeatureMask feature mask
    template<uint64_t FeatureMask>
    struct bfloat64 : public bval<ibfloat64<FeatureMask>>,

        // generic traits
        printable<bfloat64<FeatureMask>, bfloat64<FeatureMask>>,
        convertable<bfloat64<FeatureMask>, bfloat64<FeatureMask>>,

        // float64 traits
        float64_modules::io<ibfloat64<FeatureMask>, bfloat64<FeatureMask>>,
        float64_modules::math<ibfloat64<FeatureMask>, bfloat64<FeatureMask>>,
        float64_modules::numeric<ibfloat64<FeatureMask>, bfloat64<FeatureMask>>,
        float64_modules::arithmetic<ibfloat64<FeatureMask>, bfloat64<FeatureMask>>,
        float64_modules::bitwise<ibfloat64<FeatureMask>, bfloat64<FeatureMask>>,
        float64_modules::comparable<ibfloat64<FeatureMask>, bfloat64<FeatureMask>>,
        float64_modules::logical<ibfloat64<FeatureMask>, bfloat64<FeatureMask>>,
        float64_modules::equatable<ibfloat64<FeatureMask>, bfloat64<FeatureMask>>,
        float64_modules::conditional<ibfloat64<FeatureMask>, bfloat64<FeatureMask>>
    {
        USING_ZTYPE(ibfloat64<FeatureMask>);

        /// complete vector
        using zval_t = zfloat64<FeatureMask>;

        /// complete boolean vector
        using bval_t = bfloat64<FeatureMask>;

        /// Forwarding constructor
        FORWARD2(bfloat64, bval<ibfloat64<FeatureMask>>);

    };

    // Validate zfloat64 ===================================================================================

    static_assert( std::is_base_of<izfloat64<0>, izfloat64<0>>::value, "base_of<izfloat64> != izfloat64.");
    static_assert(!std::is_base_of<ibfloat64<0>, izfloat64<0>>::value, "base_of<izfloat64> == ibfloat64.");

    static_assert( is_zval<izfloat64<0>>::value, "is_zval<izfloat64> == false.");
    static_assert(!is_bval<izfloat64<0>>::value, "is_bval<izfloat64> != false.");

    static_assert( std::is_base_of<izfloat64<0>, zfloat64<0>>::value, "base_of<zfloat64> != izfloat64.");
    static_assert(!std::is_base_of<ibfloat64<0>, zfloat64<0>>::value, "base_of<zfloat64> == ibfloat64.");

    static_assert(zfloat64<0>::size == 1, "zfloat64::size != 1.");
    static_assert(zfloat64<0>::alignment == 16, "zfloat64::alignment != 16.");
    static_assert(zfloat64<0>::is_vector == false, "zfloat64::is_vector != false.");

    static_assert(std::is_same<zfloat64<0>::tag, zval_tag>::value, "zfloat64::tag != zval_tag.");
    static_assert(std::is_same<zfloat64<0>::vector_type, std::array<double, 1>>::value, "zfloat64::vector_type != std::array<double, 1>.");
    static_assert(std::is_same<zfloat64<0>::element_type, double>::value, "zfloat64::element_type != double.");
    static_assert(std::is_same<zfloat64<0>::mask_vector_type, std::array<bool, 1>>::value, "zfloat64::mask_vector_type != std::array<bool, 1>.");
    static_assert(std::is_same<zfloat64<0>::extracted_type, std::array<double, 1>>::value, "zfloat64::extracted_type != std::array<double, 1>.");

    static_assert( is_zval<zfloat64<0>>::value, "is_zval<zfloat64> == false.");
    static_assert(!is_bval<zfloat64<0>>::value, "is_bval<zfloat64> != false.");

    // Validate bfloat64 ===================================================================================

    static_assert( std::is_base_of<ibfloat64<0>, ibfloat64<0>>::value, "base_of<izfloat64> != izfloat64.");
    static_assert(!std::is_base_of<izfloat64<0>, ibfloat64<0>>::value, "base_of<izfloat64> == ibfloat64.");

    static_assert( is_bval<ibfloat64<0>>::value, "is_bval<ibfloat64> == false.");
    static_assert(!is_zval<ibfloat64<0>>::value, "is_zval<ibfloat64> != false.");

    static_assert( std::is_base_of<ibfloat64<0>, bfloat64<0>>::value, "base_of<bfloat64> != ibfloat64.");
    static_assert(!std::is_base_of<izfloat64<0>, bfloat64<0>>::value, "base_of<bfloat64> == izfloat64.");

    static_assert(bfloat64<0>::size == 1, "bfloat64::size != 1.");
    static_assert(bfloat64<0>::alignment == 16, "bfloat64::alignment != 16.");
    static_assert(bfloat64<0>::is_vector == false, "bfloat64::is_vector != false.");

    static_assert(std::is_same<bfloat64<0>::tag, bval_tag>::value, "bfloat64::tag != zval_tag.");
    static_assert(std::is_same<bfloat64<0>::vector_type, std::array<double, 1>>::value, "bfloat64::vector_type != std::array<double, 1>.");
    static_assert(std::is_same<bfloat64<0>::element_type, double>::value, "bfloat64::element_type != double.");
    static_assert(std::is_same<bfloat64<0>::mask_vector_type, std::array<bool, 1>>::value, "bfloat64::mask_vector_type != std::array<bool, 1>.");
    static_assert(std::is_same<bfloat64<0>::extracted_type, std::array<double, 1>>::value, "bfloat64::extracted_type != std::array<double, 1>.");

    static_assert( is_bval<bfloat64<0>>::value, "is_bval<bfloat64> == false.");
    static_assert(!is_zval<bfloat64<0>>::value, "is_zval<bfloat64> != false.");

    // Validate integral, float, double traits =========================================================================

    static_assert(!std::is_floating_point<double>::value || is_floating_point < zfloat64<0>>::value, "is_floating_point<zfloat64> == false. [scalar = double]");
    static_assert(!std::is_floating_point<double>::value || !is_integral<zfloat64<0>>::value, "is_integral<zfloat64> != false. [scalar = double]");

    static_assert(!std::is_same<double, float>::value || is_float < zfloat64<0>>::value, "is_float<zfloat64> == false. [scalar = double]");
    static_assert(!std::is_same<double, float>::value || !is_double < zfloat64<0>>::value, "is_double<zfloat64> != false. [scalar = double]");

    static_assert(!std::is_same<double, double>::value || is_double < zfloat64<0>>::value, "is_double<zfloat64> == false. [scalar = double]");
    static_assert(!std::is_same<double, double>::value || !is_float < zfloat64<0>>::value, "is_float<zfloat64> != false. [scalar = double]");

    static_assert(!std::is_integral<double>::value || is_integral<zfloat64<0>>::value,"is_integral<zfloat64> == false. [scalar = double]");
    static_assert(!std::is_integral<double>::value || !is_floating_point < zfloat64<0>>::value, "is_floating_point<zfloat64> != false. [scalar = double]");
}}}