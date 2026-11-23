#include <gtest/gtest.h>
#include <optional>
#include <vector>
#include "problems/07_trees/0104_maximum_depth_of_binary_tree.hpp"

static int solve(const std::vector<std::optional<int>>& tree) {
    TreeNode* root = build_tree(tree);
    int result = lc0104::Solution().maxDepth(root);
    free_tree(root);
    return result;
}

TEST(MaximumDepthOfBinaryTreeTest, Example1) {
    EXPECT_EQ(solve({3, 9, 20, null, null, 15, 7}), 3);
}

TEST(MaximumDepthOfBinaryTreeTest, OnlyRightChildren) {
    EXPECT_EQ(solve({1, null, 2}), 2);
}

TEST(MaximumDepthOfBinaryTreeTest, Empty) {
    EXPECT_EQ(solve({}), 0);
}
