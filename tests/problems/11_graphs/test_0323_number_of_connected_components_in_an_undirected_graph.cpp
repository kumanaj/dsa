#include <gtest/gtest.h>
#include <vector>
#include "problems/11_graphs/0323_number_of_connected_components_in_an_undirected_graph.hpp"

static int solve(int n, std::vector<std::vector<int>> edges) {
    return lc0323::Solution().countComponents(n, edges);
}

TEST(NumberOfConnectedComponentsInAnUndirectedGraphTest, Example1) {
    EXPECT_EQ(solve(5, {{0, 1}, {1, 2}, {3, 4}}), 2);
}

TEST(NumberOfConnectedComponentsInAnUndirectedGraphTest, Example2) {
    EXPECT_EQ(solve(5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}), 1);
}

TEST(NumberOfConnectedComponentsInAnUndirectedGraphTest, IsolatedNodes) {
    EXPECT_EQ(solve(4, {{2, 3}}), 3);   // {0}, {1}, {2, 3}
}
