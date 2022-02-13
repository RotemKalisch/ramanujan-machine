#include "src/continued_fraction.h"

namespace ramanujan {

ContinuedFraction::ContinuedFraction(Polynomial a, Polynomial b) :
    m_a(std::move(a)), m_b(std::move(b)) {}

double ContinuedFraction::operator()(size_t depth) {
    double result = 0;
    for (size_t i = depth; i >= 1; --i) {
        result = m_b(i) / (m_a(i) + result);
    }
    result += m_a(0);
    return result;
}

} // namespace ramanujan
