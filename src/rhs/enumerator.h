#pragma once

#include <memory>
#include <vector>

#include "src/meet_map.h"
#include "src/rhs/number_generator.h"

namespace ramanujan::rhs {

using number_generators_t = std::vector<std::unique_ptr<NumberGenerator>>;

void enumerate(
    MeetMap& meet_map,
    const number_generators_t& a_gens,
    const number_generators_t& b_gens,
    size_t depth
);

} // namespace ramanujan::rhs
