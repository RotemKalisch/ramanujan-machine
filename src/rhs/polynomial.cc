#include "src/rhs/polynomial.h"

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

Polynomial::~Polynomial() {}

coef_t Polynomial::operator()(coef_t n) const {
    coef_t res = 0;
    for (size_t i = 0; i < m_degree; ++i) {
        res += m_coefs[i] * detail::pow(n, i);
    }
    return res;
}

coef_t Polynomial::operator()() const {
    return this->operator()(m_curr++);
}

void Polynomial::reset() const { m_curr = 0; }

std::string Polynomial::print() const {
    /*
     * TODO - write a better representation.
     * skipping it for now because it's not interesting.
     */
    std::stringstream ss;
    ss << "Polynomial" << m_coefs;
    return ss.str();
}

} // namespace ramanujan
