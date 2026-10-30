template <class T>
struct DNode {
    T data;
    DNode* prev;
    DNode* next;

    DNode() : prev(nullptr), next(nullptr) {}
    DNode(const T& item): data(item), prev(nullptr), next(nullptr) {} // We can also use std::move(item) here.
};