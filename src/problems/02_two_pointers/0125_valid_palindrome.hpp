#pragma once
// ============================================================================
// 125. Valid Palindrome                                              [Easy]
// https://leetcode.com/problems/valid-palindrome/
// Lists:   Blind 75, NeetCode 150
// Pattern: Two Pointers
// ----------------------------------------------------------------------------
// Given a string, lowercase every letter and drop everything that isn't a
// letter or digit. Return true if what remains reads the same forwards and
// backwards.
//
// Example 1: s = "A man, a plan, a canal: Panama"  ->  true   ("amanaplanacanalpanama")
// Example 2: s = "race a car"                      ->  false  ("raceacar")
// Example 3: s = " "                               ->  true   (empty after cleanup)
//
// Constraints: 1 <= s.length <= 2 * 10^5; printable ASCII characters.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>

namespace lc0125 {

class Solution {
public:
    // TODO: not implemented yet
    bool isPalindrome(std::string s) {
        throw std::logic_error("lc0125::isPalindrome not implemented");
    }
};

}  // namespace lc0125
