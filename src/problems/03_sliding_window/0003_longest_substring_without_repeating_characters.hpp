#pragma once
// ============================================================================
// 3. Longest Substring Without Repeating Characters                [Medium]
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Lists:   Blind 75, NeetCode 150
// Pattern: Sliding Window
// ----------------------------------------------------------------------------
// Given a string, return the length of the longest substring (contiguous
// characters) in which no character appears twice.
//
// Example 1: s = "abcabcbb"  ->  3   ("abc")
// Example 2: s = "bbbbb"     ->  1   ("b")
// Example 3: s = "pwwkew"    ->  3   ("wke"; "pwke" is a subsequence, not a substring)
//
// Constraints: 0 <= s.length <= 5 * 10^4; letters, digits, symbols and spaces.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>

namespace lc0003 {

class Solution {
public:
    // TODO: not implemented yet
    int lengthOfLongestSubstring(std::string s) {
        throw std::logic_error("lc0003::lengthOfLongestSubstring not implemented");
    }
};

}  // namespace lc0003
