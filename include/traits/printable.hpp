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


#include <sstream>
#include "util/macros.hpp"
#include "util/type/type_traits.hpp"

namespace zacc {

//    /**
//     * @brief printable trait implementation. Provides pretty-print functionality for zacc types
//     */
//    template<typename Composed, typename Interface>
//    struct printable
//    {
//        /**
//         * @brief converts current data to string representation
//         * @return string, e.g [4, 5, 6, 7] for a 4x int vector
//         */
//        std::string to_string() const {
//            std::stringstream ss;
//
//            if (Interface::is_vector)
//                ss << "[ ";
//
//            for (auto entry : static_cast<Composed*>(this)->data())
//                ss << entry << " ";
//
//            if (Interface::is_vector)
//                ss << "]";
//
//            return ss.str();
//        }
//
//        /**
//         * @brief prints current value to target stream
//         * @param os target stream
//         * @param data printable trait
//         * @return target stream
//         */
//        friend std::ostream &operator<<(std::ostream &os, const printable &data) {
//            os << data.to_string();
//
//            return os;
//        }
//    };

    /**
     * @brief provides pretty-print functionality for zacc types
     */
    struct printable {
        /**
         * @brief printable trait implementation
         * @tparam Base base type (e.g previous trait)
         */
        template<typename Base>
        struct impl : public Base
        {
            FORWARD(impl);

            using zval_t = typename Base::zval_t;
            using bval_t = typename Base::bval_t;

            /**
             * @brief converts current data to string representation
             * @return string, e.g [4, 5, 6, 7] for a 4x int vector
             */
            std::string to_string() const {
                std::stringstream ss;

                if (Base::is_vector)
                    ss << "[ ";

                for (auto entry : Base::data())
                    ss << entry << " ";

                if (Base::is_vector)
                    ss << "]";

                return ss.str();
            }

            /**
             * @brief prints current value to target stream
             * @param os target stream
             * @param data printable trait
             * @return target stream
             */
            friend std::ostream &operator<<(std::ostream &os, const impl &data) {
                os << data.to_string();

                return os;
            }
        };
    };
}