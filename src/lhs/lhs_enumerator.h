#pragma once

#include "src/rhs/number_generator.h"
#include "src/meet_map.h"

namespace ramanujan {

class LHSEnumerator {
public:
    LHSEnumerator(MeetMap& meet_map);
    void generate(double constant, const std::string& constant_name, coef_t threshold);

private:
    MeetMap& m_meet_map;
    coef_t m_threshold;
};

} // namespace ramanujan
