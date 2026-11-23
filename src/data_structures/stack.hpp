#pragma once

#include <cstddef>
#include <optional>
#include <stdexcept>

// LIFO stack built on singly linked nodes: push and pop both happen at head, so they're O(1).

template <typename T>
struct StackNode {
    T data;
    StackNode* next;

    StackNode(const T& item) : data(item), next(nullptr) {}
};

template <typename T>
class Stack {
public:
    Stack() : head(nullptr), count(0) {}

    ~Stack() {
        // TODO: free every node here (call clear() once it is implemented)
    }

    // Disable copying (the default copy would share nodes and double-free them)
    Stack(const Stack<T>& other) = delete;
    Stack& operator=(const Stack<T>& other) = delete;

    size_t size() const { return count; }
    bool empty() const { return count == 0; }

    // TODO: not implemented yet
    void push(const T& item) {
        throw std::logic_error("Stack::push not implemented");
    }

    // TODO: not implemented yet
    T pop() {
        throw std::logic_error("Stack::pop not implemented");
    }

    // TODO: not implemented yet
    std::optional<T> top() const {
        throw std::logic_error("Stack::top not implemented");
    }

    // TODO: not implemented yet
    void clear() {
        throw std::logic_error("Stack::clear not implemented");
    }

private:
    StackNode<T>* head;  // top of the stack
    size_t count;
};
