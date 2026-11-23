#include <gtest/gtest.h>
#include "problems/13_1d_dp/0091_decode_ways.hpp"

TEST(DecodeWaysTest, Example1) {
    EXPECT_EQ(lc0091::Solution().numDecodings("12"), 2);
}

TEST(DecodeWaysTest, Example2) {
    EXPECT_EQ(lc0091::Solution().numDecodings("226"), 3);
}

TEST(DecodeWaysTest, Zeros) {
    EXPECT_EQ(lc0091::Solution().numDecodings("06"), 0);
    EXPECT_EQ(lc0091::Solution().numDecodings("10"), 1);    // only "J"
    EXPECT_EQ(lc0091::Solution().numDecodings("100"), 0);   // the second 0 can't be decoded
}
