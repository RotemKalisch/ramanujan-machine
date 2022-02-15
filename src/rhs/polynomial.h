#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "src/rhs/number_generator.h"

namespace ramanujan {

using coef_t = int32_t;

class Polynomial : public NumberGenerator {
public:
    explicit Polynomial(std::vector<coef_t> coefs);
    virtual ~Polynomial();
    coef_t operator()(coef_t n) const;
    virtual coef_t operator()() const override;
    virtual void reset() const override;
    virtual std::string print() const override;

private:
    std::vector<coef_t> m_coefs;
    size_t m_degree;
    mutable size_t m_curr;
};

} // namespace ramanujan
