#include <gtest/gtest.h>
#include <vector>
#include "problems/01_arrays_hashing/0217_contains_duplicate.hpp"

TEST(ContainsDuplicateTest, Example1) {
    std::vector<int> nums = {1, 2, 3, 1};
    EXPECT_TRUE(lc0217::Solution().containsDuplicate(nums));
}

TEST(ContainsDuplicateTest, Example2) {
    std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_FALSE(lc0217::Solution().containsDuplicate(nums));
}

TEST(ContainsDuplicateTest, SingleElement) {
    std::vector<int> nums = {7};
    EXPECT_FALSE(lc0217::Solution().containsDuplicate(nums));
}
