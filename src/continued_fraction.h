#pragma once

#include <algorithm>

#include "src/generator.h"

namespace ramanujan {

template <Generator A, Generator B>
class ContinuedFraction {
public:
    ContinuedFraction(A a, B b) : m_a(std::move(a)), m_b(std::move(b)) {}

    double operator()(size_t depth) {
        double result = 0;
        std::vector<coef_t> a, b;
        a.reserve(depth);
        b.reserve(depth);
        for (size_t i = 0; i <= std::max(1UL, depth); ++i) {
            a.push_back(m_a());
            b.push_back(m_b());
        }
        for (size_t i = depth; i > 0; --i) {
            result = b[i] / (a[i] + result);
        }
        result += a[0];
        m_a.reset();
        m_b.reset();
        return result;
    }

private:
    A m_a;
    B m_b;
};

} // namespace ramanujan
