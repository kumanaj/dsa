#include <gtest/gtest.h>
#include "problems/01_arrays_hashing/0242_valid_anagram.hpp"

TEST(ValidAnagramTest, Example1) {
    EXPECT_TRUE(lc0242::Solution().isAnagram("anagram", "nagaram"));
}

TEST(ValidAnagramTest, Example2) {
    EXPECT_FALSE(lc0242::Solution().isAnagram("rat", "car"));
}

TEST(ValidAnagramTest, DifferentLengths) {
    EXPECT_FALSE(lc0242::Solution().isAnagram("ab", "a"));
    EXPECT_FALSE(lc0242::Solution().isAnagram("aab", "abb"));   // same letters, different counts
}
