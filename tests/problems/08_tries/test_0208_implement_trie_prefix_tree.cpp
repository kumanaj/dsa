#include <gtest/gtest.h>
#include "problems/08_tries/0208_implement_trie_prefix_tree.hpp"

TEST(ImplementTriePrefixTreeTest, Example) {
    lc0208::Trie trie;
    trie.insert("apple");
    EXPECT_TRUE(trie.search("apple"));
    EXPECT_FALSE(trie.search("app"));
    EXPECT_TRUE(trie.startsWith("app"));
    trie.insert("app");
    EXPECT_TRUE(trie.search("app"));
}

TEST(ImplementTriePrefixTreeTest, EmptyTrie) {
    lc0208::Trie trie;
    EXPECT_FALSE(trie.search("a"));
    EXPECT_FALSE(trie.startsWith("a"));
}

TEST(ImplementTriePrefixTreeTest, LongerThanAnyWord) {
    lc0208::Trie trie;
    trie.insert("car");
    EXPECT_FALSE(trie.search("cart"));
    EXPECT_FALSE(trie.startsWith("cart"));
    EXPECT_TRUE(trie.startsWith("car"));
}
