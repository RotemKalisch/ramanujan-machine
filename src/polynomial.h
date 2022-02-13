#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>

#include "src/generator.h"

namespace ramanujan {

using coef_t = int32_t;

class Polynomial {
public:
    explicit Polynomial(std::vector<coef_t> coefs);
    coef_t operator()(coef_t);
    coef_t operator()();
    void reset();
    std::string to_string() const;

private:
    std::vector<coef_t> m_coefs;
    size_t m_degree;
    size_t m_curr;
};

} // namespace ramanujan
