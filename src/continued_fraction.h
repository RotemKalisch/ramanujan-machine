#pragma once

#include "src/polynomial.h"

namespace ramanujan {

class ContinuedFraction {
public:
    ContinuedFraction(Polynomial a, Polynomial b);
    double operator()(size_t depth);

private:
    Polynomial m_a;
    Polynomial m_b;
};

} // namespace ramanujan
