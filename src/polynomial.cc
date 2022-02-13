#include "src/polynomial.h"

#include <math.h>

namespace ramanujan {

namespace detail {

coef_t pow(coef_t a, size_t b) {
    return static_cast<coef_t>(std::round(std::pow(a, b)));
}

} // namespace detail

Polynomial::Polynomial(std::vector<coef_t> coefs) :
    m_coefs(std::move(coefs)), m_degree(m_coefs.size()) {}

coef_t Polynomial::operator()(coef_t n) {
    coef_t res = 0;
    for (size_t i = 0; i < m_degree; ++i) {
        res += m_coefs[i] * detail::pow(n, i);
    }
    return res;
}

} // namespace ramanujan
