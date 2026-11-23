#pragma once
// ============================================================================
// 33. Search in Rotated Sorted Array                               [Medium]
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Lists:   Blind 75, NeetCode 150
// Pattern: Binary Search
// ----------------------------------------------------------------------------
// A sorted array of distinct integers has been rotated at an unknown pivot.
// Return the index of target in it, or -1 if it isn't there, in O(log n) time.
//
// Example 1: nums = [4,5,6,7,0,1,2], target = 0  ->  4
// Example 2: nums = [4,5,6,7,0,1,2], target = 3  ->  -1
// Example 3: nums = [1],             target = 0  ->  -1
//
// Constraints: 1 <= n <= 5000; values are distinct; -10^4 <= nums[i], target <= 10^4.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0033 {

class Solution {
public:
    // TODO: not implemented yet
    int search(std::vector<int>& nums, int target) {
        throw std::logic_error("lc0033::search not implemented");
    }
};

}  // namespace lc0033
