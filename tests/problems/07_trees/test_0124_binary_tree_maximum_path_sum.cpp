#include <gtest/gtest.h>
#include <optional>
#include <vector>
#include "problems/07_trees/0124_binary_tree_maximum_path_sum.hpp"

static int solve(const std::vector<std::optional<int>>& tree) {
    TreeNode* root = build_tree(tree);
    int result = lc0124::Solution().maxPathSum(root);
    free_tree(root);
    return result;
}

TEST(BinaryTreeMaximumPathSumTest, Example1) {
    EXPECT_EQ(solve({1, 2, 3}), 6);
}

TEST(BinaryTreeMaximumPathSumTest, PathSkipsTheRoot) {
    EXPECT_EQ(solve({-10, 9, 20, null, null, 15, 7}), 42);
}

TEST(BinaryTreeMaximumPathSumTest, AllNegative) {
    EXPECT_EQ(solve({-3}), -3);
    EXPECT_EQ(solve({-2, -1}), -1);
}
