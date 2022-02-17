#include "src/meet.h"

#include "src/rhs/enumerator.h"
#include "src/rhs/polynomial.h"

namespace ramanujan {

std::vector<rhs::number_generator_t> create_linear_functions(int32_t threshold) {
    std::vector<rhs::number_generator_t> results;
    for (int32_t m = -threshold; m <= threshold; ++m) {
        for (int32_t n = - threshold; n <= threshold; ++n) {
            results.push_back(rhs::make_polynomial({n, m}));
        }
    }
    return results;
}
 
std::vector<rhs::number_generator_t> create_generators(int32_t threshold) {
    return create_linear_functions(threshold);
}

void load(MeetMap& meet_map, int32_t threshold) {
    lhs::enumerate<>(meet_map, threshold, const_pairs);
}

void meet(
    MeetMap& meet_map,
    const std::vector<rhs::number_generator_t>& a_gens,
    const std::vector<rhs::number_generator_t>& b_gens,
    size_t depth
) {
    rhs::enumerate<>(meet_map, a_gens, b_gens, depth);
}

} // namespace ramanujan
