#pragma once

#include <cstddef>
#include <optional>
#include <stdexcept>
#include <vector>

// Binary min-heap stored in an array (this is also a priority queue).
// For index i: parent is (i - 1) / 2, children are 2i + 1 and 2i + 2.
// For a max-heap, push negated values or flip the comparisons.
//
// In an interview, use std::priority_queue (<queue>). It is a MAX-heap by default:
//   std::priority_queue<int> max_heap;                                        // largest on top
//   std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;   // smallest on top
// Its pop() returns void, so read top() first. Pairs compare by .first, which is handy for
// Dijkstra-style (distance, vertex) entries in a min-heap.

template <typename T>
class MinHeap {
public:
    MinHeap() {}

    // TODO: not implemented yet
    // Build a heap from unsorted values in O(n) (heapify), not n pushes.
    explicit MinHeap(const std::vector<T>& values) : data(values) {
        throw std::logic_error("MinHeap::MinHeap(values) not implemented");
    }

    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }

    // TODO: not implemented yet
    void push(const T& item) {
        throw std::logic_error("MinHeap::push not implemented");
    }

    // TODO: not implemented yet
    // Remove and return the smallest element.
    T pop() {
        throw std::logic_error("MinHeap::pop not implemented");
    }

    // TODO: not implemented yet
    // The smallest element, without removing it.
    std::optional<T> top() const {
        throw std::logic_error("MinHeap::top not implemented");
    }

    // TODO: not implemented yet
    void clear() {
        throw std::logic_error("MinHeap::clear not implemented");
    }

private:
    std::vector<T> data;

    // TODO: not implemented yet
    void sift_up(size_t index) {
        throw std::logic_error("MinHeap::sift_up not implemented");
    }

    // TODO: not implemented yet
    void sift_down(size_t index) {
        throw std::logic_error("MinHeap::sift_down not implemented");
    }
};
