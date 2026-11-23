#pragma once

#include <stdexcept>
#include <vector>

// Disjoint set over elements 0..n-1, with path compression and union by rank.

class UnionFind {
public:
    // TODO: not implemented yet
    // Start with every element in its own set (its own parent).
    UnionFind(int n) : parent(n), rank(n, 0), components(n) {
        throw std::logic_error("UnionFind::UnionFind not implemented");
    }

    int size() const { return static_cast<int>(parent.size()); }
    int component_count() const { return components; }

    // TODO: not implemented yet
    // Root of the set containing x. Compresses the path on the way back.
    int find(int x) {
        throw std::logic_error("UnionFind::find not implemented");
    }

    // TODO: not implemented yet
    // Merge the sets containing x and y. Returns false if they were already in the same set.
    bool unite(int x, int y) {
        throw std::logic_error("UnionFind::unite not implemented");
    }

    // TODO: not implemented yet
    bool connected(int x, int y) {
        throw std::logic_error("UnionFind::connected not implemented");
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;   // upper bound on each root's tree height
    int components;          // number of separate sets
};
