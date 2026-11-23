#include <gtest/gtest.h>
#include <vector>
#include "problems/04_binary_search/0033_search_in_rotated_sorted_array.hpp"

static int solve(std::vector<int> nums, int target) {
    return lc0033::Solution().search(nums, target);
}

TEST(SearchInRotatedSortedArrayTest, Example1) {
    EXPECT_EQ(solve({4, 5, 6, 7, 0, 1, 2}, 0), 4);
}

TEST(SearchInRotatedSortedArrayTest, Missing) {
    EXPECT_EQ(solve({4, 5, 6, 7, 0, 1, 2}, 3), -1);
    EXPECT_EQ(solve({1}, 0), -1);
}

TEST(SearchInRotatedSortedArrayTest, TwoElements) {
    EXPECT_EQ(solve({3, 1}, 1), 1);
    EXPECT_EQ(solve({3, 1}, 3), 0);
}
