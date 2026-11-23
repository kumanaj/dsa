#pragma once
// ============================================================================
// 143. Reorder List                                                [Medium]
// https://leetcode.com/problems/reorder-list/
// Lists:   Blind 75, NeetCode 150
// Pattern: Linked List
// ----------------------------------------------------------------------------
// Given a list L0 -> L1 -> ... -> Ln, reorder it in place to
// L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ... by relinking nodes, not by
// changing their values.
//
// Example 1: head = [1,2,3,4]    ->  [1,4,2,3]
// Example 2: head = [1,2,3,4,5]  ->  [1,5,2,4,3]
//
// Constraints: 1 <= number of nodes <= 5 * 10^4; 1 <= Node.val <= 1000.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/list_node.hpp"
#include <stdexcept>

namespace lc0143 {

class Solution {
public:
    // TODO: not implemented yet
    void reorderList(ListNode* head) {
        throw std::logic_error("lc0143::reorderList not implemented");
    }
};

}  // namespace lc0143
