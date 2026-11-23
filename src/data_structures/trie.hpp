#pragma once

#include <stdexcept>
#include <string>

// Prefix tree over lowercase words 'a'-'z'. children[c - 'a'] is the child for letter c.

struct TrieNode {
    TrieNode* children[26] = {};
    bool is_end = false;   // true if a word ends at this node
};

class Trie {
public:
    Trie() : root(new TrieNode()) {}

    ~Trie() {
        // TODO: free every node below root here
        delete root;
    }

    // Disable copying (the default copy would share nodes and double-free them)
    Trie(const Trie& other) = delete;
    Trie& operator=(const Trie& other) = delete;

    // TODO: not implemented yet
    void insert(const std::string& word) {
        throw std::logic_error("Trie::insert not implemented");
    }

    // TODO: not implemented yet
    // True only if this exact word was inserted.
    bool search(const std::string& word) const {
        throw std::logic_error("Trie::search not implemented");
    }

    // TODO: not implemented yet
    // True if any inserted word starts with prefix.
    bool starts_with(const std::string& prefix) const {
        throw std::logic_error("Trie::starts_with not implemented");
    }

private:
    TrieNode* root;
};
