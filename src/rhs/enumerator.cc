#include "src/rhs/enumerator.h"

#include <iostream>

#include "src/rhs/continued_fraction.h"

namespace ramanujan::rhs {

void enumerate(
    MeetMap& meet_map,
    const number_generators_t& a_gens,
    const number_generators_t& b_gens,
    size_t depth
) {
    for (const std::unique_ptr<NumberGenerator>& a_gen : a_gens) {
        for (const std::unique_ptr<NumberGenerator>& b_gen : b_gens) {
            double value = calculate_continued_fraction(*a_gen, *b_gen, depth);
            if (meet_map.contains(value)) {
                std::cout << meet_map[value] << " = "
                    << print_continued_fraction(*a_gen, *b_gen) << std::endl;
            }
        }
    }

}

} // namespace ramanujan::rhs
