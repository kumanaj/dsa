#pragma once
// ============================================================================
// 23. Merge k Sorted Lists                                           [Hard]
// https://leetcode.com/problems/merge-k-sorted-lists/
// Lists:   Blind 75, NeetCode 150
// Pattern: Linked List
// ----------------------------------------------------------------------------
// Given an array of k linked lists, each sorted ascending, merge them all into
// one sorted linked list and return its head.
//
// Example 1: lists = [[1,4,5],[1,3,4],[2,6]]  ->  [1,1,2,3,4,4,5,6]
// Example 2: lists = []                       ->  []
// Example 3: lists = [[]]                     ->  []
//
// Constraints: 0 <= k <= 10^4; 0 <= total nodes <= 10^4; -10^4 <= Node.val <= 10^4.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/list_node.hpp"
#include <stdexcept>
#include <vector>

namespace lc0023 {

class Solution {
public:
    // TODO: not implemented yet
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        throw std::logic_error("lc0023::mergeKLists not implemented");
    }
};

}  // namespace lc0023
