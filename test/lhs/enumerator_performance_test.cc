#include <gtest/gtest.h>

#include <chrono>
#include <cmath>
#include <numbers>

#include "src/meet_map.h"
#include "src/lhs/enumerator.h"

namespace ramanujan::lhs {

class TestMap : public MeetMap {
public:
    size_t size() const {
        return m_results.size();
    }
};

TEST(Enumerator, performance) {
    TestMap test_map;
    const_t const_pair = std::pair(std::numbers::pi, "pi");
    const auto start = std::chrono::steady_clock::now();
    enumerate<>(test_map, 40, const_pair);
    const auto end = std::chrono::steady_clock::now();
    const double unique_generated_bits = std::log2(test_map.size());
    std::cout << "Generated " << unique_generated_bits << " bit LHS results in " << 
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() <<
        " milliseconds." << std::endl;
}

} // namespace ramanujan
