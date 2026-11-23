#pragma once
// ============================================================================
// 207. Course Schedule                                             [Medium]
// https://leetcode.com/problems/course-schedule/
// Lists:   Blind 75, NeetCode 150
// Pattern: Graphs
// ----------------------------------------------------------------------------
// There are numCourses courses, numbered 0 to numCourses - 1.
// prerequisites[i] = [a, b] means course b must be taken before course a.
// Return true if it's possible to finish every course.
//
// Example 1: numCourses = 2, prerequisites = [[1,0]]        ->  true
// Example 2: numCourses = 2, prerequisites = [[1,0],[0,1]]  ->  false   (each needs the other)
//
// Constraints: 1 <= numCourses <= 2000; 0 <= prerequisites.length <= 5000;
//              all pairs are unique.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0207 {

class Solution {
public:
    // TODO: not implemented yet
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        throw std::logic_error("lc0207::canFinish not implemented");
    }
};

}  // namespace lc0207
