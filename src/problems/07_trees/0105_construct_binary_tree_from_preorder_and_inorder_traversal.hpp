#pragma once
// ============================================================================
// 105. Construct Binary Tree from Preorder and Inorder Traversal   [Medium]
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Lists:   Blind 75, NeetCode 150
// Pattern: Trees
// ----------------------------------------------------------------------------
// Given the preorder and inorder traversals of the same binary tree (all values
// distinct), rebuild the tree and return its root.
//
// Example 1: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]  ->  [3,9,20,null,null,15,7]
// Example 2: preorder = [-1],          inorder = [-1]           ->  [-1]
//
// Constraints: 1 <= n <= 3000; -3000 <= values <= 3000; values are unique;
//              both arrays describe the same tree.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/tree_node.hpp"
#include <stdexcept>
#include <vector>

namespace lc0105 {

class Solution {
public:
    // TODO: not implemented yet
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        throw std::logic_error("lc0105::buildTree not implemented");
    }
};

}  // namespace lc0105
