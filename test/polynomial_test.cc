#include <gtest/gtest.h>

#include "src/polynomial.h"

namespace ramanujan {

TEST(Polynomial, zero) {
    Polynomial p(std::vector<coef_t>{});
    for (int32_t n = 0; n < 10; ++n) {
        EXPECT_EQ(0, p(n));
    }
}

TEST(Polynomial, basic) {
    // 3 -5*x - x^2 + 2*x^3
    Polynomial p(std::vector<coef_t>{3, -5, -1, 2});
    EXPECT_EQ(3, p(0));
    EXPECT_EQ(-1, p(1));
    EXPECT_EQ(5, p(2));
}

} // namespace ramanujan
