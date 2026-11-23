#include <gtest/gtest.h>
#include <vector>
#include "problems/01_arrays_hashing/0238_product_of_array_except_self.hpp"

static std::vector<int> solve(std::vector<int> nums) {
    return lc0238::Solution().productExceptSelf(nums);
}

TEST(ProductOfArrayExceptSelfTest, Example1) {
    EXPECT_EQ(solve({1, 2, 3, 4}), (std::vector<int>{24, 12, 8, 6}));
}

TEST(ProductOfArrayExceptSelfTest, OneZero) {
    EXPECT_EQ(solve({-1, 1, 0, -3, 3}), (std::vector<int>{0, 0, 9, 0, 0}));
}

TEST(ProductOfArrayExceptSelfTest, TwoZeros) {
    EXPECT_EQ(solve({0, 2, 0}), (std::vector<int>{0, 0, 0}));
}
