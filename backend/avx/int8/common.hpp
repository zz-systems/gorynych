//
// Created by Sergej Zuyev on 12/13/2016.
//

#pragma once

#include <immintrin.h>
#include <sstream>
#include "../../../common/compose.hpp"

namespace zacc {
    namespace avx {
        namespace int8_policies {

            template<typename aggregate_t>
            struct common {
                template<typename base_t>
                struct io_policy : public extractable<base_t> {
                    FORWARD2(io_policy, extractable < base_t >);

                    typedef typename base_t::extracted_type extracted_t;

                    void store(extracted_t &target) const {
                        _mm256_store_ps(target.data(), base_t::_value);
                    }

                    void stream(extracted_t &target) const {
                        _mm256_stream_ps(target.data(), base_t::_value);
                    }
                };
            };
        }
    }
}