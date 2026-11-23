#include <gtest/gtest.h>
#include <vector>
#include "problems/11_graphs/0261_graph_valid_tree.hpp"

static bool solve(int n, std::vector<std::vector<int>> edges) {
    return lc0261::Solution().validTree(n, edges);
}

TEST(GraphValidTreeTest, Example1) {
    EXPECT_TRUE(solve(5, {{0, 1}, {0, 2}, {0, 3}, {1, 4}}));
    EXPECT_TRUE(solve(1, {}));   // a single node is a tree
}

TEST(GraphValidTreeTest, Cycle) {
    EXPECT_FALSE(solve(5, {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}}));
}

TEST(GraphValidTreeTest, Disconnected) {
    EXPECT_FALSE(solve(4, {{0, 1}, {2, 3}}));
}
