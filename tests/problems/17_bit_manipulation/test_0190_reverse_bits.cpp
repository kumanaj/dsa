#include <gtest/gtest.h>
#include <cstdint>
#include "problems/17_bit_manipulation/0190_reverse_bits.hpp"

TEST(ReverseBitsTest, Example1) {
    EXPECT_EQ(lc0190::Solution().reverseBits(43261596u), 964176192u);
}

TEST(ReverseBitsTest, Example2) {
    EXPECT_EQ(lc0190::Solution().reverseBits(4294967293u), 3221225471u);
}

TEST(ReverseBitsTest, LowestBitBecomesHighest) {
    EXPECT_EQ(lc0190::Solution().reverseBits(1u), 2147483648u);
    EXPECT_EQ(lc0190::Solution().reverseBits(0u), 0u);
}
