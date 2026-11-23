#include <gtest/gtest.h>
#include <vector>
#include "problems/17_bit_manipulation/0338_counting_bits.hpp"

TEST(CountingBitsTest, Example1) {
    EXPECT_EQ(lc0338::Solution().countBits(2), (std::vector<int>{0, 1, 1}));
}

TEST(CountingBitsTest, Example2) {
    EXPECT_EQ(lc0338::Solution().countBits(5), (std::vector<int>{0, 1, 1, 2, 1, 2}));
}

TEST(CountingBitsTest, Zero) {
    EXPECT_EQ(lc0338::Solution().countBits(0), std::vector<int>{0});
}
