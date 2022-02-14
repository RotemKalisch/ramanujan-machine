#include "src/lhs/mobius.h"

namespace ramanujan {

double calculate_mobius(double a, double b, double c, double d, double x, double y) {
    return (a*x + b) / (c*y + d);
}

} // namespace ramanujan
