#pragma once
// ============================================================================
// 253. Meeting Rooms II                                            [Medium]
// https://leetcode.com/problems/meeting-rooms-ii/  (LeetCode Premium)
// Free version: https://neetcode.io/problems/meeting-schedule-ii
// Lists:   Blind 75, NeetCode 150
// Pattern: Intervals
// ----------------------------------------------------------------------------
// Given a list of meeting times, return the fewest meeting rooms needed to hold
// them all. A meeting that ends at the same time another starts, like (0,8) and
// (8,10), can reuse the same room.
//
// Example 1: intervals = [(0,40),(5,10),(15,20)]  ->  2
// Example 2: intervals = [(4,9)]                  ->  1
//
// Constraints: 0 <= intervals.length <= 500; 0 <= start < end <= 10^6.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0253 {

// NeetCode's interval type for this problem (LeetCode's Premium version uses std::vector<std::vector<int>>).
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    // TODO: not implemented yet
    int minMeetingRooms(std::vector<Interval>& intervals) {
        throw std::logic_error("lc0253::minMeetingRooms not implemented");
    }
};

}  // namespace lc0253
