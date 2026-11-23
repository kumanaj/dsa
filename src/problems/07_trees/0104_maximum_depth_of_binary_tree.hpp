#pragma once
// ============================================================================
// 104. Maximum Depth of Binary Tree                                  [Easy]
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Lists:   Blind 75, NeetCode 150
// Pattern: Trees
// ----------------------------------------------------------------------------
// Given the root of a binary tree, return its maximum depth: the number of
// nodes on the longest path from the root down to a leaf.
//
// Example 1: root = [3,9,20,null,null,15,7]  ->  3
// Example 2: root = [1,null,2]               ->  2
//
// Constraints: 0 <= number of nodes <= 10^4; -100 <= Node.val <= 100.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/tree_node.hpp"
#include <stdexcept>

namespace lc0104 {

class Solution {
public:
    // TODO: not implemented yet
    int maxDepth(TreeNode* root) {
        throw std::logic_error("lc0104::maxDepth not implemented");
    }
};

}  // namespace lc0104
