#pragma once
// ============================================================================
// 98. Validate Binary Search Tree                                  [Medium]
// https://leetcode.com/problems/validate-binary-search-tree/
// Lists:   Blind 75, NeetCode 150
// Pattern: Trees
// ----------------------------------------------------------------------------
// Given the root of a binary tree, return true if it is a valid binary search
// tree: for every node, all keys in its left subtree are strictly smaller and
// all keys in its right subtree are strictly larger, and both subtrees are
// valid BSTs too.
//
// Example 1: root = [2,1,3]                    ->  true
// Example 2: root = [5,1,4,null,null,3,6]      ->  false   (4 is in 5's right subtree)
//
// Constraints: 1 <= number of nodes <= 10^4; -2^31 <= Node.val <= 2^31 - 1.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/tree_node.hpp"
#include <stdexcept>

namespace lc0098 {

class Solution {
public:
    // TODO: not implemented yet
    bool isValidBST(TreeNode* root) {
        throw std::logic_error("lc0098::isValidBST not implemented");
    }
};

}  // namespace lc0098
