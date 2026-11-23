#pragma once
// ============================================================================
// 56. Merge Intervals                                              [Medium]
// https://leetcode.com/problems/merge-intervals/
// Lists:   Blind 75, NeetCode 150
// Pattern: Intervals
// ----------------------------------------------------------------------------
// Given a list of [start, end] intervals in any order, merge every group of
// overlapping intervals (touching ones like [1,4] and [4,5] count) and return
// the non-overlapping result.
//
// Example 1: intervals = [[1,3],[2,6],[8,10],[15,18]]  ->  [[1,6],[8,10],[15,18]]
// Example 2: intervals = [[1,4],[4,5]]                 ->  [[1,5]]
// Example 3: intervals = [[4,7],[1,4]]                 ->  [[1,7]]
//
// Constraints: 1 <= intervals.length <= 10^4; 0 <= start <= end <= 10^4.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0056 {

class Solution {
public:
    // TODO: not implemented yet
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        throw std::logic_error("lc0056::merge not implemented");
    }
};

}  // namespace lc0056
