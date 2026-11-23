#pragma once
// ============================================================================
// 211. Design Add and Search Words Data Structure                  [Medium]
// https://leetcode.com/problems/design-add-and-search-words-data-structure/
// Lists:   Blind 75, NeetCode 150
// Pattern: Tries
// ----------------------------------------------------------------------------
// Implement a WordDictionary class:
//   WordDictionary()   creates an empty dictionary.
//   addWord(word)      adds word.
//   search(word)       true if some added word matches word, where each '.'
//                      in word matches any single letter.
//
// Example: addWord("bad"); addWord("dad"); addWord("mad");
//          search("pad") -> false; search("bad") -> true;
//          search(".ad") -> true;  search("b..") -> true
//
// Constraints: 1 <= word.length <= 25; addWord takes lowercase letters; search takes
//              lowercase letters or '.', with at most 2 dots; at most 10^4 calls.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>

namespace lc0211 {

class WordDictionary {
public:
    // TODO: not implemented yet
    WordDictionary() {
        throw std::logic_error("lc0211::WordDictionary::WordDictionary not implemented");
    }

    // TODO: not implemented yet
    void addWord(std::string word) {
        throw std::logic_error("lc0211::WordDictionary::addWord not implemented");
    }

    // TODO: not implemented yet
    bool search(std::string word) {
        throw std::logic_error("lc0211::WordDictionary::search not implemented");
    }
};

}  // namespace lc0211
