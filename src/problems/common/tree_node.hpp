#pragma once
// LeetCode's binary tree node, exactly as LeetCode defines it, so solutions paste unchanged.
// Shared by every tree problem, which is why it lives outside the per-problem namespaces.
// The helpers below are for tests only.

#include <cstddef>
#include <optional>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Lets tests write trees the way LeetCode prints them: build_tree({3, 9, 20, null, null, 15, 7}).
inline constexpr std::nullopt_t null = std::nullopt;

// Builds a tree from LeetCode's level-order format, where null marks a missing child.
inline TreeNode* build_tree(const std::vector<std::optional<int>>& level_order) {
    if (level_order.empty() || !level_order[0]) return nullptr;
    TreeNode* root = new TreeNode(*level_order[0]);
    std::queue<TreeNode*> parents;
    parents.push(root);
    size_t i = 1;
    while (!parents.empty() && i < level_order.size()) {
        TreeNode* parent = parents.front();
        parents.pop();
        if (i < level_order.size() && level_order[i]) {
            parent->left = new TreeNode(*level_order[i]);
            parents.push(parent->left);
        }
        i++;
        if (i < level_order.size() && level_order[i]) {
            parent->right = new TreeNode(*level_order[i]);
            parents.push(parent->right);
        }
        i++;
    }
    return root;
}

// The reverse of build_tree: LeetCode's level-order format, without trailing nulls.
inline std::vector<std::optional<int>> to_level_order(TreeNode* root) {
    std::vector<std::optional<int>> values;
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        TreeNode* node = nodes.front();
        nodes.pop();
        if (node == nullptr) {
            values.push_back(std::nullopt);
        } else {
            values.push_back(node->val);
            nodes.push(node->left);
            nodes.push(node->right);
        }
    }
    while (!values.empty() && !values.back()) {
        values.pop_back();
    }
    return values;
}

// First node with this value (pre-order), or nullptr. Used to get p and q for LCA-style problems.
inline TreeNode* find_node(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) return root;
    TreeNode* left = find_node(root->left, val);
    return left != nullptr ? left : find_node(root->right, val);
}

// Deletes every node.
inline void free_tree(TreeNode* root) {
    if (root == nullptr) return;
    free_tree(root->left);
    free_tree(root->right);
    delete root;
}
