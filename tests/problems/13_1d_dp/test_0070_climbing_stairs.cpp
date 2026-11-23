#include <gtest/gtest.h>
#include "problems/13_1d_dp/0070_climbing_stairs.hpp"

TEST(ClimbingStairsTest, Examples) {
    EXPECT_EQ(lc0070::Solution().climbStairs(2), 2);
    EXPECT_EQ(lc0070::Solution().climbStairs(3), 3);
}

TEST(ClimbingStairsTest, OneStep) {
    EXPECT_EQ(lc0070::Solution().climbStairs(1), 1);
}

TEST(ClimbingStairsTest, LargestInput) {
    EXPECT_EQ(lc0070::Solution().climbStairs(45), 1836311903);   // plain recursion is far too slow here
}
