#pragma once
// ============================================================================
// 11. Container With Most Water                                    [Medium]
// https://leetcode.com/problems/container-with-most-water/
// Lists:   Blind 75, NeetCode 150
// Pattern: Two Pointers
// ----------------------------------------------------------------------------
// height[i] is the height of a vertical line at x = i. Pick two lines; together
// with the x-axis they form a container holding min(height) * distance water.
// Return the most water any pair of lines can hold.
//
// Example 1: height = [1,8,6,2,5,4,8,3,7]  ->  49   (lines at 1 and 8: min(8,7) * 7)
// Example 2: height = [1,1]                ->  1
//
// Constraints: 2 <= n <= 10^5; 0 <= height[i] <= 10^4.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0011 {

class Solution {
public:
    // TODO: not implemented yet
    int maxArea(std::vector<int>& height) {
        throw std::logic_error("lc0011::maxArea not implemented");
    }
};

}  // namespace lc0011
