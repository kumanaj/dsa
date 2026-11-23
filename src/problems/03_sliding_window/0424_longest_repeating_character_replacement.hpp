#pragma once
// ============================================================================
// 424. Longest Repeating Character Replacement                     [Medium]
// https://leetcode.com/problems/longest-repeating-character-replacement/
// Lists:   Blind 75, NeetCode 150
// Pattern: Sliding Window
// ----------------------------------------------------------------------------
// Given a string of uppercase letters and an integer k, you may change at most
// k characters to any other uppercase letter. Return the length of the longest
// substring that can be made of a single repeated letter.
//
// Example 1: s = "ABAB",    k = 2  ->  4   (change both A's or both B's)
// Example 2: s = "AABABBA", k = 1  ->  4   ("AABA" -> "AAAA")
//
// Constraints: 1 <= s.length <= 10^5; uppercase English letters; 0 <= k <= s.length.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>

namespace lc0424 {

class Solution {
public:
    // TODO: not implemented yet
    int characterReplacement(std::string s, int k) {
        throw std::logic_error("lc0424::characterReplacement not implemented");
    }
};

}  // namespace lc0424
