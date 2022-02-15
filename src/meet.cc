#include "src/meet.h"

#include "src/rhs/enumerator.h"
#include "src/rhs/polynomial.h"

namespace ramanujan {

std::vector<rhs::number_generator_t> create_linear_functions(int32_t thresh) {
    std::vector<rhs::number_generator_t> results;
    for (int32_t m = -thresh; m <= thresh; ++thresh) {
        for (int32_t n = - thresh; n <= thresh; ++thresh) {
            results.push_back(rhs::make_polynomial({n, m}));
        }
    }
    return results;
}
 
std::vector<rhs::number_generator_t> create_generators() {
    return create_linear_functions(20);
}

void load(MeetMap& meet_map) {
    lhs::enumerate(meet_map, 20, const_pairs);
}

void meet(
    MeetMap& meet_map,
    const std::vector<rhs::number_generator_t>& a_gens,
    const std::vector<rhs::number_generator_t>& b_gens
) {
    enumerate(meet_map, a_gens, b_gens, 20);
}

} // namespace ramanujan
