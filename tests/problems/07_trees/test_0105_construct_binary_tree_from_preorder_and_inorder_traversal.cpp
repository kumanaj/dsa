#include <gtest/gtest.h>
#include <optional>
#include <vector>
#include "problems/07_trees/0105_construct_binary_tree_from_preorder_and_inorder_traversal.hpp"

using Level = std::vector<std::optional<int>>;

static Level solve(std::vector<int> preorder, std::vector<int> inorder) {
    TreeNode* root = lc0105::Solution().buildTree(preorder, inorder);
    Level result = to_level_order(root);
    free_tree(root);
    return result;
}

TEST(ConstructBinaryTreeFromPreorderAndInorderTraversalTest, Example1) {
    EXPECT_EQ(solve({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7}), (Level{3, 9, 20, null, null, 15, 7}));
}

TEST(ConstructBinaryTreeFromPreorderAndInorderTraversalTest, SingleNode) {
    EXPECT_EQ(solve({-1}, {-1}), Level{-1});
}

TEST(ConstructBinaryTreeFromPreorderAndInorderTraversalTest, LeftLeaning) {
    EXPECT_EQ(solve({3, 2, 1}, {1, 2, 3}), (Level{3, 2, null, 1}));
}
