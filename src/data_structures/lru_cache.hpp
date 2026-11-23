#pragma once

#include <cstddef>
#include <optional>
#include <stdexcept>
#include <unordered_map>

// LRU cache (LeetCode 146): get and put in O(1).
// A hash map finds a key's node; a doubly linked list keeps nodes in recency order.
// dummy is a sentinel like in DoublyLinkedList: dummy->next is the most recently used,
// dummy->prev the least recently used.

struct LruNode {
    int key;
    int value;
    LruNode* prev;
    LruNode* next;

    LruNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LruCache {
public:
    explicit LruCache(size_t capacity) : capacity(capacity), dummy(new LruNode(0, 0)) {
        dummy->next = dummy;
        dummy->prev = dummy;
    }

    ~LruCache() {
        // TODO: free every cached node here
        delete dummy;
    }

    // Disable copying (the default copy would share nodes and double-free them)
    LruCache(const LruCache& other) = delete;
    LruCache& operator=(const LruCache& other) = delete;

    size_t size() const { return nodes.size(); }

    // TODO: not implemented yet
    // Value for key (and mark it most recently used), or nullopt if missing.
    std::optional<int> get(int key) {
        throw std::logic_error("LruCache::get not implemented");
    }

    // TODO: not implemented yet
    // Insert or update key and mark it most recently used. Evict the least recently used key if over capacity.
    void put(int key, int value) {
        throw std::logic_error("LruCache::put not implemented");
    }

private:
    size_t capacity;
    std::unordered_map<int, LruNode*> nodes;
    LruNode* dummy;

    // TODO: not implemented yet
    // Take node out of the list (without deleting it).
    void unlink(LruNode* node) {
        throw std::logic_error("LruCache::unlink not implemented");
    }

    // TODO: not implemented yet
    // Insert node right after dummy (most recently used position).
    void push_front(LruNode* node) {
        throw std::logic_error("LruCache::push_front not implemented");
    }
};
