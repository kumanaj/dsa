#pragma once
// ============================================================================
// 1. Two Sum                                                         [Easy]
// https://leetcode.com/problems/two-sum/
// Lists:   Blind 75, NeetCode 150
// Pattern: Arrays & Hashing
// ----------------------------------------------------------------------------
// Given an array of integers and a target, return the indices of the two
// numbers that add up to the target. Exactly one answer exists, and the same
// element can't be used twice. The indices can be returned in any order.
//
// Example 1: nums = [2,7,11,15], target = 9  ->  [0,1]
// Example 2: nums = [3,2,4],     target = 6  ->  [1,2]
//
// Constraints: 2 <= n <= 10^4; -10^9 <= nums[i], target <= 10^9;
//              exactly one valid answer.
// Follow-up:   can you do better than O(n^2) time?
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0001 {

class Solution {
public:
    // TODO: not implemented yet
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        throw std::logic_error("lc0001::twoSum not implemented");
    }
};

}  // namespace lc0001
