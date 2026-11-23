#pragma once
// ============================================================================
// 124. Binary Tree Maximum Path Sum                                  [Hard]
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Lists:   Blind 75, NeetCode 150
// Pattern: Trees
// ----------------------------------------------------------------------------
// A path is a sequence of nodes where each adjacent pair is joined by an edge
// and no node appears twice. It doesn't have to pass through the root and has
// at least one node. Given the root of a binary tree, return the largest sum
// of node values over all paths.
//
// Example 1: root = [1,2,3]                    ->  6    (2 -> 1 -> 3)
// Example 2: root = [-10,9,20,null,null,15,7]  ->  42   (15 -> 20 -> 7)
//
// Constraints: 1 <= number of nodes <= 3 * 10^4; -1000 <= Node.val <= 1000.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/tree_node.hpp"
#include <stdexcept>

namespace lc0124 {

class Solution {
public:
    // TODO: not implemented yet
    int maxPathSum(TreeNode* root) {
        throw std::logic_error("lc0124::maxPathSum not implemented");
    }
};

}  // namespace lc0124
