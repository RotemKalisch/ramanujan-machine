#include "src/compare.h"

#include <cmath>

namespace ramanujan {

bool compare(double a, double b, double margin) {
   return std::abs(a - b) < margin;
}

} // namespace ramanujan
