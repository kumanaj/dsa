#include <gtest/gtest.h>
#include "problems/03_sliding_window/0003_longest_substring_without_repeating_characters.hpp"

TEST(LongestSubstringWithoutRepeatingCharactersTest, Example1) {
    EXPECT_EQ(lc0003::Solution().lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(LongestSubstringWithoutRepeatingCharactersTest, Example3) {
    EXPECT_EQ(lc0003::Solution().lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(LongestSubstringWithoutRepeatingCharactersTest, EdgeCases) {
    EXPECT_EQ(lc0003::Solution().lengthOfLongestSubstring(""), 0);
    EXPECT_EQ(lc0003::Solution().lengthOfLongestSubstring("abba"), 2);   // the window's left edge must never move back
}
