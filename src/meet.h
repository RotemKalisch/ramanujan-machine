#pragma once

#include <numbers>
#include <vector>

#include "src/meet_map.h"
#include "src/lhs/enumerator.h"
#include "src/rhs/number_generator.h"

namespace ramanujan {

static const std::vector<lhs::const_t> const_pairs = {
    std::pair(std::numbers::pi, "pi"),
    std::pair(std::numbers::e, "e"),
    std::pair(std::numbers::log2e, "log2"),
    std::pair(std::numbers::ln2, "ln2"),
    std::pair(std::numbers::sqrt2, "sqrt2"),
    std::pair(std::numbers::sqrt3, "sqrt3")
};

std::vector<rhs::number_generator_t> create_generators();

void load(MeetMap& meet_map);
void meet(
    MeetMap& meet_map,
    const std::vector<rhs::number_generator_t>& a_gens,
    const std::vector<rhs::number_generator_t>& b_gens
);

} // namespace ramanujan
