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
//   Approach: scan every cell; on an unvisited '1', count an island and flood
//             it with recursive DFS (4 directions), marking cells in `visited`.
//             Recursion can go ~rows*cols deep (300x300 all land overflows the
//             stack in Debug/ASan builds); an explicit stack or BFS avoids it.
//   Time: O(m*n)   Space: O(m*n) for visited + recursion stack
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0200 {

class Solution {
public:
    void dfs(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& visited, int src_row, int src_col) {
        if (src_row < 0 || src_row >= grid.size()) return;
        if (src_col < 0 || src_col >= grid[0].size()) return;
        if (grid[src_row][src_col] == '0' || visited[src_row][src_col]) return;

        visited[src_row][src_col] = true;
        
        dfs(grid, visited, src_row + 1, src_col);
        dfs(grid, visited, src_row, src_col + 1);
        dfs(grid, visited, src_row - 1, src_col);
        dfs(grid, visited, src_row, src_col - 1);
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        int islands = 0;
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1' && !visited[r][c]) {
                    dfs(grid, visited, r, c);
                    islands++;
                }
            }
        }

        return islands;
    }
};

}  // namespace lc0200
