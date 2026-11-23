#pragma once
// ============================================================================
// 212. Word Search II                                                [Hard]
// https://leetcode.com/problems/word-search-ii/
// Lists:   Blind 75, NeetCode 150
// Pattern: Tries
// ----------------------------------------------------------------------------
// Given a grid of letters and a list of words, return every word that can be
// spelled by a path through the grid. Each step moves to a horizontally or
// vertically adjacent cell, and a cell can't be used twice in the same word.
// Return each found word once, in any order.
//
// Example 1: board = [[o,a,a,n],
//                     [e,t,a,e],
//                     [i,h,k,r],
//                     [i,f,l,v]],  words = [oath,pea,eat,rain]  ->  [eat,oath]
// Example 2: board = [[a,b],[c,d]], words = [abcb]               ->  []
//
// Constraints: 1 <= rows, cols <= 12; lowercase letters; 1 <= words.length <= 3 * 10^4;
//              1 <= words[i].length <= 10; words are unique.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>
#include <vector>

namespace lc0212 {

class Solution {
public:
    // TODO: not implemented yet
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        throw std::logic_error("lc0212::findWords not implemented");
    }
};

}  // namespace lc0212
