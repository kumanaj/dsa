#include <gtest/gtest.h>
#include <optional>
#include <vector>
#include "problems/07_trees/0102_binary_tree_level_order_traversal.hpp"

using Levels = std::vector<std::vector<int>>;

static Levels solve(const std::vector<std::optional<int>>& tree) {
    TreeNode* root = build_tree(tree);
    Levels result = lc0102::Solution().levelOrder(root);
    free_tree(root);
    return result;
}

TEST(BinaryTreeLevelOrderTraversalTest, Example1) {
    EXPECT_EQ(solve({3, 9, 20, null, null, 15, 7}), (Levels{{3}, {9, 20}, {15, 7}}));
}

TEST(BinaryTreeLevelOrderTraversalTest, SmallTrees) {
    EXPECT_EQ(solve({1}), (Levels{{1}}));
    EXPECT_EQ(solve({}), Levels{});
}

TEST(BinaryTreeLevelOrderTraversalTest, GapsInALevel) {
    EXPECT_EQ(solve({1, 2, 3, 4, null, null, 5}), (Levels{{1}, {2, 3}, {4, 5}}));
}
