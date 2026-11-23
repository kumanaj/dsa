#pragma once
// ============================================================================
// 208. Implement Trie (Prefix Tree)                                [Medium]
// https://leetcode.com/problems/implement-trie-prefix-tree/
// Lists:   Blind 75, NeetCode 150
// Pattern: Tries
// ----------------------------------------------------------------------------
// Implement a Trie class:
//   Trie()                     creates an empty trie.
//   insert(word)               adds word.
//   search(word)               true if word was inserted.
//   startsWith(prefix)         true if any inserted word starts with prefix.
//
// Example: insert("apple"); search("apple") -> true; search("app") -> false;
//          startsWith("app") -> true; insert("app"); search("app") -> true
//
// Constraints: 1 <= word.length, prefix.length <= 2000; lowercase English letters;
//              at most 3 * 10^4 calls in total.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <string>

namespace lc0208 {

class Trie {
public:
    // TODO: not implemented yet
    Trie() {
        throw std::logic_error("lc0208::Trie::Trie not implemented");
    }

    // TODO: not implemented yet
    void insert(std::string word) {
        throw std::logic_error("lc0208::Trie::insert not implemented");
    }

    // TODO: not implemented yet
    bool search(std::string word) {
        throw std::logic_error("lc0208::Trie::search not implemented");
    }

    // TODO: not implemented yet
    bool startsWith(std::string prefix) {
        throw std::logic_error("lc0208::Trie::startsWith not implemented");
    }
};

}  // namespace lc0208
