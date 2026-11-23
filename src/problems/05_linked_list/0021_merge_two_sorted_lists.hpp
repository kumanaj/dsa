#pragma once
// ============================================================================
// 21. Merge Two Sorted Lists                                         [Easy]
// https://leetcode.com/problems/merge-two-sorted-lists/
// Lists:   Blind 75, NeetCode 150
// Pattern: Linked List
// ----------------------------------------------------------------------------
// Given the heads of two sorted linked lists, splice their nodes together into
// one sorted list and return its head.
//
// Example 1: list1 = [1,2,4], list2 = [1,3,4]  ->  [1,1,2,3,4,4]
// Example 2: list1 = [],      list2 = []       ->  []
// Example 3: list1 = [],      list2 = [0]      ->  [0]
//
// Constraints: 0 <= nodes in each list <= 50; -100 <= Node.val <= 100; both sorted ascending.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/list_node.hpp"
#include <stdexcept>

namespace lc0021 {

class Solution {
public:
    // TODO: not implemented yet
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        throw std::logic_error("lc0021::mergeTwoLists not implemented");
    }
};

}  // namespace lc0021
