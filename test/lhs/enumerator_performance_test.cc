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
    const double unique_generated = test_map.size();
    const auto time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    const auto time_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << "Generated " << std::log2(unique_generated) << " bit LHS results in " << 
        time_ms.count() << " milliseconds." << std::endl <<
         "Rate: " << std::log2(unique_generated / time_s.count()) << " bits/s" << std::endl;
}

} // namespace ramanujan
