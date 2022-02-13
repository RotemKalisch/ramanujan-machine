#include "src/meet.h"

namespace ramanujan {

bool MeetMap::contains(double key) const {
    return m_results.contains(convert_to_key(key));
}

std::string& MeetMap::operator[](double key) {
    return m_results[convert_to_key(key)];
}

key_t MeetMap::convert_to_key(double key) {
    key *= RESOLUTION;
    return static_cast<key_t>(key);
}

} // namespace ramanujan
