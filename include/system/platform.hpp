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

#include <vector>
#include <map>
#include <algorithm>

#include <type_traits>

#include "util/type/type_traits.hpp"
#include "util/algorithm.hpp"
#include "util/bithacks.hpp"

#include "cpuid.hpp"
#include "capabilities.hpp"


namespace zacc {

    /**
     * System and platform information.
     * Vital component of the dispatching mechanism
     */
    struct platform {
    private:
        using capability_map_t = std::map<const capabilities, arch>;

    public:

        using raw_t = std::underlying_type_t<capabilities>;

        /**
         * @brief Enable arch, fluent interface
         * @param arch
         * @return self
         */
        platform &enable(const capabilities arch);

        /**
         * @brief Disable arch, fluent interface
         * @param arch
         * @return self
         */
        platform &disable(const capabilities arch);

        /**
         * @brief Set arch, fluent interface
         * @param arch
         * @param enabled
         * @return self
         */
        platform &set(const capabilities arch, bool enabled);

        /**
         * @brief Set capabilities from raw value, fluent interface
         * @param raw_value
         * @return self
         */
        platform &set(raw_t raw_value);

        /**
         * @brief Checks if arch is set
         * @param arch
         * @return true if set, otherwise false
         */
        bool is_set(const capabilities arch) const;

        /**
         * @brief Get entire raw value with all capabilities
         * @return raw value
         */
        raw_t raw();

        /**
         * @brief Get enabled arch objects from raw representation
         * @return array of capabilities for each enabled arch
         */
        std::vector<arch> enabled_capabilities() const;

        /**
         * @brief Get all arch objects from raw representation
         * @return array of capabilities for each enabled arch
         */
        std::vector<arch> all_capabilities() const;

        /**
         * @brief Match runtime capabilities with requirement list
         * @return array of missing capabilities. Empty if conditions met.
         */
        std::vector<arch> match_capabilities(std::initializer_list<capabilities> required) const;

        /**
         * @brief Match runtime capabilities with raw requirement list (integer reporesentation)
         * @return array of missing capabilities. Empty if conditions met.
         */
        std::vector<arch> match_capabilities(raw_t required) const;

        /**
         * @brief Get all arch objects from raw representation
         * @return array of capabilities for each enabled arch
         */
        std::vector<arch> make_capabilities(raw_t value) const;

        /**
         * @brief Resolves platform information and populates capabilities, fluent interface
         * @return self
         */
        platform &reload();

        /**
         * @brief registers main capabilitiy metadata, fluent interface
         * @return self
         */
        platform& register_capabilities();

        /**
         * @brief registers a specified arch metadata, fluent interface
         * @param cap arch
         * @param str capabilitiy's string representation
         * @return self
         */
        platform & register_capability(const capabilities cap, const char* str);

        /**
         * @brief returns number of threads available on this machine
         */
        size_t num_threads();

        /**
         * @brief copy constructor not available
         */
        platform(platform const&)        = delete;

        /**
         * @brief returns the global instance
         * @return global instance
         */
        static platform& global();

        /**
         * @brief assignment operator not available
         */
        void operator=(platform const&)  = delete;

    private:
        raw_t _flags;

        capability_map_t _capabilities;

        static thread_local cpuid _cpuid;

        /**
         * @brief constructor
         * Fetches system information and populates main capabilities
         */
        platform();

        /**
         * @brief if the arch is registered, set the availability flag, fluent interface
         * @param cap arch
         * @param enabled availability flag
         * @return self
         */
        platform & set_capability_if_registered(capabilities cap, bool enabled);

        /**
         * @brief pretty-prints the currently supported features
         * @param os
         * @param cap
         * @return
         */
        friend std::ostream& operator<<(std::ostream& os, const platform& cap);
    };
}