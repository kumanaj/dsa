#include <gtest/gtest.h>
#include <vector>
#include "problems/17_bit_manipulation/0268_missing_number.hpp"

static int solve(std::vector<int> nums) {
    return lc0268::Solution().missingNumber(nums);
}

TEST(MissingNumberTest, Example1) {
    EXPECT_EQ(solve({3, 0, 1}), 2);
    EXPECT_EQ(solve({9, 6, 4, 2, 3, 5, 7, 0, 1}), 8);
}

TEST(MissingNumberTest, MissingIsN) {
    EXPECT_EQ(solve({0, 1}), 2);
}

TEST(MissingNumberTest, MissingIsZero) {
    EXPECT_EQ(solve({1}), 0);
}
