#include <gtest/gtest.h>
#include "data_structures/trie.hpp"

TEST(TrieTest, EmptyTrieFindsNothing) {
    Trie t;
    EXPECT_FALSE(t.search("a"));
    EXPECT_FALSE(t.starts_with("a"));
}

TEST(TrieTest, InsertAndSearch) {
    Trie t;
    t.insert("apple");
    EXPECT_TRUE(t.search("apple"));
    EXPECT_FALSE(t.search("app"));      // only a prefix, not a word
    EXPECT_TRUE(t.starts_with("app"));
    EXPECT_TRUE(t.starts_with("apple"));
}

TEST(TrieTest, PrefixBecomesWordAfterInsert) {
    Trie t;
    t.insert("apple");
    t.insert("app");
    EXPECT_TRUE(t.search("app"));
    EXPECT_TRUE(t.search("apple"));
}

TEST(TrieTest, LongerThanAnyWord) {
    Trie t;
    t.insert("apple");
    EXPECT_FALSE(t.search("apples"));
    EXPECT_FALSE(t.starts_with("apples"));
}

TEST(TrieTest, SharedPrefixes) {
    Trie t;
    t.insert("car");
    t.insert("cart");
    t.insert("care");
    t.insert("dog");
    EXPECT_TRUE(t.search("car"));
    EXPECT_TRUE(t.search("cart"));
    EXPECT_TRUE(t.search("care"));
    EXPECT_TRUE(t.search("dog"));
    EXPECT_FALSE(t.search("ca"));
    EXPECT_FALSE(t.search("do"));
    EXPECT_TRUE(t.starts_with("ca"));
    EXPECT_TRUE(t.starts_with("d"));
    EXPECT_FALSE(t.starts_with("cat"));
    EXPECT_FALSE(t.starts_with("e"));
}

TEST(TrieTest, InsertSameWordTwice) {
    Trie t;
    t.insert("hello");
    t.insert("hello");
    EXPECT_TRUE(t.search("hello"));
}
