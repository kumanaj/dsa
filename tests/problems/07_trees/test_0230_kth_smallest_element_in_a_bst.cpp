#include <gtest/gtest.h>
#include <optional>
#include <vector>
#include "problems/07_trees/0230_kth_smallest_element_in_a_bst.hpp"

static int solve(const std::vector<std::optional<int>>& tree, int k) {
    TreeNode* root = build_tree(tree);
    int result = lc0230::Solution().kthSmallest(root, k);
    free_tree(root);
    return result;
}

TEST(KthSmallestElementInABstTest, Example1) {
    EXPECT_EQ(solve({3, 1, 4, null, 2}, 1), 1);
}

TEST(KthSmallestElementInABstTest, Example2) {
    EXPECT_EQ(solve({5, 3, 6, 2, 4, null, null, 1}, 3), 3);
}

TEST(KthSmallestElementInABstTest, Largest) {
    EXPECT_EQ(solve({5, 3, 6, 2, 4, null, null, 1}, 6), 6);
}
