#pragma once

#include "src/rhs/number_generator.h"

namespace ramanujan::rhs {

double calculate_continued_fraction(
    const NumberGenerator& a, const NumberGenerator& b, size_t depth
);

} // namespace ramanujan::rhs
