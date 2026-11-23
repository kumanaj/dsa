#pragma once
// ============================================================================
// 269. Alien Dictionary                                              [Hard]
// https://leetcode.com/problems/alien-dictionary/  (LeetCode Premium)
// Free version: https://neetcode.io/problems/foreign-dictionary
// Lists:   Blind 75, NeetCode 150
// Pattern: Advanced Graphs
// ----------------------------------------------------------------------------
// An alien language uses a subset of the lowercase English letters in an
// unknown order. You're given a list of its words, sorted in that language's
// dictionary order. Return a string containing every letter that appears in
// the words, ordered to match the alien alphabet. If several orders work,
// return any of them. If the list can't be sorted under any order (for
// example, a word comes before its own prefix), return "".
//
// Example 1: words = ["z","o"]                        ->  "zo"
// Example 2: words = ["hrn","hrf","er","enn","rfnn"]  ->  "hernf"
// Example 3: words = ["abc","ab"]                     ->  ""   ("ab" must come first)
//
// Constraints: 1 <= words.length <= 100; 1 <= words[i].length <= 100;
//              lowercase English letters.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>
#include <vector>

namespace lc0269 {

// NeetCode's version (linked above) names the method foreignDictionary; LeetCode's calls it alienOrder.

class Solution {
public:
    // TODO: not implemented yet
    std::string foreignDictionary(std::vector<std::string>& words) {
        throw std::logic_error("lc0269::foreignDictionary not implemented");
    }
};

}  // namespace lc0269
