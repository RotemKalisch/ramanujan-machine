#include "src/lhs/enumerator.h"

#include <cmath>
#include <numeric>

#include "src/lhs/mobius.h"

namespace ramanujan::lhs {

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

void insert(MeetMap& meet_map, double value, std::string str) {
    if(std::isfinite(value)) {
        meet_map[value] = std::move(str);
    }
}

void enumerate(
    MeetMap& meet_map,
    int32_t threshold,
    const std::vector<const_t>& const_pairs
) {
    for (const const_t const_pair : const_pairs) {
        enumerate(meet_map, threshold, const_pair);
    }
}

void enumerate(
    MeetMap& meet_map,
    int32_t threshold,
    const const_t& const_pair
) { 
    for (int32_t a = 0; a < threshold; ++a) {
        for (int32_t b = -threshold; b < threshold; ++b) {
            for (int32_t c = 0; c < threshold; ++c) {
                if (a == 0 && c == 0) {
                    continue;
                }
                for (int32_t d = -threshold; d < threshold; ++d) {
                    if (skip(a, b, c, d)) {
                        continue;
                    }
                    insert(
                        meet_map,
                        calculate_mobius(a, b, c, d, const_pair.first, const_pair.first),
                        print_mobius(a, b, c, d, const_pair.second, const_pair.second)
                    );
                }
            }
        }
    }
}

} // namespace ramanujan::lhs
