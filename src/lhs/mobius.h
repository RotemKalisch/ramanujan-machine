#pragma once

#include <tuple>
#include <string>
#include <sstream>

namespace ramanujan::lhs {

double calculate_mobius(
    double a, double b, double c, double d, double x, double y
);

template <class X, class Y>
std::string print_mobius(double a, double b, double c, double d, X x, Y y) {
    std::stringstream ss;
    ss << "Mobius(" << a << ", " << b << ", " << c << ", " << d << ", "
        << x << ", " << y << ")";
    return ss.str();
}

} // namespace ramanujan::lhs
