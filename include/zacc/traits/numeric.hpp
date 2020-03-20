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
#include <limits>
#include <zacc/util/operators.hpp>

namespace zacc { namespace traits {

    /**
     * @brief provides numeric value definitions, fluent interface
     * @tparam Base base type (e.g previous trait)
     * @tparam Composed final composed type (e.g zfloat32)
     */
    template<typename Interface, typename Composed, typename Boolean>
    struct numeric
    {

        constexpr auto self() const
        {
            return static_cast<const Composed*>(this);
        }

        /**
         * @brief NaN value
         * @see std::numeric_limits
         * @return NaN
         */
        static constexpr Composed quiet_NaN() noexcept {
            return std::numeric_limits<typename ztraits<Composed>::element_type>::quiet_NaN();
        };

        /**
         * @brief is the current value infinite?
         * @return true if infinite
         */
        Boolean is_infinite() const noexcept {
            return (*self()) == infinity();
        };

        /**
         * @brief infinity value
         * @see std::numeric_limits
         * @return infinity
         */
        static constexpr Composed infinity() noexcept {
            return std::numeric_limits<typename ztraits<Composed>::element_type>::infinity();
        };

        /**
         * @brief minimum value for current type
         * @see std::numeric_limits
         * @return minimum value
         */
        static constexpr Composed min_value() noexcept {
            return std::numeric_limits<typename ztraits<Composed>::element_type>::min();
        }

        /**
         * @brief maximum value for current type
         * @see std::numeric_limits
         * @return maximum value
         */
        static constexpr Composed max_value() noexcept {
            return std::numeric_limits<typename ztraits<Composed>::element_type>::max();
        }
    };
}}