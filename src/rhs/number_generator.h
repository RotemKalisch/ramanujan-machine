#pragma once

#include <iostream>
#include <string>

using coef_t = int32_t;

namespace ramanujan::rhs {

class NumberGenerator {
public:
    virtual ~NumberGenerator() = 0;
    virtual void reset() const = 0;
    virtual coef_t operator()() const = 0;
    virtual std::string print() const = 0;
    friend std::ostream& operator<<(std::ostream&, const NumberGenerator&);
};

} // namespace ramanujan::rhs
