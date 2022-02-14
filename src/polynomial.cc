#include "src/polynomial.h"

#include <math.h>
#include <sstream>

#include "src/utils.h"

namespace ramanujan {

namespace detail {

coef_t pow(coef_t a, size_t b) {
    return static_cast<coef_t>(std::round(std::pow(a, b)));
}

} // namespace detail

Polynomial::Polynomial(std::vector<coef_t> coefs) :
    m_coefs(std::move(coefs)), m_degree(m_coefs.size()), m_curr(0) {}

coef_t Polynomial::operator()(coef_t n) {
    coef_t res = 0;
    for (size_t i = 0; i < m_degree; ++i) {
        res += m_coefs[i] * detail::pow(n, i);
    }
    return res;
}

coef_t Polynomial::operator()() {
    return this->operator()(m_curr++);
}

void Polynomial::reset() { m_curr = 0; }

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    /*
     * TODO - write a better representation.
     * skipping it for now because it's not interesting.
     */
    os << "Polynomial" << p.m_coefs;
    return os;
}

} // namespace ramanujan
