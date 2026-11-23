#pragma once

#include <algorithm>
#include <cstddef>
#include <iostream>

template <typename T>
struct BstNode {
    T key;
    BstNode *left, *right, *parent;
    BstNode(T data) : key(data), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <typename T>
class BinarySearchTree {

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() { clear(); }

    // Disable copying (the default copy would share nodes and double-free them)
    BinarySearchTree(const BinarySearchTree<T>& other) = delete;
    BinarySearchTree& operator=(const BinarySearchTree<T>& other) = delete;

    void insert(const T key) {
        root = insert_node(root, key);
        root->parent = nullptr;
    }

    void remove(const T key) {
        root = remove_node(root, key);
        if (root) root->parent = nullptr;
    }

    BstNode<T>* search(const T key) const {
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

    void traverse() const {
        this->traverse_node(this->root);
    }

    int depth(BstNode<T>* node) const {
        size_t depth = 0;
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

    int size(BstNode<T>* node) const {
        if (node == nullptr)  {
            return 0;
        }
        return 1 + size(node->left) + size(node->right);
    }

    int size() const {
        return size(this->root);
    }

    void clear() {
        this->delete_subtree(this->root);
        root = nullptr;
    }

private:
    BstNode<T> *root;

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

    void traverse_node(BstNode<T>* node) const {
        if (node == nullptr) return;
        traverse_node(node->left);
        std::cout << node->key << " ";
        traverse_node(node->right);
    }

    void delete_subtree(BstNode<T>* node) const {
        if (node == nullptr) return;
        this->delete_subtree(node->left);
        this->delete_subtree(node->right);
        delete node;
    }
};
