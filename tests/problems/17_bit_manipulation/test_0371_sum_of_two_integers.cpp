#include <gtest/gtest.h>
#include "problems/17_bit_manipulation/0371_sum_of_two_integers.hpp"

TEST(SumOfTwoIntegersTest, Examples) {
    EXPECT_EQ(lc0371::Solution().getSum(1, 2), 3);
    EXPECT_EQ(lc0371::Solution().getSum(2, 3), 5);
}

TEST(SumOfTwoIntegersTest, MixedSigns) {
    EXPECT_EQ(lc0371::Solution().getSum(-1, 1), 0);
    EXPECT_EQ(lc0371::Solution().getSum(-12, 7), -5);
}

TEST(SumOfTwoIntegersTest, BothNegative) {
    EXPECT_EQ(lc0371::Solution().getSum(-2, -3), -5);
    EXPECT_EQ(lc0371::Solution().getSum(-1000, -1000), -2000);
}
