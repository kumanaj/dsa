#pragma once
// ============================================================================
// 102. Binary Tree Level Order Traversal                           [Medium]
// https://leetcode.com/problems/binary-tree-level-order-traversal/
// Lists:   Blind 75, NeetCode 150
// Pattern: Trees
// ----------------------------------------------------------------------------
// Given the root of a binary tree, return its values level by level: one list
// per level, top to bottom, each list left to right.
//
// Example 1: root = [3,9,20,null,null,15,7]  ->  [[3],[9,20],[15,7]]
// Example 2: root = [1]                      ->  [[1]]
// Example 3: root = []                       ->  []
//
// Constraints: 0 <= number of nodes <= 2000; -1000 <= Node.val <= 1000.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/tree_node.hpp"
#include <stdexcept>
#include <vector>

namespace lc0102 {

class Solution {
public:
    // TODO: not implemented yet
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        throw std::logic_error("lc0102::levelOrder not implemented");
    }
};

}  // namespace lc0102
