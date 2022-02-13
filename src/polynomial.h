#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>

namespace ramanujan {

using coef_t = int32_t;

class Polynomial {
public:
    explicit Polynomial(std::vector<coef_t> coefs);
    coef_t operator()(coef_t);

private:
    std::vector<coef_t> m_coefs;
    size_t m_degree;
};

} // namespace ramanujan
