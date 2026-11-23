#include <gtest/gtest.h>
#include "problems/02_two_pointers/0125_valid_palindrome.hpp"

TEST(ValidPalindromeTest, Example1) {
    EXPECT_TRUE(lc0125::Solution().isPalindrome("A man, a plan, a canal: Panama"));
}

TEST(ValidPalindromeTest, Example2) {
    EXPECT_FALSE(lc0125::Solution().isPalindrome("race a car"));
}

TEST(ValidPalindromeTest, DigitsCount) {
    EXPECT_FALSE(lc0125::Solution().isPalindrome("0P"));   // digits are kept, so "0p" is not a palindrome
    EXPECT_TRUE(lc0125::Solution().isPalindrome(" "));
}
