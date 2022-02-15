#include "src/lhs/enumerator.h"

#include <cmath>
#include <numeric>

#include "src/lhs/mobius.h"

namespace ramanujan::lhs {

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
                    insert(
                        meet_map,
                        calculate_mobius(a, b, c, d, const_pair.first, 1),
                        print_mobius(a, b, c, d, const_pair.second, 1)
                    );
                    // We want to avoid cases of 0 numerator
                    if (a + b != 0) {
                        insert(
                            meet_map,
                            calculate_mobius(a, b, c, d, 1, const_pair.first),
                            print_mobius(a, b, c, d, 1, const_pair.second)
                        );
                    }
                    // Since here x = y, we don't want things such as (1+x)/(1+x)
                    if (!(a == c && b == d)) {
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
}

} // namespace ramanujan::lhs
