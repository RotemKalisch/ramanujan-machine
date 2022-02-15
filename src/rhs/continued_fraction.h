#pragma once

#include <optional>

#include "src/rhs/number_generator.h"

namespace ramanujan::rhs {

std::string print_continued_fraction(
    const NumberGenerator& a, const NumberGenerator& b
);

std::optional<double> calculate_continued_fraction(
    const NumberGenerator& a, const NumberGenerator& b, size_t depth
);

} // namespace ramanujan::rhs
