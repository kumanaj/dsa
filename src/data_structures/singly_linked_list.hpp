#pragma once

#include <cassert>
#include <cstddef>
#include <optional>
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node() : next(nullptr) {}
    Node(const T& item) : data(item), next(nullptr) {} // Copies item; a T&& overload could std::move it instead.
};

template <typename T>
class SinglyLinkedList {
public:
    SinglyLinkedList() : head(nullptr), count(0) { }

    ~SinglyLinkedList() {
        clear();
    }

    // Disable copying (the default copy would share nodes and double-free them)
    SinglyLinkedList(const SinglyLinkedList<T>& other) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList<T>& other) = delete;

    size_t size() const { return count; }
    bool empty() const { return count == 0; }

    void push_front(const T& item) {
        Node<T>* node = new Node<T>(item);
        node->next = head;
        head = node;
        count++;
    }

    void push_back(const T& item) {
        Node<T>* node = new Node<T>(item);
        if (!head) {
            head = node;
        } else {
            Node<T>* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = node;
        }
        count++;
    }

    T pop_front() {
        if(!head || (count == 0)) {
            throw std::underflow_error("SinglyLinkedList has no items.");
        }
        Node<T>* temp = head;
        head = head->next;
        T data = temp->data;
        delete temp;
        --count;
        return data;
    }

    T pop_back() {
        if (count == 0) {
            throw std::underflow_error("SinglyLinkedList has no items.");
        }
        T data;
        if (head->next == nullptr) {
            data = head->data;
            delete head;
            head = nullptr;
        } else {
            Node<T>* curr = head;
            while (curr->next->next) {
                curr = curr->next;
            }
            data = curr->next->data;
            delete curr->next;
            curr->next = nullptr;
        }
        count--;
        return data;
    }

    T& get(size_t index) {
        return node_at(index)->data;
    }

    const T& get(size_t index) const {
        return node_at(index)->data;
    }

    T& operator[] (size_t index) {
        return get(index);
    }

    const T& operator[] (size_t index) const {
        return get(index);
    }

    std::optional<T> front() const {
        return (count > 0) ? std::optional<T>{get(0)} : std::nullopt;
    }

    std::optional<T> back() const {
        return (count > 0) ? std::optional<T>{get(count - 1)} : std::nullopt;
    }

    void clear() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            Node<T>* next = curr->next;
            delete curr;
            curr = next;
            count--;
        }
        head = nullptr;
    }

private:
    // Walk to position index (shared by both versions of get).
    Node<T>* node_at(size_t index) const {
        assert(index < count);
        Node<T>* curr = head;
        for (size_t i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr;
    }

    Node<T> *head;
    size_t count;
};
