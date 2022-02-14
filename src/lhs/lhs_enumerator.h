#pragma once

#include "src/rhs/generator.h"
#include "src/meet_map.h"

namespace ramanujan {

class LHSEnumerator {
public:
    LHSEnumerator(coef_t threshold);
    void generate(MeetMap& meet_map, double constant, const std::string& constant_name) const;

private:
    coef_t m_threshold;
};

} // namespace ramanujan
