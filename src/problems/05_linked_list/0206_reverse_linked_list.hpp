#pragma once
// ============================================================================
// 206. Reverse Linked List                                           [Easy]
// https://leetcode.com/problems/reverse-linked-list/
// Lists:   Blind 75, NeetCode 150
// Pattern: Linked List
// ----------------------------------------------------------------------------
// Given the head of a singly linked list, reverse it and return the new head.
//
// Example 1: head = [1,2,3,4,5]  ->  [5,4,3,2,1]
// Example 2: head = [1,2]        ->  [2,1]
// Example 3: head = []           ->  []
//
// Constraints: 0 <= number of nodes <= 5000; -5000 <= Node.val <= 5000.
// Follow-up:   solve it both iteratively and recursively.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/list_node.hpp"
#include <stdexcept>

namespace lc0206 {

class Solution {
public:
    // TODO: not implemented yet
    ListNode* reverseList(ListNode* head) {
        throw std::logic_error("lc0206::reverseList not implemented");
    }
};

}  // namespace lc0206
