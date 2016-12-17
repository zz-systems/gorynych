//
// Created by Sergej Zuyev on 12/13/2016.
//

#pragma once

#include <immintrin.h>

#include "../../../dispatch/dispatcher.hpp"
#include "../../../common/compose.hpp"

namespace zacc {
    namespace avx2 {
        namespace int32_policies {

            template<typename aggregate_t>
            struct arithmetic {

                template<typename base_t>
                struct negate_policy : public base_t {

                    FORWARD(negate_policy);

                    friend
                    aggregate_t
                    operator-(const aggregate_t one) {
                        return _mm256_sub_epi32(_mm256_setzero_si256(), one.get_value());
                    }
                };

                template<typename base_t>
                struct add_policy : public base_t {

                    FORWARD(add_policy);

                    friend
                    aggregate_t
                    operator+(const aggregate_t one, const aggregate_t other) {
                        return _mm256_add_epi32(one.get_value(), other.get_value());
                    }
                };

                template<typename base_t>
                struct sub_policy : public base_t {

                    FORWARD(sub_policy);

                    friend
                    aggregate_t
                    operator-(const aggregate_t one, const aggregate_t other) {
                        return _mm256_sub_epi32(one.get_value(), other.get_value());
                    }
                };

                template<typename base_t>
                struct mul_policy : public base_t {
                    FORWARD(mul_policy);

                    /**
                     * @brief integer multiplication (emulated). For machines without SSE4
                     * @see https://software.intel.com/en-us/forums/intel-c-compiler/topic/288768
                     * @param one left arg
                     * @param other right arg
                     * @return multiplication result
                     */
                    friend
                    aggregate_t//reject_if_t <aggregate_t, CAPABILITY_SSE41, CAPABILITY_SSE42>
                    operator*(const aggregate_t one, const aggregate_t other) {
                        /* mul 2,0*/
                        auto tmp1 = _mm256_castsi256_ps(_mm256_mul_epu32(one.get_value(), other.get_value()));
                        /* mul 3,1 */
                        auto tmp2 = _mm256_castsi256_ps(_mm256_mul_epu32(_mm256_srli_si256(one.get_value(), 4),
                                                                         _mm256_srli_si256(other.get_value(), 4)));

                        return _mm256_castps_si256(_mm256_shuffle_ps(tmp1, tmp2, _mm256_SHUFFLE(2, 0, 2, 0)));
                    }

                    /**
                     * @brief integer multiplication (native). For machines with SSE4
                     * @param one left arg
                     * @param other right arg
                     * @return multiplication result
                     */
                    //friend
                    //aggregate_t//accept_if_t <aggregate_t, CAPABILITY_SSE41, CAPABILITY_SSE42>
                    //operator*(const aggregate_t one, const aggregate_t other) {
                    //    return _mm256_mullo_epi32(one.get_value(), other.get_value());
                    //}
                };

                template<typename base_t>
                struct div_policy : public base_t {

                    FORWARD(div_policy);

                    friend
                    aggregate_t
                    operator/(const aggregate_t one, const aggregate_t other) {
                        return _mm256_div_ps(_mm256_cvtepi32_ps(one.get_value()),
                                             _mm256_cvtepi32_ps(other.get_value()));
                    }
                };
            };
        }
    }
}