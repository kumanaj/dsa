#pragma once
// ============================================================================
// 213. House Robber II                                             [Medium]
// https://leetcode.com/problems/house-robber-ii/
// Lists:   Blind 75, NeetCode 150
// Pattern: 1-D Dynamic Programming
// ----------------------------------------------------------------------------
// Same as House Robber, but the houses are in a circle, so the first and last
// houses are also adjacent. Return the most money you can rob without robbing
// two adjacent houses.
//
// Example 1: nums = [2,3,2]    ->  3   (can't take both 2s; they're adjacent)
// Example 2: nums = [1,2,3,1]  ->  4
// Example 3: nums = [1,2,3]    ->  3
//
// Constraints: 1 <= n <= 100; 0 <= nums[i] <= 1000.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0213 {

class Solution {
public:
    // TODO: not implemented yet
    int rob(std::vector<int>& nums) {
        throw std::logic_error("lc0213::rob not implemented");
    }
};

}  // namespace lc0213
