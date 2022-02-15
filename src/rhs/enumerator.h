#pragma once

#include <memory>
#include <vector>

#include "src/meet_map.h"
#include "src/rhs/number_generator.h"

namespace ramanujan::rhs {

using number_generator_t = std::unique_ptr<NumberGenerator>;

void enumerate(
    MeetMap& meet_map,
    const std::vector<number_generator_t>& a_gens,
    const std::vector<number_generator_t>& b_gens,
    size_t depth
);

} // namespace ramanujan::rhs
