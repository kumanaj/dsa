#include <gtest/gtest.h>
#include <vector>
#include "problems/02_two_pointers/0011_container_with_most_water.hpp"

static int solve(std::vector<int> height) {
    return lc0011::Solution().maxArea(height);
}

TEST(ContainerWithMostWaterTest, Example1) {
    EXPECT_EQ(solve({1, 8, 6, 2, 5, 4, 8, 3, 7}), 49);
}

TEST(ContainerWithMostWaterTest, Example2) {
    EXPECT_EQ(solve({1, 1}), 1);
}

TEST(ContainerWithMostWaterTest, BestPairIsNotTheOuterOne) {
    EXPECT_EQ(solve({1, 2, 4, 3}), 4);   // heights 2 and 3, distance 2
}
