#include <gtest/gtest.h>
#include <vector>
#include "problems/13_1d_dp/0213_house_robber_ii.hpp"

static int solve(std::vector<int> nums) {
    return lc0213::Solution().rob(nums);
}

TEST(HouseRobberIiTest, FirstAndLastAreAdjacent) {
    EXPECT_EQ(solve({2, 3, 2}), 3);
}

TEST(HouseRobberIiTest, Example2) {
    EXPECT_EQ(solve({1, 2, 3, 1}), 4);
}

TEST(HouseRobberIiTest, SingleHouse) {
    EXPECT_EQ(solve({5}), 5);   // excluding first or last would leave nothing
}
