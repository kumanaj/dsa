#pragma once
// ============================================================================
// 322. Coin Change                                                 [Medium]
// https://leetcode.com/problems/coin-change/
// Lists:   Blind 75, NeetCode 150
// Pattern: 1-D Dynamic Programming
// ----------------------------------------------------------------------------
// Given coin denominations and an amount, return the fewest coins that add up
// to the amount, using any coin as many times as you like. Return -1 if the
// amount can't be made.
//
// Example 1: coins = [1,2,5], amount = 11  ->  3    (5 + 5 + 1)
// Example 2: coins = [2],     amount = 3   ->  -1
// Example 3: coins = [1],     amount = 0   ->  0
//
// Constraints: 1 <= coins.length <= 12; 1 <= coins[i] <= 2^31 - 1; 0 <= amount <= 10^4.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0322 {

class Solution {
public:
    // TODO: not implemented yet
    int coinChange(std::vector<int>& coins, int amount) {
        throw std::logic_error("lc0322::coinChange not implemented");
    }
};

}  // namespace lc0322
