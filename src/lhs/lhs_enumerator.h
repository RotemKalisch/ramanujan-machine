#pragma once

#include "src/rhs/number_generator.h"
#include "src/meet_map.h"

namespace ramanujan {

class LHSEnumerator {
public:
    LHSEnumerator(MeetMap& meet_map, coef_t threshold);
    void generate(double constant, const std::string& constant_name);

private:
    MeetMap& m_meet_map;
    coef_t m_threshold;
};

} // namespace ramanujan
