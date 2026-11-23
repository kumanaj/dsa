#pragma once
// ============================================================================
// 55. Jump Game                                                    [Medium]
// https://leetcode.com/problems/jump-game/
// Lists:   Blind 75, NeetCode 150
// Pattern: Greedy
// ----------------------------------------------------------------------------
// You start at index 0 of an array, where nums[i] is the furthest you can jump
// forward from index i. Return true if you can reach the last index.
//
// Example 1: nums = [2,3,1,1,4]  ->  true    (0 -> 1 -> 4)
// Example 2: nums = [3,2,1,0,4]  ->  false   (every path gets stuck at index 3)
//
// Constraints: 1 <= n <= 10^4; 0 <= nums[i] <= 10^5.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0055 {

class Solution {
public:
    // TODO: not implemented yet
    bool canJump(std::vector<int>& nums) {
        throw std::logic_error("lc0055::canJump not implemented");
    }
};

}  // namespace lc0055
