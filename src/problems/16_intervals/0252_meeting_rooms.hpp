#pragma once
// ============================================================================
// 252. Meeting Rooms                                                 [Easy]
// https://leetcode.com/problems/meeting-rooms/  (LeetCode Premium)
// Free version: https://neetcode.io/problems/meeting-schedule
// Lists:   Blind 75, NeetCode 150
// Pattern: Intervals
// ----------------------------------------------------------------------------
// Given a list of meeting times, return true if one person could attend all of
// them (no two meetings overlap). A meeting that ends at the same time another
// starts, like (0,8) and (8,10), is not a conflict.
//
// Example 1: intervals = [(0,30),(5,10),(15,20)]  ->  false
// Example 2: intervals = [(5,8),(9,15)]           ->  true
//
// Constraints: 0 <= intervals.length <= 500; 0 <= start < end <= 10^6.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0252 {

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
    bool canAttendMeetings(std::vector<Interval>& intervals) {
        throw std::logic_error("lc0252::canAttendMeetings not implemented");
    }
};

}  // namespace lc0252
