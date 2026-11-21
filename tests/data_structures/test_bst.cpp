#include <gtest/gtest.h>
#include "data_structures/bst.hpp"

// Builds:      5
//            /   \
//           3     8
//          / \   / \
//         1   4 7   9
static void build_sample(BinarySearchTree<int>& tree) {
    for (int key : {5, 3, 8, 1, 4, 7, 9}) {
        tree.insert(key);
    }
}

static std::string traverse_output(const BinarySearchTree<int>& tree) {
    testing::internal::CaptureStdout();
    tree.traverse();
    return testing::internal::GetCapturedStdout();
}

TEST(BinarySearchTreeTest, StartsEmpty) {
    BinarySearchTree<int> tree;
    EXPECT_EQ(tree.get_root(), nullptr);
    EXPECT_EQ(tree.size(), 0);
    EXPECT_EQ(tree.height(), 0);
    EXPECT_EQ(tree.search(1), nullptr);
    EXPECT_EQ(tree.get_min(), nullptr);
    EXPECT_EQ(tree.get_max(), nullptr);
}

TEST(BinarySearchTreeTest, InsertAndSearch) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    EXPECT_EQ(tree.get_root()->key, 5);
    ASSERT_NE(tree.search(4), nullptr);
    EXPECT_EQ(tree.search(4)->key, 4);
    EXPECT_EQ(tree.search(6), nullptr);
}

TEST(BinarySearchTreeTest, InsertKeepsBstShape) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    BstNode<int>* root = tree.get_root();
    EXPECT_EQ(root->left->key, 3);
    EXPECT_EQ(root->right->key, 8);
    EXPECT_EQ(root->left->left->key, 1);
    EXPECT_EQ(root->right->left->key, 7);
}

TEST(BinarySearchTreeTest, InsertSetsParent) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    EXPECT_EQ(tree.get_root()->parent, nullptr);
    EXPECT_EQ(tree.search(1)->parent, tree.search(3));
    EXPECT_EQ(tree.search(7)->parent, tree.search(8));
}

TEST(BinarySearchTreeTest, MinMax) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    EXPECT_EQ(tree.get_min()->key, 1);
    EXPECT_EQ(tree.get_max()->key, 9);
}

TEST(BinarySearchTreeTest, SizeHeightDepth) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    EXPECT_EQ(tree.size(), 7);
    EXPECT_EQ(tree.height(), 3);                 // counts nodes on the longest path
    EXPECT_EQ(tree.depth(tree.get_root()), 1);   // counts nodes from root down to node
    EXPECT_EQ(tree.depth(tree.search(9)), 3);
}

TEST(BinarySearchTreeTest, TraverseIsInOrder) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    EXPECT_EQ(traverse_output(tree), "1 3 4 5 7 8 9 ");
}

TEST(BinarySearchTreeTest, RemoveLeaf) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    tree.remove(1);
    EXPECT_EQ(tree.search(1), nullptr);
    EXPECT_EQ(tree.size(), 6);
    EXPECT_EQ(traverse_output(tree), "3 4 5 7 8 9 ");
}

TEST(BinarySearchTreeTest, RemoveNodeWithOneChild) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    tree.remove(1);
    tree.remove(3);   // 3 now has only the right child 4
    EXPECT_EQ(tree.get_root()->left->key, 4);
    EXPECT_EQ(tree.search(4)->parent, tree.get_root());
    EXPECT_EQ(traverse_output(tree), "4 5 7 8 9 ");
}

TEST(BinarySearchTreeTest, RemoveNodeWithTwoChildren) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    tree.remove(8);
    EXPECT_EQ(tree.search(8), nullptr);
    EXPECT_EQ(tree.size(), 6);
    EXPECT_EQ(traverse_output(tree), "1 3 4 5 7 9 ");
}

TEST(BinarySearchTreeTest, RemoveRoot) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    tree.remove(5);
    EXPECT_EQ(tree.size(), 6);
    EXPECT_EQ(tree.get_root()->parent, nullptr);
    EXPECT_EQ(traverse_output(tree), "1 3 4 7 8 9 ");
}

TEST(BinarySearchTreeTest, RemoveOnlyNode) {
    BinarySearchTree<int> tree;
    tree.insert(1);
    tree.remove(1);
    EXPECT_EQ(tree.get_root(), nullptr);
    EXPECT_EQ(tree.size(), 0);
}

TEST(BinarySearchTreeTest, RemoveMissingKeyIsNoOp) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    tree.remove(42);
    EXPECT_EQ(tree.size(), 7);
}

TEST(BinarySearchTreeTest, ClearThenReuse) {
    BinarySearchTree<int> tree;
    build_sample(tree);
    tree.clear();
    EXPECT_EQ(tree.get_root(), nullptr);
    EXPECT_EQ(tree.size(), 0);
    tree.insert(2);
    EXPECT_EQ(tree.get_root()->key, 2);
}
