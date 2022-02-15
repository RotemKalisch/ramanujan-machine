#include "src/lhs/lhs_enumerator.h"

#include <numeric>

#include "src/lhs/mobius.h"

namespace ramanujan {

LHSEnumerator::LHSEnumerator(MeetMap& meet_map, coef_t threshold) :
    m_meet_map(meet_map), m_threshold(threshold) {}

void LHSEnumerator::generate(double constant, const std::string& constant_name) {
    for (coef_t a = 0; a < m_threshold; ++a) {
        for (coef_t b = -m_threshold; b < m_threshold; ++b) {
            for (coef_t c = 0; c < m_threshold; ++c) {
                for (coef_t d = -m_threshold; d < m_threshold; ++d) {
                    if(std::gcd(a, b) != 1 || std::gcd(c, d) != 1) {
                        /*
                         * We don't want values such as 2pi + 2,
                         * as we already have pi + 1!
                         * We also catch here zero cases.
                         */
                        continue;
                    }
                    double numerator = calculate_mobius(a, b, c, d, constant, 1);
                    double denominator = calculate_mobius(a, b, c, d, 1, constant);
                    double both = calculate_mobius(a, b, c, d, constant, constant);
                    // TODO validate not in there
                    m_meet_map[numerator] = print_mobius(a, b, c, d, constant_name, 1);
                    m_meet_map[denominator] = print_mobius(a, b, c, d, 1, constant_name);
                    m_meet_map[both] = print_mobius(a, b, c, d, constant_name, constant_name);
                }
            }
        }
    }
}

} // namespace ramanujan
