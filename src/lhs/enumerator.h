#pragma once

#include "src/meet_map.h"

namespace ramanujan::lhs {

void enumerate(
    MeetMap& meet_map,
    double constant,
    const std::string& constant_name,
    int32_t threshold
);

} // namespace ramanujan::lhs
