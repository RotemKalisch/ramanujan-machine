#pragma once

#include <unordered_map>
#include <string>

namespace ramanujan {

using key_t = int64_t;

/**
 * The meet hashmap
 * If we were to be actually scalable this would be a DB or something
 */
class MeetMap {
public:
    static constexpr int8_t RESOLUTION_BITS = 32;
    static constexpr key_t RESOLUTION = 1UL << RESOLUTION_BITS;
    bool contains(double key) const;
    std::string& operator[](double key);

private:
    static key_t convert_to_key(double key);
    std::unordered_map<key_t, std::string> m_results;
};

} // namespace ramanujan
