#include <gtest/gtest.h>
#include "data_structures/graph.hpp"

// Directed sample graph:
//   0 -> 1 -> 3
//   0 -> 2 -> 3
//   4 is isolated
static Graph build_sample() {
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    return g;
}

TEST(GraphTest, Size) {
    Graph g(3);
    EXPECT_EQ(g.size(), 3);
}

TEST(GraphTest, AddVertexReturnsNewIndex) {
    Graph g(2);
    EXPECT_EQ(g.add_vertex(), 2);
    EXPECT_EQ(g.size(), 3);
}

TEST(GraphTest, EdgesAreDirected) {
    Graph g(2);
    g.add_edge(0, 1);
    EXPECT_TRUE(g.has_edge(0, 1));
    EXPECT_FALSE(g.has_edge(1, 0));
}

TEST(GraphTest, RemoveEdge) {
    Graph g = build_sample();
    g.remove_edge(0, 1);
    EXPECT_FALSE(g.has_edge(0, 1));
    EXPECT_TRUE(g.has_edge(0, 2));
    g.remove_edge(0, 1);   // removing a missing edge is a no-op
}

TEST(GraphTest, RemoveVertexShiftsIndices) {
    Graph g = build_sample();
    EXPECT_TRUE(g.remove_vertex(1));   // old 2 -> 1, old 3 -> 2, old 4 -> 3
    EXPECT_EQ(g.size(), 4);
    EXPECT_TRUE(g.has_edge(0, 1));     // was 0 -> 2
    EXPECT_TRUE(g.has_edge(1, 2));     // was 2 -> 3
    EXPECT_FALSE(g.has_edge(0, 2));    // 0 -> 1 -> 3 path is gone
}

TEST(GraphTest, InvalidVertexThrows) {
    Graph g(2);
    EXPECT_THROW(g.add_edge(0, 2), std::out_of_range);
    EXPECT_THROW(g.has_edge(-1, 0), std::out_of_range);
    EXPECT_THROW(g.remove_vertex(5), std::out_of_range);
    EXPECT_THROW(g.dfs(2), std::out_of_range);
    EXPECT_THROW(g.bfs(2), std::out_of_range);
}

TEST(GraphTest, Dfs) {
    Graph g = build_sample();
    EXPECT_EQ(g.dfs(0), (std::vector<int>{0, 1, 3, 2}));
    EXPECT_EQ(g.dfs(4), (std::vector<int>{4}));
}

TEST(GraphTest, Bfs) {
    Graph g = build_sample();
    EXPECT_EQ(g.bfs(0), (std::vector<int>{0, 1, 2, 3}));
    EXPECT_EQ(g.bfs(3), (std::vector<int>{3}));
}

TEST(GraphTest, PathExists) {
    Graph g = build_sample();
    EXPECT_TRUE(g.path_exists(0, 3));
    EXPECT_FALSE(g.path_exists(3, 0));
    EXPECT_FALSE(g.path_exists(0, 4));
}

TEST(GraphTest, IsConnected) {
    Graph g = build_sample();
    EXPECT_FALSE(g.is_connected());   // 4 is unreachable from 0
    g.add_edge(3, 4);
    EXPECT_TRUE(g.is_connected());
}

TEST(GraphTest, ShortestPath) {
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(0, 4);
    g.add_edge(4, 3);   // 0 -> 4 -> 3 is shorter than 0 -> 1 -> 2 -> 3
    EXPECT_EQ(g.shortest_path(0, 3), (std::vector<int>{0, 4, 3}));
    EXPECT_EQ(g.shortest_path(2, 2), (std::vector<int>{2}));
}

TEST(GraphTest, ShortestPathUnreachable) {
    Graph g = build_sample();
    EXPECT_EQ(g.shortest_path(3, 0), std::nullopt);
}
