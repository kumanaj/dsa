#include <gtest/gtest.h>
#include <algorithm>
#include <string>
#include <vector>
#include "problems/01_arrays_hashing/0049_group_anagrams.hpp"

using Groups = std::vector<std::vector<std::string>>;

// Groups and the strings inside them may come back in any order, so sort both before comparing.
static Groups solve(std::vector<std::string> strs) {
    Groups groups = lc0049::Solution().groupAnagrams(strs);
    for (auto& group : groups) {
        std::sort(group.begin(), group.end());
    }
    std::sort(groups.begin(), groups.end());
    return groups;
}

TEST(GroupAnagramsTest, Example1) {
    Groups expected = {{"ate", "eat", "tea"}, {"bat"}, {"nat", "tan"}};
    EXPECT_EQ(solve({"eat", "tea", "tan", "ate", "nat", "bat"}), expected);
}

TEST(GroupAnagramsTest, EmptyString) {
    EXPECT_EQ(solve({""}), (Groups{{""}}));
}

TEST(GroupAnagramsTest, SameLettersDifferentCounts) {
    Groups expected = {{"aab"}, {"abb"}};   // same letters, but not anagrams
    EXPECT_EQ(solve({"aab", "abb"}), expected);
}
