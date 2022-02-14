#pragma once

#include <algorithm>

#include "src/rhs/generator.h"

namespace ramanujan {

template <Generator A, Generator B>
double calculate_continued_fraction(const A& a, const B& b, size_t depth) {
    a.reset();
    b.reset();
    double result = 0;
    std::vector<coef_t> a_results, b_results;
    a_results.reserve(depth);
    b_results.reserve(depth);
    for (size_t i = 0; i <= std::max(1UL, depth); ++i) {
        a_results.push_back(a());
        b_results.push_back(b());
    }
    for (size_t i = depth; i > 0; --i) {
        result = b_results[i] / (a_results[i] + result);
    }
    result += a_results[0];
    return result;
}

} // namespace ramanujan
