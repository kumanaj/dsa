#pragma once
// ============================================================================
// 261. Graph Valid Tree                                            [Medium]
// https://leetcode.com/problems/graph-valid-tree/  (LeetCode Premium)
// Free version: https://neetcode.io/problems/valid-tree
// Lists:   Blind 75, NeetCode 150
// Pattern: Graphs
// ----------------------------------------------------------------------------
// Given n nodes labelled 0 to n - 1 and a list of undirected edges, return true
// if the edges make a valid tree: every node is connected and there are no
// cycles.
//
// Example 1: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]        ->  true
// Example 2: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]  ->  false   (1-2-3 is a cycle)
//
// Constraints: 1 <= n <= 2000; 0 <= edges.length <= 5000; no self-loops or repeated edges.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0261 {

class Solution {
public:
    // TODO: not implemented yet
    bool validTree(int n, std::vector<std::vector<int>>& edges) {
        throw std::logic_error("lc0261::validTree not implemented");
    }
};

}  // namespace lc0261
