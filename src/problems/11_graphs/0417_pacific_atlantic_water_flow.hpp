#pragma once
// ============================================================================
// 417. Pacific Atlantic Water Flow                                 [Medium]
// https://leetcode.com/problems/pacific-atlantic-water-flow/
// Lists:   Blind 75, NeetCode 150
// Pattern: Graphs
// ----------------------------------------------------------------------------
// heights is a grid of land heights. The Pacific Ocean touches the top and left
// edges, the Atlantic the bottom and right edges. Rain flows from a cell to a
// neighbouring cell (up, down, left, right) whose height is less than or equal
// to its own, and from edge cells into the ocean next to them. Return every
// cell [row, col] from which water can reach both oceans, in any order.
//
// Example 1: heights = [[1,2,2,3,5],
//                       [3,2,3,4,4],
//                       [2,4,5,3,1],
//                       [6,7,1,4,5],
//                       [5,1,1,2,4]]
//            ->  [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Example 2: heights = [[1]]  ->  [[0,0]]
//
// Constraints: 1 <= rows, cols <= 200; 0 <= heights[r][c] <= 10^5.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0417 {

class Solution {
public:
    // TODO: not implemented yet
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        throw std::logic_error("lc0417::pacificAtlantic not implemented");
    }
};

}  // namespace lc0417
