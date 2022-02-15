#pragma once

#include "src/meet_map.h"

#include <numbers>
#include <string_view>
#include <utility>
#include <vector>

namespace ramanujan::lhs {

using const_t = std::pair<double, std::string_view>;

static const std::vector<const_t> const_pairs = {
    std::pair(std::numbers::pi, "pi"),
    std::pair(std::numbers::e, "e"),
    std::pair(std::numbers::log2e, "log2"),
    std::pair(std::numbers::ln2, "ln2"),
    std::pair(std::numbers::sqrt2, "sqrt2"),
    std::pair(std::numbers::sqrt3, "sqrt3")
};

void enumerate(
    MeetMap& meet_map,
    int32_t threshold,
    const std::vector<const_t>& const_pairs
);

void enumerate(
    MeetMap& meet_map,
    int32_t threshold,
    const const_t& const_pair
);

} // namespace ramanujan::lhs
