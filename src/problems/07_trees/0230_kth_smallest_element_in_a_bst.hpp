#pragma once
// ============================================================================
// 230. Kth Smallest Element in a BST                               [Medium]
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Lists:   Blind 75, NeetCode 150
// Pattern: Trees
// ----------------------------------------------------------------------------
// Given the root of a binary search tree and an integer k, return the k-th smallest value in it (k is 1-indexed).
//
// Example 1: root = [3,1,4,null,2],           k = 1  ->  1
// Example 2: root = [5,3,6,2,4,null,null,1],  k = 3  ->  3
//
// Constraints: 1 <= k <= n <= 10^4; 0 <= Node.val <= 10^4.
// Follow-up:   if the BST is modified often (inserts and deletes) and you need the k-th
//              smallest frequently, how would you optimise it?
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/tree_node.hpp"
#include <stdexcept>

namespace lc0230 {

class Solution {
public:
    // TODO: not implemented yet
    int kthSmallest(TreeNode* root, int k) {
        throw std::logic_error("lc0230::kthSmallest not implemented");
    }
};

}  // namespace lc0230
