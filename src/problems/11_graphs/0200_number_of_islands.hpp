#pragma once
// ============================================================================
// 200. Number of Islands                                           [Medium]
// https://leetcode.com/problems/number-of-islands/
// Lists:   Blind 75, NeetCode 150
// Pattern: Graphs
// ----------------------------------------------------------------------------
// Given a grid of '1' (land) and '0' (water), return the number of islands.
// An island is land connected horizontally or vertically (not diagonally), and
// everything outside the grid is water.
//
// Example 1: grid = [[1,1,1,1,0],
//                    [1,1,0,1,0],
//                    [1,1,0,0,0],
//                    [0,0,0,0,0]]  ->  1
// Example 2: grid = [[1,1,0,0,0],
//                    [1,1,0,0,0],
//                    [0,0,1,0,0],
//                    [0,0,0,1,1]]  ->  3
//
// Constraints: 1 <= rows, cols <= 300; each cell is '0' or '1'.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0200 {

class Solution {
public:
    // TODO: not implemented yet
    int numIslands(std::vector<std::vector<char>>& grid) {
        throw std::logic_error("lc0200::numIslands not implemented");
    }
};

}  // namespace lc0200
