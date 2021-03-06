#include <gtest/gtest.h>

#include "src/compare.h"
#include "src/rhs/continued_fraction.h"
#include "src/rhs/polynomial.h"

namespace ramanujan::rhs {

static constexpr double epsilon = 0.0001;

TEST(ContinuedFraction, one) {
    Polynomial one(std::vector<coef_t>{1});
    std::vector<double> cf = {
        calculate_continued_fraction(one, one, 0),
        calculate_continued_fraction(one, one, 1),
        calculate_continued_fraction(one, one, 2)
    };
    EXPECT_TRUE(compare(1.0, cf[0], epsilon)) << cf[0];
    EXPECT_TRUE(compare(2.0, cf[1], epsilon)) << cf[1];
    EXPECT_TRUE(compare(1.5, cf[2], epsilon)) << cf[2];
}

} // namespace ramanujan
