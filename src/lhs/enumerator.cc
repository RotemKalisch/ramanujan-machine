#include "src/lhs/enumerator.h"

#include <numeric>

#include "src/lhs/mobius.h"

namespace ramanujan::lhs {

void enumerate(
    MeetMap& meet_map,
    const const_t constant,
    int32_t threshold
) { 
    for (int32_t a = 0; a < threshold; ++a) {
        for (int32_t b = -threshold; b < threshold; ++b) {
            for (int32_t c = 0; c < threshold; ++c) {
                for (int32_t d = -threshold; d < threshold; ++d) {
                    if(std::gcd(a, b) != 1 || std::gcd(c, d) != 1) {
                        /*
                         * We don't want values such as 2pi + 2,
                         * as we already have pi + 1!
                         * We also catch here zero cases.
                         */
                        continue;
                    }
                    double numerator = calculate_mobius(a, b, c, d, constant.first, 1);
                    double denominator = calculate_mobius(a, b, c, d, 1, constant.first);
                    double both = calculate_mobius(a, b, c, d, constant.first, constant.first);
                    // TODO validate not in there
                    meet_map[numerator] = print_mobius(a, b, c, d, constant.second, 1);
                    meet_map[denominator] = print_mobius(a, b, c, d, 1, constant.second);
                    meet_map[both] = print_mobius(a, b, c, d, constant.second, constant.second);
                }
            }
        }
    }
}

} // namespace ramanujan::lhs
