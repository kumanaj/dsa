#pragma once

#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>

// Self-balancing BST: after every insert/remove, each node's children differ in height by at most 1.
// Like BinarySearchTree, height counts nodes (a leaf has height 1, an empty tree 0).
// No parent pointers. Duplicate keys are ignored.

template <typename T>
struct AvlNode {
    T key;
    AvlNode *left, *right;
    int height;

    AvlNode(T data) : key(data), left(nullptr), right(nullptr), height(1) {}
};

template <typename T>
class AvlTree {
public:
    AvlTree() : root(nullptr), count(0) {}

    ~AvlTree() {
        // TODO: free every node here (call clear() once it is implemented)
    }

    // Disable copying (the default copy would share nodes and double-free them)
    AvlTree(const AvlTree<T>& other) = delete;
    AvlTree& operator=(const AvlTree<T>& other) = delete;

    size_t size() const { return count; }
    bool empty() const { return count == 0; }
    AvlNode<T>* get_root() const { return root; }

    // TODO: not implemented yet
    void insert(const T key) {
        throw std::logic_error("AvlTree::insert not implemented");
    }

    // TODO: not implemented yet
    // Does nothing if the key isn't in the tree.
    void remove(const T key) {
        throw std::logic_error("AvlTree::remove not implemented");
    }

    // TODO: not implemented yet
    bool contains(const T key) const {
        throw std::logic_error("AvlTree::contains not implemented");
    }

    // TODO: not implemented yet
    int height() const {
        throw std::logic_error("AvlTree::height not implemented");
    }

    // TODO: not implemented yet
    // Keys in sorted order.
    std::vector<T> in_order() const {
        throw std::logic_error("AvlTree::in_order not implemented");
    }

    // TODO: not implemented yet
    void clear() {
        throw std::logic_error("AvlTree::clear not implemented");
    }

private:
    AvlNode<T>* root;
    size_t count;

    // TODO: not implemented yet
    // Height of a possibly-null node (0 for nullptr).
    int height(AvlNode<T>* node) const {
        throw std::logic_error("AvlTree::height(node) not implemented");
    }

    // TODO: not implemented yet
    // height(left) - height(right)
    int balance_factor(AvlNode<T>* node) const {
        throw std::logic_error("AvlTree::balance_factor not implemented");
    }

    // TODO: not implemented yet
    void update_height(AvlNode<T>* node) {
        throw std::logic_error("AvlTree::update_height not implemented");
    }

    // TODO: not implemented yet
    // Returns the new root of this subtree.
    AvlNode<T>* rotate_left(AvlNode<T>* node) {
        throw std::logic_error("AvlTree::rotate_left not implemented");
    }

    // TODO: not implemented yet
    // Returns the new root of this subtree.
    AvlNode<T>* rotate_right(AvlNode<T>* node) {
        throw std::logic_error("AvlTree::rotate_right not implemented");
    }

    // TODO: not implemented yet
    // Fix the LL, RR, LR and RL cases at this node. Returns the new root of this subtree.
    AvlNode<T>* rebalance(AvlNode<T>* node) {
        throw std::logic_error("AvlTree::rebalance not implemented");
    }

    // TODO: not implemented yet
    AvlNode<T>* insert_node(AvlNode<T>* node, T key) {
        throw std::logic_error("AvlTree::insert_node not implemented");
    }

    // TODO: not implemented yet
    AvlNode<T>* remove_node(AvlNode<T>* node, T key) {
        throw std::logic_error("AvlTree::remove_node not implemented");
    }

    // TODO: not implemented yet
    void in_order_node(AvlNode<T>* node, std::vector<T>& keys) const {
        throw std::logic_error("AvlTree::in_order_node not implemented");
    }

    // TODO: not implemented yet
    void delete_subtree(AvlNode<T>* node) {
        throw std::logic_error("AvlTree::delete_subtree not implemented");
    }
};
