#pragma once

#include <limits>
#include <optional>
#include <queue>
#include <stdexcept>
#include <vector>

// Directed graph with integer edge weights over int vertices 0..n-1.
// Like Graph, invalid vertex indices throw std::out_of_range.

struct WeightedEdge {
    int to;
    int weight;
};

class WeightedGraph {
public:
    static constexpr int INF = std::numeric_limits<int>::max();

    WeightedGraph(int n) : adj_list(n) {}

    int size() const { return static_cast<int>(adj_list.size()); }

    // TODO: not implemented yet
    // Add a directed edge u -> v.
    void add_edge(int u, int v, int weight) {
        throw std::logic_error("WeightedGraph::add_edge not implemented");
    }

    // TODO: not implemented yet
    // Shortest distance from src to every vertex (INF if unreachable). Weights must be non-negative.
    std::vector<int> dijkstra(int src) const {
        throw std::logic_error("WeightedGraph::dijkstra not implemented");
    }

    // TODO: not implemented yet
    // An order where every edge u -> v has u before v, or nullopt if the graph has a cycle.
    std::optional<std::vector<int>> topological_sort() const {
        throw std::logic_error("WeightedGraph::topological_sort not implemented");
    }

private:
    std::vector<std::vector<WeightedEdge>> adj_list;
};
