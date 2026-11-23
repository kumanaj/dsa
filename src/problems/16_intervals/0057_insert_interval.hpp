#pragma once
// ============================================================================
// 57. Insert Interval                                              [Medium]
// https://leetcode.com/problems/insert-interval/
// Lists:   Blind 75, NeetCode 150
// Pattern: Intervals
// ----------------------------------------------------------------------------
// intervals is a list of non-overlapping [start, end] intervals, sorted by
// start. Insert newInterval so the list stays sorted and non-overlapping,
// merging any intervals it overlaps (intervals that touch, like [1,5] and
// [5,7], count as overlapping). Return the resulting list.
//
// Example 1: intervals = [[1,3],[6,9]],                    newInterval = [2,5]  ->  [[1,5],[6,9]]
// Example 2: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]  ->  [[1,2],[3,10],[12,16]]
//
// Constraints: 0 <= intervals.length <= 10^4; intervals are sorted by start and don't
//              overlap; 0 <= start <= end <= 10^5.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0057 {

class Solution {
public:
    // TODO: not implemented yet
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        throw std::logic_error("lc0057::insert not implemented");
    }
};

}  // namespace lc0057
