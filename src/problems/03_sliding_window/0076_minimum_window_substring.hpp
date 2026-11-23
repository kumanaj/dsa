#pragma once
// ============================================================================
// 76. Minimum Window Substring                                       [Hard]
// https://leetcode.com/problems/minimum-window-substring/
// Lists:   Blind 75, NeetCode 150
// Pattern: Sliding Window
// ----------------------------------------------------------------------------
// Given strings s and t, return the shortest substring of s that contains every
// character of t, including duplicates (t = "aa" needs two a's). Return "" if
// no such substring exists. The answer is guaranteed to be unique.
//
// Example 1: s = "ADOBECODEBANC", t = "ABC"  ->  "BANC"
// Example 2: s = "a",             t = "a"    ->  "a"
// Example 3: s = "a",             t = "aa"   ->  ""
//
// Constraints: 1 <= s.length, t.length <= 10^5; uppercase and lowercase English letters.
// Follow-up:   O(m + n) time.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>

namespace lc0076 {

class Solution {
public:
    // TODO: not implemented yet
    std::string minWindow(std::string s, std::string t) {
        throw std::logic_error("lc0076::minWindow not implemented");
    }
};

}  // namespace lc0076
