#include <gtest/gtest.h>

#include "src/compare.h"
#include "src/continued_fraction.h"
#include "src/polynomial.h"

namespace ramanujan {

static constexpr double epsilon = 0.0001;

TEST(ContinuedFraction, ones) {
    Polynomial one(std::vector<coef_t>{1});
    ContinuedFraction cf(one, one);
    EXPECT_TRUE(compare(1.0, cf(0), epsilon)) << cf(0);
    EXPECT_TRUE(compare(2.0, cf(1), epsilon)) << cf(1);
    EXPECT_TRUE(compare(1.5, cf(2), epsilon)) << cf(2);
}

} // namespace ramanujan
