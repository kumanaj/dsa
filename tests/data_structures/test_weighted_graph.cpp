#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include "data_structures/weighted_graph.hpp"

// True if order contains every vertex once and each edge u -> v has u before v.
static bool is_valid_topological_order(const std::vector<int>& order, int n,
                                       const std::vector<std::pair<int, int>>& edges) {
    if (static_cast<int>(order.size()) != n) return false;
    std::vector<int> position(n, -1);
    for (int i = 0; i < n; i++) {
        if (order[i] < 0 || order[i] >= n || position[order[i]] != -1) return false;
        position[order[i]] = i;
    }
    for (auto [u, v] : edges) {
        if (position[u] > position[v]) return false;
    }
    return true;
}

TEST(WeightedGraphTest, Size) {
    WeightedGraph g(3);
    EXPECT_EQ(g.size(), 3);
}

TEST(WeightedGraphTest, AddEdgeInvalidVertexThrows) {
    WeightedGraph g(2);
    EXPECT_THROW(g.add_edge(0, 2, 1), std::out_of_range);
    EXPECT_THROW(g.add_edge(-1, 0, 1), std::out_of_range);
}

TEST(WeightedGraphTest, DijkstraShortestDistances) {
    //   0 -4-> 1 -1-> 3
    //   0 -1-> 2 -2-> 1
    //          2 -5-> 3
    //   4 is unreachable
    WeightedGraph g(5);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 2, 1);
    g.add_edge(2, 1, 2);
    g.add_edge(1, 3, 1);
    g.add_edge(2, 3, 5);
    std::vector<int> expected = {0, 3, 1, 4, WeightedGraph::INF};
    EXPECT_EQ(g.dijkstra(0), expected);
}

TEST(WeightedGraphTest, DijkstraFollowsEdgeDirection) {
    WeightedGraph g(2);
    g.add_edge(0, 1, 7);
    std::vector<int> expected = {WeightedGraph::INF, 0};
    EXPECT_EQ(g.dijkstra(1), expected);
}

TEST(WeightedGraphTest, DijkstraInvalidSourceThrows) {
    WeightedGraph g(2);
    EXPECT_THROW(g.dijkstra(5), std::out_of_range);
}

TEST(WeightedGraphTest, TopologicalSortOnDag) {
    std::vector<std::pair<int, int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    WeightedGraph g(6);
    for (auto [u, v] : edges) {
        g.add_edge(u, v, 1);
    }
    auto order = g.topological_sort();
    ASSERT_TRUE(order.has_value());
    EXPECT_TRUE(is_valid_topological_order(*order, 6, edges));
}

TEST(WeightedGraphTest, TopologicalSortIncludesIsolatedVertices) {
    WeightedGraph g(3);
    g.add_edge(0, 1, 1);
    auto order = g.topological_sort();
    ASSERT_TRUE(order.has_value());
    EXPECT_TRUE(is_valid_topological_order(*order, 3, {{0, 1}}));
}

TEST(WeightedGraphTest, TopologicalSortDetectsCycle) {
    WeightedGraph g(3);
    g.add_edge(0, 1, 1);
    g.add_edge(1, 2, 1);
    g.add_edge(2, 0, 1);
    EXPECT_EQ(g.topological_sort(), std::nullopt);
}
