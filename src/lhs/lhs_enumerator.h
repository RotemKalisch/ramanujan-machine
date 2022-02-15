#pragma once

#include "src/rhs/number_generator.h"
#include "src/meet_map.h"

namespace ramanujan::lhs {

void enumerate(
    MeetMap& meet_map,
    double constant,
    const std::string& constant_name,
    coef_t threshold
);

} // namespace ramanujan::lhs
