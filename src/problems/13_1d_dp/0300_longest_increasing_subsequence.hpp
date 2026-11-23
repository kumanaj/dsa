#pragma once
// ============================================================================
// 300. Longest Increasing Subsequence                              [Medium]
// https://leetcode.com/problems/longest-increasing-subsequence/
// Lists:   Blind 75, NeetCode 150
// Pattern: 1-D Dynamic Programming
// ----------------------------------------------------------------------------
// Given an integer array, return the length of its longest strictly increasing
// subsequence (elements in order, not necessarily next to each other).
//
// Example 1: nums = [10,9,2,5,3,7,101,18]  ->  4   ([2,3,7,101])
// Example 2: nums = [0,1,0,3,2,3]          ->  4
// Example 3: nums = [7,7,7,7,7,7,7]        ->  1
//
// Constraints: 1 <= n <= 2500; -10^4 <= nums[i] <= 10^4.
// Follow-up:   O(n log n) time.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0300 {

class Solution {
public:
    // TODO: not implemented yet
    int lengthOfLIS(std::vector<int>& nums) {
        throw std::logic_error("lc0300::lengthOfLIS not implemented");
    }
};

}  // namespace lc0300
