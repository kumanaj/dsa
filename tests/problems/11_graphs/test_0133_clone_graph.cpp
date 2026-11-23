#include <gtest/gtest.h>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include "problems/11_graphs/0133_clone_graph.hpp"

using lc0133::Node;
using AdjList = std::vector<std::vector<int>>;

// Every node reachable from start, keyed by value.
static std::map<int, Node*> collect(Node* start) {
    std::map<int, Node*> nodes;
    if (start == nullptr) return nodes;
    std::queue<Node*> pending;
    pending.push(start);
    nodes[start->val] = start;
    while (!pending.empty()) {
        Node* node = pending.front();
        pending.pop();
        for (Node* next : node->neighbors) {
            if (nodes.count(next->val) == 0) {
                nodes[next->val] = next;
                pending.push(next);
            }
        }
    }
    return nodes;
}

// Clones the graph built from adj, checks that no original node was reused, and returns the clone's adjacency list.
static AdjList solve(const AdjList& adj) {
    std::vector<Node*> originals;
    for (size_t i = 0; i < adj.size(); i++) {
        originals.push_back(new Node(static_cast<int>(i) + 1));
    }
    for (size_t i = 0; i < adj.size(); i++) {
        for (int v : adj[i]) {
            originals[i]->neighbors.push_back(originals[v - 1]);
        }
    }

    Node* copy = lc0133::Solution().cloneGraph(originals.empty() ? nullptr : originals[0]);
    std::map<int, Node*> cloned = collect(copy);

    std::set<Node*> original_set(originals.begin(), originals.end());
    AdjList result;
    for (auto& [val, node] : cloned) {
        EXPECT_EQ(original_set.count(node), 0u) << "node " << val << " is an original, not a copy";
        std::vector<int> neighbours;
        for (Node* next : node->neighbors) {
            neighbours.push_back(next->val);
        }
        result.push_back(neighbours);
    }

    for (auto& [val, node] : cloned) {
        if (original_set.count(node) == 0) delete node;
    }
    for (Node* node : originals) {
        delete node;
    }
    return result;
}

TEST(CloneGraphTest, Example1) {
    AdjList adj = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};
    EXPECT_EQ(solve(adj), adj);
}

TEST(CloneGraphTest, SingleNode) {
    AdjList adj = {std::vector<int>{}};   // one node with no neighbours
    EXPECT_EQ(solve(adj), adj);
}

TEST(CloneGraphTest, Empty) {
    EXPECT_EQ(solve({}), AdjList{});
}
