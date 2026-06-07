template <class T>
struct Node {
    T data;
    Node* next;

    Node() : next(nullptr) {}
    Node(const T& item) : data(item), next(nullptr) {} // We can also use std::move(item) here.
};