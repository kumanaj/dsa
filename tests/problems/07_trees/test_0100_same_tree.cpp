#include <gtest/gtest.h>
#include <optional>
#include <vector>
#include "problems/07_trees/0100_same_tree.hpp"

using Level = std::vector<std::optional<int>>;

static bool solve(const Level& a, const Level& b) {
    TreeNode* p = build_tree(a);
    TreeNode* q = build_tree(b);
    bool result = lc0100::Solution().isSameTree(p, q);
    free_tree(p);
    free_tree(q);
    return result;
}

TEST(SameTreeTest, Same) {
    EXPECT_TRUE(solve({1, 2, 3}, {1, 2, 3}));
    EXPECT_TRUE(solve({}, {}));
}

TEST(SameTreeTest, DifferentShape) {
    EXPECT_FALSE(solve({1, 2}, {1, null, 2}));
    EXPECT_FALSE(solve({1}, {}));
}

TEST(SameTreeTest, DifferentValues) {
    EXPECT_FALSE(solve({1, 2, 1}, {1, 1, 2}));
}
