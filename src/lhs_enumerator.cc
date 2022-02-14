#include "src/lhs_enumerator.h"

#include <numeric>

#include "src/mobius.h"

namespace ramanujan {

LHSEnumerator::LHSEnumerator(coef_t threshold) : m_threshold(threshold) {}

void LHSEnumerator::generate(MeetMap& meet_map, double constant, const std::string& constant_name) const {
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
                    // TODO validate not in there
                    meet_map[numerator] = print_mobius(a, b, c, d, constant_name, 1);
                    meet_map[denominator] = print_mobius(a, b, c, d, 1, constant);
                }
            }
        }
    }
}

} // namespace ramanujan
