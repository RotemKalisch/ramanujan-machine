#include <gtest/gtest.h>

#include <chrono>
#include <cmath>
#include <numbers>

#include "src/meet.h"
#include "src/meet_map.h"
#include "src/rhs/enumerator.h"

namespace ramanujan::rhs {

class TestMap : public MeetMap {
public:
    TestMap() : MeetMap(), m_call_amount(0) {}
    bool contains(double key) const {
        ++m_call_amount;
        return MeetMap::contains(key);
    }

    size_t calls_amount() const {
        return m_call_amount;
    }

private:
    mutable size_t m_call_amount;
};

TEST(Enumerator, performance) {
    TestMap test_map;
    auto generators = create_generators(/*threshold=*/ 17);
    const auto start = std::chrono::steady_clock::now();
    enumerate<>(test_map, generators, generators, /*depth=*/100);
    const auto end = std::chrono::steady_clock::now();
    const double calls = test_map.calls_amount();
    const auto time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    const auto time_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << "Called " << std::log2(calls) << " bit RHS results in " << 
         time_ms.count() << " milliseconds." << std::endl <<
         "Rate: " << std::log2(calls / time_s.count()) << " bits/s" << std::endl;
}

} // namespace ramanujan
