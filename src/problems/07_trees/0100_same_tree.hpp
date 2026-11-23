#pragma once
// ============================================================================
// 100. Same Tree                                                     [Easy]
// https://leetcode.com/problems/same-tree/
// Lists:   Blind 75, NeetCode 150
// Pattern: Trees
// ----------------------------------------------------------------------------
// Given the roots of two binary trees, return true if they have the same shape and the same values in every node.
//
// Example 1: p = [1,2,3], q = [1,2,3]       ->  true
// Example 2: p = [1,2],   q = [1,null,2]    ->  false
// Example 3: p = [1,2,1], q = [1,1,2]       ->  false
//
// Constraints: 0 <= number of nodes in each tree <= 100; -10^4 <= Node.val <= 10^4.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/tree_node.hpp"
#include <stdexcept>

namespace lc0100 {

class Solution {
public:
    // TODO: not implemented yet
    bool isSameTree(TreeNode* p, TreeNode* q) {
        throw std::logic_error("lc0100::isSameTree not implemented");
    }
};

}  // namespace lc0100
