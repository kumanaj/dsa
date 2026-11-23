#pragma once
// ============================================================================
// 15. 3Sum                                                         [Medium]
// https://leetcode.com/problems/3sum/
// Lists:   Blind 75, NeetCode 150
// Pattern: Two Pointers
// ----------------------------------------------------------------------------
// Given an integer array, return every unique triplet [a, b, c] of values at
// three different indices with a + b + c == 0. The result must not contain the
// same triplet twice. Triplets and their order can be returned in any order.
//
// Example 1: nums = [-1,0,1,2,-1,-4]  ->  [[-1,-1,2],[-1,0,1]]
// Example 2: nums = [0,1,1]           ->  []
// Example 3: nums = [0,0,0]           ->  [[0,0,0]]
//
// Constraints: 3 <= n <= 3000; -10^5 <= nums[i] <= 10^5.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0015 {

class Solution {
public:
    // TODO: not implemented yet
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        throw std::logic_error("lc0015::threeSum not implemented");
    }
};

}  // namespace lc0015
