#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "problems/01_arrays_hashing/0001_two_sum.hpp"

// Indices may come back in any order, so sort before comparing.
static std::vector<int> solve(std::vector<int> nums, int target) {
    std::vector<int> result = lc0001::Solution().twoSum(nums, target);
    std::sort(result.begin(), result.end());
    return result;
}

TEST(TwoSumTest, Example1) {
    EXPECT_EQ(solve({2, 7, 11, 15}, 9), (std::vector<int>{0, 1}));
}

TEST(TwoSumTest, Example2) {
    EXPECT_EQ(solve({3, 2, 4}, 6), (std::vector<int>{1, 2}));   // 3 + 3 would reuse index 0
}

TEST(TwoSumTest, DuplicateValues) {
    EXPECT_EQ(solve({3, 3}, 6), (std::vector<int>{0, 1}));
}
