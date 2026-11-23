#pragma once
// ============================================================================
// 91. Decode Ways                                                  [Medium]
// https://leetcode.com/problems/decode-ways/
// Lists:   Blind 75, NeetCode 150
// Pattern: 1-D Dynamic Programming
// ----------------------------------------------------------------------------
// Letters are encoded as numbers: 'A' -> "1", 'B' -> "2", ..., 'Z' -> "26".
// Given a string of digits, return how many ways it can be decoded back into
// letters. A group with a leading zero ("06") is not a valid code, so some
// strings have 0 decodings. The answer fits in a 32-bit integer.
//
// Example 1: s = "12"   ->  2   ("AB" from 1 2, "L" from 12)
// Example 2: s = "226"  ->  3   (2 2 6, 22 6, 2 26)
// Example 3: s = "06"   ->  0
//
// Constraints: 1 <= s.length <= 100; digits only, possibly with leading zeros.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>

namespace lc0091 {

class Solution {
public:
    // TODO: not implemented yet
    int numDecodings(std::string s) {
        throw std::logic_error("lc0091::numDecodings not implemented");
    }
};

}  // namespace lc0091
