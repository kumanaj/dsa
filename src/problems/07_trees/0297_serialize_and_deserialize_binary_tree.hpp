#pragma once
// ============================================================================
// 297. Serialize and Deserialize Binary Tree                         [Hard]
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Lists:   Blind 75, NeetCode 150
// Pattern: Trees
// ----------------------------------------------------------------------------
// Design a way to turn a binary tree into a string (serialize) and to rebuild
// the same tree from that string (deserialize). Any format is fine, as long as
// deserialize(serialize(root)) gives back a tree with the same shape and values.
//
// Example 1: root = [1,2,3,null,null,4,5]  ->  serialize -> deserialize ->  [1,2,3,null,null,4,5]
// Example 2: root = []                     ->  serialize -> deserialize ->  []
//
// Constraints: 0 <= number of nodes <= 10^4; -1000 <= Node.val <= 1000.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/tree_node.hpp"
#include <stdexcept>
#include <string>

namespace lc0297 {

class Codec {
public:
    // TODO: not implemented yet
    std::string serialize(TreeNode* root) {
        throw std::logic_error("lc0297::Codec::serialize not implemented");
    }

    // TODO: not implemented yet
    TreeNode* deserialize(std::string data) {
        throw std::logic_error("lc0297::Codec::deserialize not implemented");
    }
};

}  // namespace lc0297
