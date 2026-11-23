#pragma once
// ============================================================================
// 323. Number of Connected Components in an Undirected Graph       [Medium]
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/  (LeetCode Premium)
// Free version: https://neetcode.io/problems/count-connected-components
// Lists:   Blind 75, NeetCode 150
// Pattern: Graphs
// ----------------------------------------------------------------------------
// Given n nodes labelled 0 to n - 1 and a list of undirected edges, return the
// number of connected components (groups of nodes reachable from each other).
//
// Example 1: n = 5, edges = [[0,1],[1,2],[3,4]]        ->  2
// Example 2: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]  ->  1
//
// Constraints: 1 <= n <= 2000; 1 <= edges.length <= 5000; no repeated edges.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0323 {

class Solution {
public:
    // TODO: not implemented yet
    int countComponents(int n, std::vector<std::vector<int>>& edges) {
        throw std::logic_error("lc0323::countComponents not implemented");
    }
};

}  // namespace lc0323
