#include <gtest/gtest.h>
#include <vector>
#include "problems/13_1d_dp/0300_longest_increasing_subsequence.hpp"

static int solve(std::vector<int> nums) {
    return lc0300::Solution().lengthOfLIS(nums);
}

TEST(LongestIncreasingSubsequenceTest, Example1) {
    EXPECT_EQ(solve({10, 9, 2, 5, 3, 7, 101, 18}), 4);
}

TEST(LongestIncreasingSubsequenceTest, Example2) {
    EXPECT_EQ(solve({0, 1, 0, 3, 2, 3}), 4);
}

TEST(LongestIncreasingSubsequenceTest, EqualValuesDontCount) {
    EXPECT_EQ(solve({7, 7, 7, 7, 7, 7, 7}), 1);
}
