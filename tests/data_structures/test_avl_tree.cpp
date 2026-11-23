#include <gtest/gtest.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include "data_structures/avl_tree.hpp"

// Walks the tree and checks the AVL property and each node's stored height.
// Returns the subtree height, or -1 if something is wrong.
template <typename T>
static int checked_height(AvlNode<T>* node) {
    if (node == nullptr) return 0;
    int left = checked_height(node->left);
    int right = checked_height(node->right);
    if (left < 0 || right < 0) return -1;
    if (std::abs(left - right) > 1) return -1;
    int height = 1 + std::max(left, right);
    if (node->height != height) return -1;
    return height;
}

TEST(AvlTreeTest, StartsEmpty) {
    AvlTree<int> t;
    EXPECT_TRUE(t.empty());
    EXPECT_EQ(t.size(), 0u);
    EXPECT_EQ(t.height(), 0);
    EXPECT_EQ(t.get_root(), nullptr);
    EXPECT_FALSE(t.contains(1));
    EXPECT_TRUE(t.in_order().empty());
}

TEST(AvlTreeTest, InsertAndContains) {
    AvlTree<int> t;
    t.insert(5);
    t.insert(3);
    t.insert(8);
    EXPECT_EQ(t.size(), 3u);
    EXPECT_TRUE(t.contains(3));
    EXPECT_TRUE(t.contains(8));
    EXPECT_FALSE(t.contains(4));
}

TEST(AvlTreeTest, InOrderIsSorted) {
    AvlTree<int> t;
    for (int k : {5, 3, 8, 1, 4}) {
        t.insert(k);
    }
    std::vector<int> expected = {1, 3, 4, 5, 8};
    EXPECT_EQ(t.in_order(), expected);
}

TEST(AvlTreeTest, IgnoresDuplicates) {
    AvlTree<int> t;
    t.insert(1);
    t.insert(1);
    EXPECT_EQ(t.size(), 1u);
}

TEST(AvlTreeTest, RightRightCaseRotatesLeft) {
    AvlTree<int> t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    EXPECT_EQ(t.get_root()->key, 2);
    EXPECT_EQ(t.height(), 2);
}

TEST(AvlTreeTest, LeftLeftCaseRotatesRight) {
    AvlTree<int> t;
    t.insert(3);
    t.insert(2);
    t.insert(1);
    EXPECT_EQ(t.get_root()->key, 2);
    EXPECT_EQ(t.height(), 2);
}

TEST(AvlTreeTest, LeftRightCase) {
    AvlTree<int> t;
    t.insert(3);
    t.insert(1);
    t.insert(2);
    EXPECT_EQ(t.get_root()->key, 2);
    EXPECT_EQ(t.height(), 2);
}

TEST(AvlTreeTest, RightLeftCase) {
    AvlTree<int> t;
    t.insert(1);
    t.insert(3);
    t.insert(2);
    EXPECT_EQ(t.get_root()->key, 2);
    EXPECT_EQ(t.height(), 2);
}

TEST(AvlTreeTest, StaysBalancedOnSortedInsert) {
    AvlTree<int> t;
    for (int i = 0; i < 1024; i++) {
        t.insert(i);
    }
    EXPECT_EQ(t.size(), 1024u);
    EXPECT_GT(checked_height(t.get_root()), 0);
    EXPECT_LE(t.height(), 14);   // an unbalanced BST would be 1024 tall
}

TEST(AvlTreeTest, Remove) {
    AvlTree<int> t;
    for (int i = 1; i <= 7; i++) {
        t.insert(i);
    }
    t.remove(4);   // node with two children
    t.remove(7);   // leaf
    std::vector<int> expected = {1, 2, 3, 5, 6};
    EXPECT_EQ(t.in_order(), expected);
    EXPECT_EQ(t.size(), 5u);
    EXPECT_FALSE(t.contains(4));
    EXPECT_GT(checked_height(t.get_root()), 0);
}

TEST(AvlTreeTest, RemoveMissingIsNoOp) {
    AvlTree<int> t;
    t.insert(1);
    t.remove(2);
    EXPECT_EQ(t.size(), 1u);
    EXPECT_TRUE(t.contains(1));
}

TEST(AvlTreeTest, StaysBalancedAfterRemovals) {
    AvlTree<int> t;
    for (int i = 0; i < 100; i++) {
        t.insert(i);
    }
    for (int i = 0; i < 100; i += 2) {
        t.remove(i);
    }
    std::vector<int> expected;
    for (int i = 1; i < 100; i += 2) {
        expected.push_back(i);
    }
    EXPECT_EQ(t.in_order(), expected);
    EXPECT_GT(checked_height(t.get_root()), 0);
}

TEST(AvlTreeTest, ClearThenReuse) {
    AvlTree<int> t;
    t.insert(1);
    t.insert(2);
    t.clear();
    EXPECT_TRUE(t.empty());
    EXPECT_EQ(t.get_root(), nullptr);
    t.insert(3);
    EXPECT_EQ(t.size(), 1u);
    EXPECT_TRUE(t.contains(3));
}
