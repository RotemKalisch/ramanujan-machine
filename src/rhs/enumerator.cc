#include "src/rhs/enumerator.h"

#include <iostream>

#include "src/rhs/continued_fraction.h"

namespace ramanujan::rhs {

void enumerate(
    MeetMap& meet_map,
    const std::vector<number_generator_t>& a_gens,
    const std::vector<number_generator_t>& b_gens,
    size_t depth
) {
    for (const number_generator_t& a_gen : a_gens) {
        for (const number_generator_t& b_gen : b_gens) {
            std::optional<double> value_opt = calculate_continued_fraction(*a_gen, *b_gen, depth);
            if (!value_opt) { continue; }
            double value = *value_opt;
            if (meet_map.contains(value)) {
                std::cout << meet_map[value] << " = "
                    << print_continued_fraction(*a_gen, *b_gen) << " = "
                    << value << std::endl;
            }
        }
    }

}

} // namespace ramanujan::rhs
