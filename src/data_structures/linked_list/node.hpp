template <class T>
struct Node {
    T data;
    Node* next;

    Node() : next(nullptr) {}
    Node(const T& item) : data(item), next(nullptr) {} // We can also use std::move(item) here.
};

/*template <class T>
struct DNode {
    T data;
    DNode* prev;
    DNode* next;

    DNode() : prev(nullptr), next(nullptr) {}
    DNode(const T& item): data(item), prev(nullptr), next(nullptr) {} // We can also use std::move(item) here.
};*/