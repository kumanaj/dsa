template <class T>
struct BstNode {
    T key;
    BstNode *left, *right, *parent;
    BstNode(T data) : key(data), left(nullptr), right(nullptr), parent(nullptr) {}
};
