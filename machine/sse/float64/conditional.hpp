//
// Created by Sergej Zuyev on 12/16/2016.
//

#pragma once

#include <smmintrin.h>
#include "../../../dispatch/dispatcher.hpp"

namespace zacc {
    namespace sse {
        namespace float64_policies {

            template<typename aggregate_t>
            struct conditional {
                template<typename base_t>
                struct if_policy;

                template<typename base_t, typename never_compose = void>
                struct else_policy {
                    //accept_if<aggregate_t, CAPABILITY_SSE41, CAPABILITY_SSE42>
                    aggregate_t
                    otherwise(const aggregate_t else_value) const {
                        return _mm_blendv_pd(_if_value.get_value(), else_value.get_value(),
                                             _mm_cmpeq_ps(_mm_setzero_ps(), _condition.get_value()));
                    }

                    //reject_if<aggregate_t, CAPABILITY_SSE41, CAPABILITY_SSE42>
                    //aggregate_t
                    //otherwise(const aggregate_t else_value) const
                    //{
                    //    return (_condition & _if_value) | (~_condition & else_value);
                    //}

                private:
                    else_policy(const aggregate_t mask, const aggregate_t if_value)
                            : _condition(mask), _if_value(if_value) {}

                    aggregate_t _if_value;
                    aggregate_t _condition;

                    friend struct if_policy<base_t>;
                };

                template<typename base_t>
                struct if_policy
                        : public base_t {
                    FORWARD(if_policy);

                    else_policy<base_t> when(const aggregate_t mask) const {
                        return else_policy<base_t>(mask, *this);
                    }
                };
            };
        }
    }
}