#pragma once

#include <cassert>
#include <cstddef>
#include <optional>
#include <stdexcept>

template <typename T>
struct DNode {
    T data;
    DNode* prev;
    DNode* next;

    DNode() : prev(nullptr), next(nullptr) {}
    DNode(const T& item): data(item), prev(nullptr), next(nullptr) {} // We can also use std::move(item) here.
};

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList() : count(0) {
        dummy = new DNode<T>();
        dummy->next = dummy;
        dummy->prev = dummy;
    }
    ~DoublyLinkedList();

    // Disable copying (the default copy would share nodes and double-free them)
    DoublyLinkedList(const DoublyLinkedList<T>& other) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList<T>& other) = delete;

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
    DNode<T> *dummy;
    size_t count;
};

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
    delete dummy;
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T item) {
    DNode<T>* node = new DNode<T>(item);

    // Link the new node with the dummy node and the first node
    node->next = dummy->next;
    node->prev = dummy;
    dummy->next->prev = node;
    dummy->next = node;

    count++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T item) {
    DNode<T>* node = new DNode<T>(item);

    // Link the new node with the last node and the dummy node
    node->next = dummy;
    node->prev = dummy->prev;
    dummy->prev->next = node;
    dummy->prev = node;

    count++;
}

template<typename T>
T DoublyLinkedList<T>::pop_front() {
    if(count == 0) {
        throw std::underflow_error("LinkList has no items.");
    }

    DNode<T>* temp = dummy->next;
    T data = temp->data;

    // Update dummy-next (head)
    dummy->next = temp->next;
    dummy->next->prev = dummy;

    delete temp;
    --count;
    return data;
}

template<typename T>
T DoublyLinkedList<T>::pop_back() {
    if(count == 0) {
        throw std::underflow_error("LinkList has no items.");
    }
    DNode<T>* temp = dummy->prev;
    T data = temp->data;

    // Update dummy->prev (tail)
    dummy->prev = temp->prev;
    dummy->prev->next = dummy;
    delete temp;
    --count;
    return data;

}

template<typename T>
T& DoublyLinkedList<T>::get(size_t index) const {
    assert((index >= 0)&& (index < count));
    DNode<T>* curr = dummy->next;
    for (size_t i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

template<typename T>
T& DoublyLinkedList<T>::operator[] (size_t index) {
    return get(index);
}

template<typename T>
std::optional<T> DoublyLinkedList<T>::front() const {
    return (count > 0) ? std::optional<T>{get(0)} : std::nullopt;
}

template<typename T>
std::optional<T> DoublyLinkedList<T>::back() const {
    return (count > 0) ? std::optional<T>{get(count - 1)} : std::nullopt;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    DNode<T>* curr = dummy->next;
    while (curr != dummy) {
        DNode<T>* next = curr->next;
        delete curr;
        curr = next;
        count--;
    }
    // Point the sentinel back at itself, otherwise it still references the deleted nodes.
    dummy->next = dummy;
    dummy->prev = dummy;
}
