#include <gtest/gtest.h>
#include "problems/17_bit_manipulation/0191_number_of_1_bits.hpp"

TEST(NumberOf1BitsTest, Example1) {
    EXPECT_EQ(lc0191::Solution().hammingWeight(11), 3);
}

TEST(NumberOf1BitsTest, PowerOfTwo) {
    EXPECT_EQ(lc0191::Solution().hammingWeight(128), 1);
}

TEST(NumberOf1BitsTest, Large) {
    EXPECT_EQ(lc0191::Solution().hammingWeight(2147483645), 30);
}
