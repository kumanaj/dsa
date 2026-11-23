#pragma once
// ============================================================================
// 19. Remove Nth Node From End of List                             [Medium]
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Lists:   Blind 75, NeetCode 150
// Pattern: Linked List
// ----------------------------------------------------------------------------
// Given the head of a linked list, remove the n-th node counting from the end
// (n = 1 is the last node) and return the head of the resulting list.
//
// Example 1: head = [1,2,3,4,5], n = 2  ->  [1,2,3,5]
// Example 2: head = [1],         n = 1  ->  []
// Example 3: head = [1,2],       n = 1  ->  [1]
//
// Constraints: 1 <= number of nodes <= 30; 0 <= Node.val <= 100; 1 <= n <= number of nodes.
// Follow-up:   do it in one pass.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/list_node.hpp"
#include <stdexcept>

namespace lc0019 {

class Solution {
public:
    // TODO: not implemented yet
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        throw std::logic_error("lc0019::removeNthFromEnd not implemented");
    }
};

}  // namespace lc0019
