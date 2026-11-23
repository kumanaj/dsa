#include <gtest/gtest.h>
#include "problems/08_tries/0211_design_add_and_search_words_data_structure.hpp"

TEST(DesignAddAndSearchWordsDataStructureTest, Example) {
    lc0211::WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    EXPECT_FALSE(dict.search("pad"));
    EXPECT_TRUE(dict.search("bad"));
    EXPECT_TRUE(dict.search(".ad"));
    EXPECT_TRUE(dict.search("b.."));
}

TEST(DesignAddAndSearchWordsDataStructureTest, LengthMustMatch) {
    lc0211::WordDictionary dict;
    dict.addWord("bad");
    EXPECT_FALSE(dict.search("ba"));
    EXPECT_FALSE(dict.search("b..."));
    EXPECT_FALSE(dict.search("."));
}

TEST(DesignAddAndSearchWordsDataStructureTest, DotsTryEveryBranch) {
    lc0211::WordDictionary dict;
    dict.addWord("ab");
    dict.addWord("cd");
    EXPECT_TRUE(dict.search(".d"));   // first branch ('a') fails, second ('c') matches
    EXPECT_TRUE(dict.search(".."));
}
