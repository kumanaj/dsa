#pragma once
// ============================================================================
// 79. Word Search                                                  [Medium]
// https://leetcode.com/problems/word-search/
// Lists:   Blind 75, NeetCode 150
// Pattern: Backtracking
// ----------------------------------------------------------------------------
// Given a grid of letters and a word, return true if the word can be spelled
// by a path through the grid. Each step moves to a horizontally or vertically
// adjacent cell, and a cell can't be used twice.
//
// board = [[A,B,C,E],
//          [S,F,C,S],
//          [A,D,E,E]]
// Example 1: word = "ABCCED"  ->  true
// Example 2: word = "SEE"     ->  true
// Example 3: word = "ABCB"    ->  false   (would reuse the B)
//
// Constraints: 1 <= rows, cols <= 6; 1 <= word.length <= 15; upper and lowercase letters.
// Follow-up:   can you prune the search so it's faster on larger boards?
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>
#include <vector>

namespace lc0079 {

class Solution {
public:
    // TODO: not implemented yet
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        throw std::logic_error("lc0079::exist not implemented");
    }
};

}  // namespace lc0079
