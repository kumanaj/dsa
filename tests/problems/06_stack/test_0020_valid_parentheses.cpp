#include <gtest/gtest.h>
#include "problems/06_stack/0020_valid_parentheses.hpp"

TEST(ValidParenthesesTest, Valid) {
    EXPECT_TRUE(lc0020::Solution().isValid("()[]{}"));
    EXPECT_TRUE(lc0020::Solution().isValid("([])"));
}

TEST(ValidParenthesesTest, WrongTypeOrOrder) {
    EXPECT_FALSE(lc0020::Solution().isValid("(]"));
    EXPECT_FALSE(lc0020::Solution().isValid("([)]"));
}

TEST(ValidParenthesesTest, Unbalanced) {
    EXPECT_FALSE(lc0020::Solution().isValid("("));
    EXPECT_FALSE(lc0020::Solution().isValid("]"));
}
