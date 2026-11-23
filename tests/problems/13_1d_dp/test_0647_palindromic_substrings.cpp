#include <gtest/gtest.h>
#include "problems/13_1d_dp/0647_palindromic_substrings.hpp"

TEST(PalindromicSubstringsTest, Example1) {
    EXPECT_EQ(lc0647::Solution().countSubstrings("abc"), 3);
}

TEST(PalindromicSubstringsTest, Example2) {
    EXPECT_EQ(lc0647::Solution().countSubstrings("aaa"), 6);
}

TEST(PalindromicSubstringsTest, EvenLengthCentre) {
    EXPECT_EQ(lc0647::Solution().countSubstrings("abba"), 6);   // a, b, b, a, bb, abba
}
