#include <gtest/gtest.h>
#include <optional>
#include <vector>
#include "problems/07_trees/0572_subtree_of_another_tree.hpp"

using Level = std::vector<std::optional<int>>;

static bool solve(const Level& a, const Level& b) {
    TreeNode* root = build_tree(a);
    TreeNode* sub = build_tree(b);
    bool result = lc0572::Solution().isSubtree(root, sub);
    free_tree(root);
    free_tree(sub);
    return result;
}

TEST(SubtreeOfAnotherTreeTest, Example1) {
    EXPECT_TRUE(solve({3, 4, 5, 1, 2}, {4, 1, 2}));
}

TEST(SubtreeOfAnotherTreeTest, ExtraNodeBelow) {
    EXPECT_FALSE(solve({3, 4, 5, 1, 2, null, null, null, null, 0}, {4, 1, 2}));
}

TEST(SubtreeOfAnotherTreeTest, ValuesThatLookAlikeAsText) {
    EXPECT_FALSE(solve({12}, {2}));   // catches string-matching approaches without separators
}
