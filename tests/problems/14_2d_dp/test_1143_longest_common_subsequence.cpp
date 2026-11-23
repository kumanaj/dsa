#include <gtest/gtest.h>
#include "problems/14_2d_dp/1143_longest_common_subsequence.hpp"

TEST(LongestCommonSubsequenceTest, Example1) {
    EXPECT_EQ(lc1143::Solution().longestCommonSubsequence("abcde", "ace"), 3);
}

TEST(LongestCommonSubsequenceTest, SameAndDisjoint) {
    EXPECT_EQ(lc1143::Solution().longestCommonSubsequence("abc", "abc"), 3);
    EXPECT_EQ(lc1143::Solution().longestCommonSubsequence("abc", "def"), 0);
}

TEST(LongestCommonSubsequenceTest, RepeatedLetter) {
    EXPECT_EQ(lc1143::Solution().longestCommonSubsequence("bl", "yby"), 1);
}
