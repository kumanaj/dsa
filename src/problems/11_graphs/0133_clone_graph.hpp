#pragma once
// ============================================================================
// 133. Clone Graph                                                 [Medium]
// https://leetcode.com/problems/clone-graph/
// Lists:   Blind 75, NeetCode 150
// Pattern: Graphs
// ----------------------------------------------------------------------------
// Given a reference to one node of a connected, undirected graph, return a deep
// copy of the whole graph: brand-new nodes with the same values and the same
// neighbour connections. In the examples, the graph is written as an adjacency
// list where list i holds the neighbours of the node with value i + 1, and the
// given node is the one with value 1.
//
// Example 1: adjList = [[2,4],[1,3],[2,4],[1,3]]  ->  [[2,4],[1,3],[2,4],[1,3]]
// Example 2: adjList = [[]]                       ->  [[]]   (one node, no edges)
// Example 3: adjList = []                         ->  []     (node is nullptr)
//
// Constraints: 0 <= number of nodes <= 100; node values are 1..n and unique;
//              no repeated edges or self-loops; the graph is connected.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach: clone node and add to map if it does not exist.
//             then clone each neighbour.
//   Time: O(V + E)   Space: O(V) for the map + recursion stack
// ============================================================================

#include <stdexcept>
#include <vector>
#include <unordered_map>

namespace lc0133 {

// LeetCode's node for this problem.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() { val = 0; neighbors = std::vector<Node*>(); }
    Node(int _val) { val = _val; neighbors = std::vector<Node*>(); }
    Node(int _val, std::vector<Node*> _neighbors) { val = _val; neighbors = _neighbors; }
};

class Solution {
public:
    Node* clone_node(Node* node, std::unordered_map<Node *, Node *>& clone_map) {
        if (node == nullptr) return nullptr;

        auto it = clone_map.find(node);
        if (it != clone_map.end()) {
            return it->second;
        }

        Node* cloned_node = new Node(node->val);
        clone_map.emplace(node, cloned_node);
        for (Node* neighbour : node->neighbors) {
            Node* cloned_neighbour = clone_node(neighbour, clone_map);
            cloned_node->neighbors.emplace_back(cloned_neighbour);
        }
        return cloned_node;
    }

    Node* cloneGraph(Node* node) {
        std::unordered_map<Node *, Node *> clone_map;
        return clone_node(node, clone_map);
    }
};

}  // namespace lc0133
