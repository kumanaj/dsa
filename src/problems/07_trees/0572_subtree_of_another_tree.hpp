#pragma once
// ============================================================================
// 572. Subtree of Another Tree                                       [Easy]
// https://leetcode.com/problems/subtree-of-another-tree/
// Lists:   Blind 75, NeetCode 150
// Pattern: Trees
// ----------------------------------------------------------------------------
// Given the roots of two binary trees, root and subRoot, return true if some
// node of root has a subtree identical to subRoot: same shape and values, all
// the way down to the leaves. A tree counts as a subtree of itself.
//
// Example 1: root = [3,4,5,1,2],                         subRoot = [4,1,2]  ->  true
// Example 2: root = [3,4,5,1,2,null,null,null,null,0],   subRoot = [4,1,2]  ->  false
//
// Constraints: 1 <= nodes in root <= 2000; 1 <= nodes in subRoot <= 1000;
//              -10^4 <= Node.val <= 10^4.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/tree_node.hpp"
#include <stdexcept>

namespace lc0572 {

class Solution {
public:
    // TODO: not implemented yet
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        throw std::logic_error("lc0572::isSubtree not implemented");
    }
};

}  // namespace lc0572
