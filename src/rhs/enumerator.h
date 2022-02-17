#pragma once

#include <vector>

#include "src/meet_map.h"
#include "src/rhs/continued_fraction.h"
#include "src/rhs/number_generator.h"

namespace ramanujan::rhs {

template <class Map>
void enumerate(
    Map& meet_map,
    const std::vector<number_generator_t>& a_gens,
    const std::vector<number_generator_t>& b_gens,
    size_t depth
) {
    for (const number_generator_t& a_gen : a_gens) {
        for (const number_generator_t& b_gen : b_gens) {
            double value = calculate_continued_fraction(*a_gen, *b_gen, depth);
            if (meet_map.contains(value)) {
                std::cout << meet_map.at(value) << " = "
                    << print_continued_fraction(*a_gen, *b_gen) << " = "
                    << value << std::endl;
            }
        }
    }
}

} // namespace ramanujan::rhs
