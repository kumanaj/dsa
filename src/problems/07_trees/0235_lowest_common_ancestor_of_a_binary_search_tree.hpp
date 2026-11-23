#pragma once
// ============================================================================
// 235. Lowest Common Ancestor of a Binary Search Tree              [Medium]
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Lists:   Blind 75, NeetCode 150
// Pattern: Trees
// ----------------------------------------------------------------------------
// Given a binary search tree and two of its nodes p and q, return their lowest
// common ancestor: the deepest node that has both p and q as descendants. A
// node counts as a descendant of itself.
//
// root = [6,2,8,0,4,7,9,null,null,3,5]
// Example 1: p = 2, q = 8  ->  6
// Example 2: p = 2, q = 4  ->  2   (2 is an ancestor of 4)
// Example 3: root = [2,1], p = 2, q = 1  ->  2
//
// Constraints: 2 <= number of nodes <= 10^5; values are unique; p != q;
//              p and q are both in the tree.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/tree_node.hpp"
#include <stdexcept>

namespace lc0235 {

class Solution {
public:
    // TODO: not implemented yet
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        throw std::logic_error("lc0235::lowestCommonAncestor not implemented");
    }
};

}  // namespace lc0235
