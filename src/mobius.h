#pragma once

#include <tuple>
#include <string>

namespace ramanujan {

using symbolic_mobius = std::tuple<std::string, std::string, std::string, std::string>;

double calculate_mobius(double a, double b, double c, double d);

} // namespace ramanujan
