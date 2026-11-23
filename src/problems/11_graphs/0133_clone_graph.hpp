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
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

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
    // TODO: not implemented yet
    Node* cloneGraph(Node* node) {
        throw std::logic_error("lc0133::cloneGraph not implemented");
    }
};

}  // namespace lc0133
