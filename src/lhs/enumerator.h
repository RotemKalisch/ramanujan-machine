#pragma once

#include "src/meet_map.h"

#include <string_view>
#include <utility>
#include <vector>

namespace ramanujan::lhs {

using const_t = std::pair<double, std::string_view>;

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
