#pragma once
#include <stdexcept>
#include <optional>

template <typename T>
class LinkedList {
public:
    struct Node {
        T data;
        Node* next = nullptr;
        Node(T val) : data(std::move(val)) {}
    };

    LinkedList() = default;
    ~LinkedList() { clear(); }
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_front(T value);
    void push_back(T value);
    void pop_front();
    std::optional<T> front() const;
    bool   empty() const { return head == nullptr; }
    size_t size()  const { return size; }
    void clear();

private:
    Node*  head = nullptr;
    Node*  tail = nullptr;
    size_t size = 0;
};

template <typename T>
void LinkedList<T>::push_front(T value) {
    auto* n = new Node(std::move(value));
    n->next = head;
    head = n;
    if (!tail) tail = head;
    ++size;
}

template <typename T>
void LinkedList<T>::push_back(T value) {
    auto* n = new Node(std::move(value));
    if (tail) { 
        tail->next = n;
    } else {
        head = n;
    }
    tail = n; ++size;
}

template <typename T>
void LinkedList<T>::pop_front() {
    if (!head) throw std::underflow_error("List is empty");
    Node* old = head;
    head = head->next;
    if (!head) tail = nullptr;
    delete old; --size;
}

template <typename T>
std::optional<T> LinkedList<T>::front() const {
    return head ? std::optional<T>{head->data} : std::nullopt;
}

template <typename T>
void LinkedList<T>::clear() {
    while (head) { 
        Node* next = head->next;
        delete head;
        head = next; 
    }
    tail = nullptr;
    size = 0;
}
