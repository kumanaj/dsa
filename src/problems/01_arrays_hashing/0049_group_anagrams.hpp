#pragma once
// ============================================================================
// 49. Group Anagrams                                               [Medium]
// https://leetcode.com/problems/group-anagrams/
// Lists:   Blind 75, NeetCode 150
// Pattern: Arrays & Hashing
// ----------------------------------------------------------------------------
// Given a list of strings, group together the strings that are anagrams of
// each other. Return the groups in any order; the strings within a group can
// also be in any order.
//
// Example 1: strs = ["eat","tea","tan","ate","nat","bat"]
//            ->  [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2: strs = [""]   ->  [[""]]
// Example 3: strs = ["a"]  ->  [["a"]]
//
// Constraints: 1 <= strs.length <= 10^4; 0 <= strs[i].length <= 100;
//              lowercase English letters.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>
#include <vector>

namespace lc0049 {

class Solution {
public:
    // TODO: not implemented yet
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        throw std::logic_error("lc0049::groupAnagrams not implemented");
    }
};

}  // namespace lc0049
