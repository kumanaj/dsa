#pragma once
// ============================================================================
// 141. Linked List Cycle                                             [Easy]
// https://leetcode.com/problems/linked-list-cycle/
// Lists:   Blind 75, NeetCode 150
// Pattern: Linked List
// ----------------------------------------------------------------------------
// Given the head of a linked list, return true if following next pointers ever
// reaches a node a second time (the list has a cycle), and false if it ends.
// In the examples, pos is the index the tail links back to (-1 means no cycle);
// it isn't passed to your function.
//
// Example 1: head = [3,2,0,-4], pos = 1   ->  true
// Example 2: head = [1,2],      pos = 0   ->  true
// Example 3: head = [1],        pos = -1  ->  false
//
// Constraints: 0 <= number of nodes <= 10^4; -10^5 <= Node.val <= 10^5.
// Follow-up:   O(1) extra memory.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include "problems/common/list_node.hpp"
#include <stdexcept>

namespace lc0141 {

class Solution {
public:
    // TODO: not implemented yet
    bool hasCycle(ListNode* head) {
        throw std::logic_error("lc0141::hasCycle not implemented");
    }
};

}  // namespace lc0141
