#include <gtest/gtest.h>
#include <vector>
#include "problems/01_arrays_hashing/0128_longest_consecutive_sequence.hpp"

static int solve(std::vector<int> nums) {
    return lc0128::Solution().longestConsecutive(nums);
}

TEST(LongestConsecutiveSequenceTest, Example1) {
    EXPECT_EQ(solve({100, 4, 200, 1, 3, 2}), 4);
}

TEST(LongestConsecutiveSequenceTest, Example2WithDuplicates) {
    EXPECT_EQ(solve({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}), 9);
}

TEST(LongestConsecutiveSequenceTest, Empty) {
    EXPECT_EQ(solve({}), 0);
}
