#include <gtest/gtest.h>
#include <vector>
#include "problems/04_binary_search/0153_find_minimum_in_rotated_sorted_array.hpp"

static int solve(std::vector<int> nums) {
    return lc0153::Solution().findMin(nums);
}

TEST(FindMinimumInRotatedSortedArrayTest, Example1) {
    EXPECT_EQ(solve({3, 4, 5, 1, 2}), 1);
}

TEST(FindMinimumInRotatedSortedArrayTest, Example2) {
    EXPECT_EQ(solve({4, 5, 6, 7, 0, 1, 2}), 0);
}

TEST(FindMinimumInRotatedSortedArrayTest, NotRotated) {
    EXPECT_EQ(solve({11, 13, 15, 17}), 11);
    EXPECT_EQ(solve({2, 1}), 1);
}
