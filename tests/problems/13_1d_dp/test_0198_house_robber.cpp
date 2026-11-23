#include <gtest/gtest.h>
#include <vector>
#include "problems/13_1d_dp/0198_house_robber.hpp"

static int solve(std::vector<int> nums) {
    return lc0198::Solution().rob(nums);
}

TEST(HouseRobberTest, Example1) {
    EXPECT_EQ(solve({1, 2, 3, 1}), 4);
}

TEST(HouseRobberTest, Example2) {
    EXPECT_EQ(solve({2, 7, 9, 3, 1}), 12);
}

TEST(HouseRobberTest, SkipTwoInARow) {
    EXPECT_EQ(solve({2, 1, 1, 2}), 4);   // houses 0 and 3; "every other house" gives only 3
}
