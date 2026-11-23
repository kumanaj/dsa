#pragma once
// ============================================================================
// 73. Set Matrix Zeroes                                            [Medium]
// https://leetcode.com/problems/set-matrix-zeroes/
// Lists:   Blind 75, NeetCode 150
// Pattern: Math & Geometry
// ----------------------------------------------------------------------------
// Given an m x n matrix, wherever an element is 0, set its entire row and
// column to 0. Do it in place. Only zeros in the original matrix count, not
// the ones you write.
//
// Example 1: matrix = [[1,1,1],[1,0,1],[1,1,1]]          ->  [[1,0,1],[0,0,0],[1,0,1]]
// Example 2: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]    ->  [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
//
// Constraints: 1 <= m, n <= 200; -2^31 <= matrix[i][j] <= 2^31 - 1.
// Follow-up:   O(m*n) extra space is easy, O(m + n) is better. Can you do it with O(1)
//              extra space?
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0073 {

class Solution {
public:
    // TODO: not implemented yet
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        throw std::logic_error("lc0073::setZeroes not implemented");
    }
};

}  // namespace lc0073
