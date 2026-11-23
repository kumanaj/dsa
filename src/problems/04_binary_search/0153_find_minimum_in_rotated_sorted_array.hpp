#pragma once
// ============================================================================
// 153. Find Minimum in Rotated Sorted Array                        [Medium]
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Lists:   Blind 75, NeetCode 150
// Pattern: Binary Search
// ----------------------------------------------------------------------------
// A sorted array of distinct integers has been rotated some number of times
// ([0,1,2,4,5,6,7] rotated 4 times is [4,5,6,7,0,1,2]). Return its smallest
// element in O(log n) time.
//
// Example 1: nums = [3,4,5,1,2]        ->  1
// Example 2: nums = [4,5,6,7,0,1,2]    ->  0
// Example 3: nums = [11,13,15,17]      ->  11   (rotated n times: back to sorted)
//
// Constraints: 1 <= n <= 5000; values are distinct; -5000 <= nums[i] <= 5000.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0153 {

class Solution {
public:
    // TODO: not implemented yet
    int findMin(std::vector<int>& nums) {
        throw std::logic_error("lc0153::findMin not implemented");
    }
};

}  // namespace lc0153
