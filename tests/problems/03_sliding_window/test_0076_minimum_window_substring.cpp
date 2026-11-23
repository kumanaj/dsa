#include <gtest/gtest.h>
#include "problems/03_sliding_window/0076_minimum_window_substring.hpp"

TEST(MinimumWindowSubstringTest, Example1) {
    EXPECT_EQ(lc0076::Solution().minWindow("ADOBECODEBANC", "ABC"), "BANC");
}

TEST(MinimumWindowSubstringTest, WholeString) {
    EXPECT_EQ(lc0076::Solution().minWindow("a", "a"), "a");
}

TEST(MinimumWindowSubstringTest, DuplicatesInT) {
    EXPECT_EQ(lc0076::Solution().minWindow("a", "aa"), "");
    EXPECT_EQ(lc0076::Solution().minWindow("abaa", "aa"), "aa");
}
