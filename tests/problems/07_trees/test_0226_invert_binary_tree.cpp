#include <gtest/gtest.h>
#include <optional>
#include <vector>
#include "problems/07_trees/0226_invert_binary_tree.hpp"

using Level = std::vector<std::optional<int>>;

static Level solve(const Level& tree) {
    TreeNode* root = lc0226::Solution().invertTree(build_tree(tree));
    Level result = to_level_order(root);
    free_tree(root);
    return result;
}

TEST(InvertBinaryTreeTest, Example1) {
    EXPECT_EQ(solve({4, 2, 7, 1, 3, 6, 9}), (Level{4, 7, 2, 9, 6, 3, 1}));
}

TEST(InvertBinaryTreeTest, Lopsided) {
    EXPECT_EQ(solve({1, 2, null, 3}), (Level{1, null, 2, null, 3}));
}

TEST(InvertBinaryTreeTest, Empty) {
    EXPECT_EQ(solve({}), Level{});
}
