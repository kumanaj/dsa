#include <gtest/gtest.h>
#include <optional>
#include <vector>
#include "problems/07_trees/0235_lowest_common_ancestor_of_a_binary_search_tree.hpp"

// Returns the value of the LCA node, or -1 if the solution returned nullptr.
static int solve(const std::vector<std::optional<int>>& tree, int p, int q) {
    TreeNode* root = build_tree(tree);
    TreeNode* lca = lc0235::Solution().lowestCommonAncestor(root, find_node(root, p), find_node(root, q));
    int result = lca != nullptr ? lca->val : -1;
    free_tree(root);
    return result;
}

TEST(LowestCommonAncestorOfABinarySearchTreeTest, SplitAtRoot) {
    EXPECT_EQ(solve({6, 2, 8, 0, 4, 7, 9, null, null, 3, 5}, 2, 8), 6);
}

TEST(LowestCommonAncestorOfABinarySearchTreeTest, NodeIsItsOwnAncestor) {
    EXPECT_EQ(solve({6, 2, 8, 0, 4, 7, 9, null, null, 3, 5}, 2, 4), 2);
    EXPECT_EQ(solve({2, 1}, 2, 1), 2);
}

TEST(LowestCommonAncestorOfABinarySearchTreeTest, DeepSplit) {
    EXPECT_EQ(solve({6, 2, 8, 0, 4, 7, 9, null, null, 3, 5}, 3, 5), 4);
}
