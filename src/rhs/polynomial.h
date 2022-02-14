#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "src/rhs/generator.h"

namespace ramanujan {

using coef_t = int32_t;

class Polynomial {
public:
    explicit Polynomial(std::vector<coef_t> coefs);
    coef_t operator()(coef_t n) const;
    coef_t operator()() const;
    void reset() const;
    friend std::ostream& operator<<(std::ostream&, const Polynomial&);

private:
    std::vector<coef_t> m_coefs;
    size_t m_degree;
    mutable size_t m_curr;
};

} // namespace ramanujan
