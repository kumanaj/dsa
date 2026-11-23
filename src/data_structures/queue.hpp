#pragma once

#include <cstddef>
#include <optional>
#include <stdexcept>

// FIFO queue on a circular buffer. Elements live at arr[head], arr[(head + 1) % capacity], ...
// The buffer grows when it is full.

template <typename T>
class Queue {
public:
    Queue() :
        arr(new T[DEFAULT_CAPACITY]),
        capacity(DEFAULT_CAPACITY),
        head(0),
        count(0) {}

    Queue(size_t initial_capacity) :
        arr(new T[initial_capacity]),
        capacity(initial_capacity),
        head(0),
        count(0) {}

    ~Queue() {
        delete [] arr;
    }

    // Disable copying (the default copy would share arr and double-free it)
    Queue(const Queue<T>& other) = delete;
    Queue& operator=(const Queue<T>& other) = delete;

    size_t size() const { return count; }
    bool empty() const { return count == 0; }

    // TODO: not implemented yet
    void push(const T item) {
        throw std::logic_error("Queue::push not implemented");
    }

    // TODO: not implemented yet
    T pop() {
        throw std::logic_error("Queue::pop not implemented");
    }

    // TODO: not implemented yet
    std::optional<T> front() const {
        throw std::logic_error("Queue::front not implemented");
    }

    // TODO: not implemented yet
    std::optional<T> back() const {
        throw std::logic_error("Queue::back not implemented");
    }

    // TODO: not implemented yet
    void clear() {
        throw std::logic_error("Queue::clear not implemented");
    }

private:
    T* arr;
    size_t capacity;
    size_t head;   // index of the front element
    size_t count;
    static constexpr size_t DEFAULT_CAPACITY = 8;

    // TODO: not implemented yet
    // Grow the buffer when it is full, copying elements so the front ends up at index 0.
    void resize() {
        throw std::logic_error("Queue::resize not implemented");
    }
};
