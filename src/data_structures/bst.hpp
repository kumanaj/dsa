#pragma once

#include <algorithm>
#include <cstddef>
#include <vector>

template <typename T>
struct BstNode {
    T key;
    BstNode *left, *right, *parent;
    BstNode(const T& data) : key(data), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <typename T>
class BinarySearchTree {

public:
    BinarySearchTree() : root(nullptr), count(0) {}
    ~BinarySearchTree() { clear(); }

    // Disable copying (the default copy would share nodes and double-free them)
    BinarySearchTree(const BinarySearchTree<T>& other) = delete;
    BinarySearchTree& operator=(const BinarySearchTree<T>& other) = delete;

    size_t size() const { return count; }
    bool empty() const { return count == 0; }

    void insert(const T& key) {
        root = insert_node(root, key);
        root->parent = nullptr;
        count++;   // duplicates are inserted too (they go right)
    }

    void remove(const T& key) {
        if (search_node(root, key) == nullptr) return;   // missing key: nothing to remove or count
        root = remove_node(root, key);
        if (root) root->parent = nullptr;
        count--;
    }

    BstNode<T>* search(const T& key) const {
        return search_node(root, key);
    }

    BstNode<T>* get_root() const {
        return this->root;
    }

    BstNode<T>* get_min() const {
        return get_min_node(this->root);
    }

    BstNode<T>* get_max() const {
        return get_max_node(this->root);
    }

    // Keys in sorted order.
    std::vector<T> in_order() const {
        std::vector<T> keys;
        in_order_node(root, keys);
        return keys;
    }

    int depth(BstNode<T>* node) const {
        int depth = 0;
        while (node != nullptr) {
            node = node->parent;
            depth++;
        }
        return depth;
    }

    int height(BstNode<T>* node) const {
        if (node == nullptr)  {
            return 0;
        }
        return 1 + std::max(height(node->left), height(node->right));
    }

    int height() const {
        return height(this->root);
    }

    void clear() {
        this->delete_subtree(this->root);
        root = nullptr;
        count = 0;
    }

private:
    BstNode<T> *root;
    size_t count;

    BstNode<T>* insert_node(BstNode<T>* node, T key) {
        if (node == nullptr) {
            return new BstNode<T>(key);
        } else if (key < node->key) {
            node->left = insert_node(node->left, key);
            node->left->parent = node;
        } else {
            node->right = insert_node(node->right, key);
            node->right->parent = node;
        }
        return node;
    }

    BstNode<T>* remove_node(BstNode<T>* node, T key) {
        if (node == nullptr) {
            return node;
        } else if (key < node->key) {
            node->left = remove_node(node->left, key);
            if (node->left) node->left->parent = node;
        } else if (key > node->key) {
            node->right = remove_node(node->right, key);
            if (node->right) node->right->parent = node;
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
            BstNode<T> *temp = get_max_node(node->left);
            node->key = temp->key;
            node->left = remove_node(node->left, temp->key);
            if (node->left) node->left->parent = node;
        }
        return node;
    }

    BstNode<T>* search_node(BstNode<T>* node, T key) const {
        if (node == nullptr || node->key == key) {
            return node;
        } else if (key < node->key) {
            return search_node(node->left, key);
        } else {
            return search_node(node->right, key);
        }
    }

    BstNode<T>* get_min_node(BstNode<T>* node) const {
        if (node == nullptr) return nullptr;
        return node->left ? get_min_node(node->left) : node;
    }

    BstNode<T>* get_max_node(BstNode<T>* node) const {
        if (node == nullptr) return nullptr;
        return node->right ? get_max_node(node->right) : node;
    }

    void in_order_node(BstNode<T>* node, std::vector<T>& keys) const {
        if (node == nullptr) return;
        in_order_node(node->left, keys);
        keys.push_back(node->key);
        in_order_node(node->right, keys);
    }

    void delete_subtree(BstNode<T>* node) {
        if (node == nullptr) return;
        this->delete_subtree(node->left);
        this->delete_subtree(node->right);
        delete node;
    }
};
