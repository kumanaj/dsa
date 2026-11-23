#include <gtest/gtest.h>
#include <string>
#include "problems/13_1d_dp/0005_longest_palindromic_substring.hpp"

static std::string solve(const std::string& s) {
    return lc0005::Solution().longestPalindrome(s);
}

TEST(LongestPalindromicSubstringTest, OddLengthTie) {
    std::string result = solve("babad");
    EXPECT_TRUE(result == "bab" || result == "aba") << result;
}

TEST(LongestPalindromicSubstringTest, EvenLength) {
    EXPECT_EQ(solve("cbbd"), "bb");
    EXPECT_EQ(solve("forgeeksskeegfor"), "geeksskeeg");
}

TEST(LongestPalindromicSubstringTest, SingleCharacter) {
    EXPECT_EQ(solve("a"), "a");
}
