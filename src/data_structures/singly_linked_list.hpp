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
    Node(const T& item) : data(item), next(nullptr) {} // We can also use std::move(item) here.
};

template <typename T>
class SinglyLinkedList {
public:
    SinglyLinkedList() : head(nullptr), count(0) { }
    ~SinglyLinkedList();

    // Disable copying (the default copy would share nodes and double-free them)
    SinglyLinkedList(const SinglyLinkedList<T>& other) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList<T>& other) = delete;

    size_t size() const { return count; }
    bool empty() const { return count == 0; }

    void push_front(const T item);
    void push_back(const T item);
    T pop_front();
    T pop_back();
    T& get(size_t index) const;
    T& operator[] (size_t index);
    std::optional<T> front() const;
    std::optional<T> back() const;
    void clear();
protected:
    Node<T> *head;
    size_t count;
};

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template<typename T>
void SinglyLinkedList<T>::push_front(const T item) {
    Node<T>* node = new Node<T>(item); //We can use Node<T>(std::move(item)) here...
    node->next = head;
    head = node;
    count++;
}

template<typename T>
void SinglyLinkedList<T>::push_back(const T item) {
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

template<typename T>
T SinglyLinkedList<T>::pop_front() {
    if(!head || (count == 0)) {
        throw std::underflow_error("LinkList has no items.");
    }
    Node<T>* temp = head;
    head = head->next;
    T data = temp->data;
    delete temp;
    --count;
    return data;
}

template<typename T>
T SinglyLinkedList<T>::pop_back() {
    if (count == 0) {
        throw std::underflow_error("LinkList has no items.");
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

template<typename T>
T& SinglyLinkedList<T>::get(size_t index) const {
    assert((index >= 0)&& (index < count));
    Node<T>* curr = head;
    for (size_t i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

template<typename T>
T& SinglyLinkedList<T>::operator[] (size_t index) {
    return get(index);
}

template<typename T>
std::optional<T> SinglyLinkedList<T>::front() const {
    return (count > 0) ? std::optional<T>{get(0)} : std::nullopt;
}

template<typename T>
std::optional<T> SinglyLinkedList<T>::back() const {
    return (count > 0) ? std::optional<T>{get(count - 1)} : std::nullopt;
}

template<typename T>
void SinglyLinkedList<T>::clear() {
    Node<T>* curr = head;
    while (curr != nullptr) {
        Node<T>* next = curr->next;
        delete curr;
        curr = next;
        count--;
    }
    head = nullptr;
}

