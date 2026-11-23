#include <gtest/gtest.h>
#include "problems/03_sliding_window/0424_longest_repeating_character_replacement.hpp"

TEST(LongestRepeatingCharacterReplacementTest, Example1) {
    EXPECT_EQ(lc0424::Solution().characterReplacement("ABAB", 2), 4);
}

TEST(LongestRepeatingCharacterReplacementTest, Example2) {
    EXPECT_EQ(lc0424::Solution().characterReplacement("AABABBA", 1), 4);
}

TEST(LongestRepeatingCharacterReplacementTest, NoReplacements) {
    EXPECT_EQ(lc0424::Solution().characterReplacement("ABBBCC", 0), 3);
}
