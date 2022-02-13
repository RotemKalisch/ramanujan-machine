#include <gtest/gtest.h>

#include "src/compare.h"
#include "src/mobius.h"

namespace ramanujan {

TEST(mobius, identity) {
    static constexpr double expected = 1.3275842395;
    static constexpr double margin = 0.00000000000001;
    double identity = calculate_mobius(expected, 0, 1, 0);
    EXPECT_TRUE(compare(expected, identity, margin));
}

} // namespace ramanujan
