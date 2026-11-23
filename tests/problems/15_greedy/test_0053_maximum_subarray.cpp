#include <gtest/gtest.h>
#include <vector>
#include "problems/15_greedy/0053_maximum_subarray.hpp"

static int solve(std::vector<int> nums) {
    return lc0053::Solution().maxSubArray(nums);
}

TEST(MaximumSubarrayTest, Example1) {
    EXPECT_EQ(solve({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
}

TEST(MaximumSubarrayTest, WholeArray) {
    EXPECT_EQ(solve({5, 4, -1, 7, 8}), 23);
}

TEST(MaximumSubarrayTest, AllNegative) {
    EXPECT_EQ(solve({-3, -1, -2}), -1);   // must pick at least one element, so not 0
}
