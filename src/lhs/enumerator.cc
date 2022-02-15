#include "src/lhs/enumerator.h"

#include <numeric>

#include "src/lhs/mobius.h"

namespace ramanujan::lhs {

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
    for (int32_t a = 1; a < threshold; ++a) {
        for (int32_t b = -threshold; b < threshold; ++b) {
            for (int32_t c = 1; c < threshold; ++c) {
                for (int32_t d = -threshold; d < threshold; ++d) {
                    if (std::gcd(a, b) != 1 || std::gcd(c, d) != 1) {
                        /*
                         * We don't want values such as 2pi + 2,
                         * as we already have pi + 1!
                         */
                        continue;
                    }
                    double numerator = calculate_mobius(a, b, c, d, const_pair.first, 1);
                    double denominator = calculate_mobius(a, b, c, d, 1, const_pair.first);
                    double both = calculate_mobius(a, b, c, d, const_pair.first, const_pair.first);
                    // TODO validate not in there
                    meet_map[numerator] = print_mobius(a, b, c, d, const_pair.second, 1);
                    meet_map[denominator] = print_mobius(a, b, c, d, 1, const_pair.second);
                    meet_map[both] = print_mobius(a, b, c, d, const_pair.second, const_pair.second);
                }
            }
        }
    }
}

} // namespace ramanujan::lhs
