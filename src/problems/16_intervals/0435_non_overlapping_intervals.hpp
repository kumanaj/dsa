#pragma once
// ============================================================================
// 435. Non-overlapping Intervals                                   [Medium]
// https://leetcode.com/problems/non-overlapping-intervals/
// Lists:   Blind 75, NeetCode 150
// Pattern: Intervals
// ----------------------------------------------------------------------------
// Given a list of [start, end] intervals, return the fewest intervals you must
// remove so that the rest don't overlap. Intervals that only touch at a point,
// like [1,2] and [2,3], do not overlap.
//
// Example 1: intervals = [[1,2],[2,3],[3,4],[1,3]]  ->  1   (remove [1,3])
// Example 2: intervals = [[1,2],[1,2],[1,2]]        ->  2
// Example 3: intervals = [[1,2],[2,3]]              ->  0
//
// Constraints: 1 <= intervals.length <= 10^5; -5 * 10^4 <= start < end <= 5 * 10^4.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0435 {

class Solution {
public:
    // TODO: not implemented yet
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        throw std::logic_error("lc0435::eraseOverlapIntervals not implemented");
    }
};

}  // namespace lc0435
