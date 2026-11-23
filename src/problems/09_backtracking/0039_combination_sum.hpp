#pragma once
// ============================================================================
// 39. Combination Sum                                              [Medium]
// https://leetcode.com/problems/combination-sum/
// Lists:   Blind 75, NeetCode 150
// Pattern: Backtracking
// ----------------------------------------------------------------------------
// Given an array of distinct integers and a target, return every unique
// combination of them that adds up to target. Each number may be used any
// number of times. Two combinations are the same if they use each number the
// same number of times. Return them in any order.
//
// Example 1: candidates = [2,3,6,7], target = 7  ->  [[2,2,3],[7]]
// Example 2: candidates = [2,3,5],   target = 8  ->  [[2,2,2,2],[2,3,3],[3,5]]
// Example 3: candidates = [2],       target = 1  ->  []
//
// Constraints: 1 <= candidates.length <= 30; 2 <= candidates[i] <= 40, all distinct;
//              1 <= target <= 40.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0039 {

class Solution {
public:
    // TODO: not implemented yet
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        throw std::logic_error("lc0039::combinationSum not implemented");
    }
};

}  // namespace lc0039
