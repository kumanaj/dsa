#include <gtest/gtest.h>
#include <vector>
#include "problems/13_1d_dp/0152_maximum_product_subarray.hpp"

static int solve(std::vector<int> nums) {
    return lc0152::Solution().maxProduct(nums);
}

TEST(MaximumProductSubarrayTest, Example1) {
    EXPECT_EQ(solve({2, 3, -2, 4}), 6);
}

TEST(MaximumProductSubarrayTest, ZeroSplitsTheArray) {
    EXPECT_EQ(solve({-2, 0, -1}), 0);
}

TEST(MaximumProductSubarrayTest, TwoNegatives) {
    EXPECT_EQ(solve({-2, 3, -4}), 24);   // needs the smallest product so far, not just the largest
}
