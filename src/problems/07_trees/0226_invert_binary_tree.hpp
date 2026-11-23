#pragma once
// ============================================================================
// 226. Invert Binary Tree                                            [Easy]
// https://leetcode.com/problems/invert-binary-tree/
// Lists:   Blind 75, NeetCode 150
// Pattern: Trees
// ----------------------------------------------------------------------------
// Given the root of a binary tree, mirror it (swap every node's left and right children) and return the root.
//
// Example 1: root = [4,2,7,1,3,6,9]  ->  [4,7,2,9,6,3,1]
// Example 2: root = [2,1,3]          ->  [2,3,1]
// Example 3: root = []               ->  []
//
// Constraints: 0 <= number of nodes <= 100; -100 <= Node.val <= 100.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/tree_node.hpp"
#include <stdexcept>

namespace lc0226 {

class Solution {
public:
    // TODO: not implemented yet
    TreeNode* invertTree(TreeNode* root) {
        throw std::logic_error("lc0226::invertTree not implemented");
    }
};

}  // namespace lc0226
