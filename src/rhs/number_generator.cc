#include "src/rhs/number_generator.h"

namespace ramanujan::rhs {

NumberGenerator::~NumberGenerator() {};

std::ostream& operator<<(std::ostream& os, const NumberGenerator& ng) {
    os << ng;
    return os;
}

} // namespace ramanujan::rhs
