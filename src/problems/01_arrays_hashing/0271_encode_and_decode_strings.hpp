#pragma once
// ============================================================================
// 271. Encode and Decode Strings                                   [Medium]
// https://leetcode.com/problems/encode-and-decode-strings/  (LeetCode Premium)
// Free version: https://neetcode.io/problems/string-encode-and-decode
// Lists:   Blind 75, NeetCode 150
// Pattern: Arrays & Hashing
// ----------------------------------------------------------------------------
// Design an encoding that turns a list of strings into a single string, and a
// decoding that turns that string back into the original list. The strings
// can contain any characters, including whatever you pick as a delimiter,
// so decode(encode(strs)) must equal strs for every input.
//
// Example 1: ["neet","code","love","you"]  ->  encode  ->  decode  ->  same list
// Example 2: ["we","say",":","yes"]        ->  encode  ->  decode  ->  same list
//
// Constraints: 0 <= strs.length < 100; 0 <= strs[i].length < 200;
//              any of the 256 ASCII characters.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>
#include <vector>

namespace lc0271 {

// Same shape as NeetCode's version (LeetCode's premium version calls this class Codec).
class Solution {
public:
    // TODO: not implemented yet
    std::string encode(std::vector<std::string>& strs) {
        throw std::logic_error("lc0271::encode not implemented");
    }

    // TODO: not implemented yet
    std::vector<std::string> decode(std::string s) {
        throw std::logic_error("lc0271::decode not implemented");
    }
};

}  // namespace lc0271
