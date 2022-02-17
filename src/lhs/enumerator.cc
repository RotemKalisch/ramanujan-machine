#include "src/lhs/enumerator.h"

namespace ramanujan::lhs::detail {

bool skip(int32_t a, int32_t b, int32_t c, int32_t d) {
    /*
     * We don't want values such as 2pi + 2, as we already have pi + 1.
     * For now we assume both numerator and denominator have no gcd.
     * This also prevents the numerator and denominator from being zero.
     * We also verify that we don't get a fraction that looks like x / x and
     * cancels out to one (We don't have to worry about 2x / x because of gcd).
     */
    return std::gcd(a, b) != 1 || std::gcd(c, d) != 1 || (a == c && b == d);
}

} // namespace ramanujan::lhs
