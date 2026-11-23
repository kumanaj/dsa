#pragma once
// ============================================================================
// 139. Word Break                                                  [Medium]
// https://leetcode.com/problems/word-break/
// Lists:   Blind 75, NeetCode 150
// Pattern: 1-D Dynamic Programming
// ----------------------------------------------------------------------------
// Given a string s and a dictionary of words, return true if s can be split
// into a sequence of one or more dictionary words. Words can be reused.
//
// Example 1: s = "leetcode",      wordDict = ["leet","code"]                   ->  true
// Example 2: s = "applepenapple", wordDict = ["apple","pen"]                   ->  true
// Example 3: s = "catsandog",     wordDict = ["cats","dog","sand","and","cat"] ->  false
//
// Constraints: 1 <= s.length <= 300; 1 <= wordDict.length <= 1000;
//              1 <= wordDict[i].length <= 20; lowercase letters; words are unique.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>
#include <vector>

namespace lc0139 {

class Solution {
public:
    // TODO: not implemented yet
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        throw std::logic_error("lc0139::wordBreak not implemented");
    }
};

}  // namespace lc0139
