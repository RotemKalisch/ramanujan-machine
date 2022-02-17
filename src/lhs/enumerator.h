#pragma once

#include <string_view>
#include <utility>
#include <vector>
#include <cmath>
#include <numeric>

#include "src/lhs/mobius.h"

namespace ramanujan::lhs {

using const_t = std::pair<double, std::string_view>;

namespace detail {

bool skip(int32_t a, int32_t b, int32_t c, int32_t d);

} // namespace detail

/**
 * Enumerates over all mobius of the const up to `threshold`
 * Returns the amount of unique mobius transformations inserted to the map.
 */
template <class Map>
size_t enumerate(
    Map& meet_map,
    int32_t threshold,
    const const_t& const_pair
) {
    size_t unique_inserted = 0;
    for (int32_t a = 0; a < threshold; ++a) {
        for (int32_t b = -threshold; b < threshold; ++b) {
            for (int32_t c = 0; c < threshold; ++c) {
                if (a == 0 && c == 0) {
                    continue;
                }
                for (int32_t d = -threshold; d < threshold; ++d) {
                    if (detail::skip(a, b, c, d)) {
                        continue;
                    }
                    ++unique_inserted;
                    meet_map.insert(
                        calculate_mobius(a, b, c, d, const_pair.first, const_pair.first),
                        print_mobius(a, b, c, d, const_pair.second, const_pair.second)
                    );
                }
            }
        }
    }
    return unique_inserted;
}

/**
 * Enumerates over all mobius of the const up to `threshold`
 * Returns the amount of unique mobius transformations inserted to the map.
 */
template <class Map>
size_t enumerate(
    Map& meet_map,
    int32_t threshold,
    const std::vector<const_t>& const_pairs
) {
    size_t unique_inserted = 0;
    for (const const_t const_pair : const_pairs) {
        unique_inserted += enumerate<>(meet_map, threshold, const_pair);
    }
    return unique_inserted;
}


} // namespace ramanujan::lhs
