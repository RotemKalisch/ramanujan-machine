#include "src/meet_map.h"

#include <cmath>
#include <iostream>

namespace ramanujan {

bool MeetMap::contains(double key) const {
    return m_results.contains(convert_to_key(key));
}

void MeetMap::insert(double value, std::string str) {
    if(std::isfinite(value)) {
        m_results[convert_to_key(value)] = std::move(str);
    }
}

const std::string& MeetMap::at(double value) const {
    return m_results.at(convert_to_key(value));
}

key_t MeetMap::convert_to_key(double key) {
    key *= RESOLUTION;
    return static_cast<key_t>(key);
}

} // namespace ramanujan
