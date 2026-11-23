#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "problems/13_1d_dp/0139_word_break.hpp"

static bool solve(const std::string& s, std::vector<std::string> dict) {
    return lc0139::Solution().wordBreak(s, dict);
}

TEST(WordBreakTest, Example1) {
    EXPECT_TRUE(solve("leetcode", {"leet", "code"}));
}

TEST(WordBreakTest, ReusesWords) {
    EXPECT_TRUE(solve("applepenapple", {"apple", "pen"}));
}

TEST(WordBreakTest, NoSplit) {
    EXPECT_FALSE(solve("catsandog", {"cats", "dog", "sand", "and", "cat"}));
}
