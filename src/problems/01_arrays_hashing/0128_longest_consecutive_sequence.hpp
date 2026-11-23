#pragma once
// ============================================================================
// 128. Longest Consecutive Sequence                                [Medium]
// https://leetcode.com/problems/longest-consecutive-sequence/
// Lists:   Blind 75, NeetCode 150
// Pattern: Arrays & Hashing
// ----------------------------------------------------------------------------
// Given an unsorted integer array, return the length of the longest run of
// consecutive values (x, x+1, x+2, ...) that all appear in the array. The
// values don't need to be next to each other in the array. Solve it in O(n).
//
// Example 1: nums = [100,4,200,1,3,2]        ->  4   (1,2,3,4)
// Example 2: nums = [0,3,7,2,5,8,4,6,0,1]    ->  9   (0..8)
//
// Constraints: 0 <= n <= 10^5; -10^9 <= nums[i] <= 10^9.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0128 {

class Solution {
public:
    // TODO: not implemented yet
    int longestConsecutive(std::vector<int>& nums) {
        throw std::logic_error("lc0128::longestConsecutive not implemented");
    }
};

}  // namespace lc0128
