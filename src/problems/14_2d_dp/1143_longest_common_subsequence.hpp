#pragma once
// ============================================================================
// 1143. Longest Common Subsequence                                 [Medium]
// https://leetcode.com/problems/longest-common-subsequence/
// Lists:   Blind 75, NeetCode 150
// Pattern: 2-D Dynamic Programming
// ----------------------------------------------------------------------------
// Given two strings, return the length of their longest common subsequence: the
// longest sequence of characters that appears in both, in the same order but
// not necessarily next to each other. Return 0 if they share none.
//
// Example 1: text1 = "abcde", text2 = "ace"  ->  3   ("ace")
// Example 2: text1 = "abc",   text2 = "abc"  ->  3
// Example 3: text1 = "abc",   text2 = "def"  ->  0
//
// Constraints: 1 <= text1.length, text2.length <= 1000; lowercase English letters.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>

namespace lc1143 {

class Solution {
public:
    // TODO: not implemented yet
    int longestCommonSubsequence(std::string text1, std::string text2) {
        throw std::logic_error("lc1143::longestCommonSubsequence not implemented");
    }
};

}  // namespace lc1143
