#include <gtest/gtest.h>
#include <climits>
#include <optional>
#include <vector>
#include "problems/07_trees/0098_validate_binary_search_tree.hpp"

static bool solve(const std::vector<std::optional<int>>& tree) {
    TreeNode* root = build_tree(tree);
    bool result = lc0098::Solution().isValidBST(root);
    free_tree(root);
    return result;
}

TEST(ValidateBinarySearchTreeTest, Examples) {
    EXPECT_TRUE(solve({2, 1, 3}));
    EXPECT_FALSE(solve({5, 1, 4, null, null, 3, 6}));
}

TEST(ValidateBinarySearchTreeTest, ViolationDeeperDown) {
    EXPECT_FALSE(solve({5, 4, 6, null, null, 3, 7}));   // 3 is in 5's right subtree; checking only parent/child misses it
    EXPECT_FALSE(solve({2, 2, 2}));                     // equal keys are not allowed
}

TEST(ValidateBinarySearchTreeTest, IntLimits) {
    EXPECT_TRUE(solve({INT_MAX}));
    EXPECT_TRUE(solve({INT_MIN, null, INT_MAX}));
}
