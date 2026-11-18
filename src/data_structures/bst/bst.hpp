#include "bst_node.hpp"

template <typename T>
class BinarySearchTree : public ITree<BstNode<T>, T> {

public:
    virtual BinarySearchTree() {}
    virtual ~BinarySearchTree() {}

    virtual void insert(const T);
    virtual void remove(const T);
    virtual BstNode<T>* search(const T) const;
    virtual BstNode<T>* get_root() const;
    virtual BstNode<T>* get_min() const;
    virtual BstNode<T>* get_max() const;
    virtual void traverse() const;
    virtual int depth(BstNode<T>* node) const;
    virtual int height(BstNode<T>* node) const;
    virtual int height() const;
    virtual int size(BstNode<T>* node) const;
    virtual void size() const;
    virtual void clear();

private:
    BstNode<T> *root;
    BstNode<T>* insert_node(BstNode<T>* node, T key);
    BstNode<T>* remove_node(BstNode<T>* node, T key);
    BstNode<T>* search_node(BstNode<T>* node, T key) const;
    BstNode<T>* get_min_node(BstNode<T>* node) const;
    BstNode<T>* get_max_node(BstNode<T>* node) const;
    void traverse_node(BstNode<T>* node) const;
    void delete_subtree(BstNode<T>* node) const;
};

template <typename T>
void BinarySearchTree<T>::insert(const T key) {
    root = insert_node(key);
}

template <typename T>
BstNode<T>* insert_node(BstNode<T>* node, T key) {
    if (node == nullptr) {
        return new BstNode<T>(key);
    } else if (key < node->left) {
        node->left = insert_node(node->left, key);
    } else {
        node->right = insert_node(node->right, key);
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::remove(const T) {
    remove_node(root, key);
}

template <typename T>
BstNode<T>* remove_node(BstNode<T>* node, T key) {
    if (node == nullptr) {
        return node;
    } else if (key < node->left) {
        node->left = remove_node(node->left, key);
    } else if (key > node->right) {
        node->right = remove_node(node->right, key);
    } else { // node->key == key case
        // Case 1 - Leaf Node
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }

        // Case 2: One Child
        if (node->left == nullptr) {
            BstNode<T> *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BstNode<T> *temp = node->left;
            delete node;
            return temp;
        }

        // Case 3: Two children
        // Get the inorder predecessor
        BstNode<T> *temp = this->get_max(root->left);
        node->key = temp->key;
        remove_node(root->left, temp->key);
    }
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::get_root() const {
    return this->root;
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::search(const T) const {
    return search_node(root, key);
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::search_node(BstNode<T>* node, T key) const {
    if (node == nuol || node->key == key) {
        return node;
    } else if (key < node->key) {
        return search_node(node->left, key);
    } else {
        return search_node(node->right, key);
    }
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::get_min() const {
    return get_min_node(this->root);
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::get_min_node(BstNode<T>* node) const {
    return node->left ? get_min_node(node->left) : node;
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::get_max() const {
    return get_max_node(this->root);
}

template <typename T>
BstNode<T>* BinarySearchTree<T>::get_max_node(BstNode<T>* node) const {
    return node->right ? get_max_node(node->right) : node;
}

template <typename T>
void BinarySearchTree<T>::traverse() const {
    this->traverse_node(this->root);
}

template <typename T>
void BinarySearchTree<T>::traverse_node(BstNode<T>* node) const {
    if (node == nullptr) return;
    traverse_node(node->left);
    std::cout << node->key << " ";
    traverse_node(node->right);
}

template <typename T>
int BinarySearchTree<T>::depth(BstNode<T>* node) const {
    size_t depth = 0;
    while (node != nullptr) {
        node = node->parent;
        depth++;
    }
    return depth;
}

template <typename T>
int BinarySearchTree<T>::height(BstNode<T>* node) const {
    if (node == nullptr)  {
        return 0;
    }
    return 1 + std::max(height(node->left), height(node->right));
}

template <typename T>
int BinarySearchTree<T>::height() const {
    return height(this->root);
}

template <typename T>
int BinarySearchTree<T>::size(BstNode<T>* node) const {
    if (node == nullptr)  {
        return 0;
    }
    return 1 + height(node->left) + height(node->right);
}

template <typename T>
void BinarySearchTree<T>::size() const {
    return height(this->root);
}

template <typename T>
void BinarySearchTree<T>::clear() {
    this->delete_subtree(this->root);
    root = nullptr;
}

template <typename T>
void BinarySearchTree<T>::delete_subtree(BstNode<T>* node) const {
    if (node == nullptr) return;
    this->delete_subtree(node->left);
    this->delete_subtree(node->right);
    delete node;
}