#pragma once

#include <cstddef>
#include <functional>
#include <optional>
#include <stdexcept>
#include <vector>

// Hash map with separate chaining: each bucket is a singly linked list of HashNodes.
// When count / buckets.size() goes above MAX_LOAD_FACTOR, rehash into twice as many buckets.

template <typename K, typename V>
struct HashNode {
    K key;
    V value;
    HashNode* next;

    HashNode(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
};

template <typename K, typename V>
class HashMap {
public:
    HashMap() : buckets(DEFAULT_BUCKETS, nullptr), count(0) {}

    ~HashMap() {
        // TODO: free every node here (call clear() once it is implemented)
    }

    // Disable copying (the default copy would share nodes and double-free them)
    HashMap(const HashMap<K, V>& other) = delete;
    HashMap& operator=(const HashMap<K, V>& other) = delete;

    size_t size() const { return count; }
    bool empty() const { return count == 0; }

    // TODO: not implemented yet
    // Insert the key, or overwrite its value if it is already present.
    void put(const K& key, const V& value) {
        throw std::logic_error("HashMap::put not implemented");
    }

    // TODO: not implemented yet
    std::optional<V> get(const K& key) const {
        throw std::logic_error("HashMap::get not implemented");
    }

    // TODO: not implemented yet
    bool contains(const K& key) const {
        throw std::logic_error("HashMap::contains not implemented");
    }

    // TODO: not implemented yet
    // Returns false if the key was not present.
    bool remove(const K& key) {
        throw std::logic_error("HashMap::remove not implemented");
    }

    // TODO: not implemented yet
    void clear() {
        throw std::logic_error("HashMap::clear not implemented");
    }

private:
    std::vector<HashNode<K, V>*> buckets;
    size_t count;
    static constexpr size_t DEFAULT_BUCKETS = 8;
    static constexpr double MAX_LOAD_FACTOR = 0.75;

    // TODO: not implemented yet
    // Which bucket a key belongs in (hint: std::hash<K>{}(key)).
    size_t bucket_index(const K& key) const {
        throw std::logic_error("HashMap::bucket_index not implemented");
    }

    // TODO: not implemented yet
    void rehash() {
        throw std::logic_error("HashMap::rehash not implemented");
    }
};
