#pragma once
// ============================================================================
// 121. Best Time to Buy and Sell Stock                               [Easy]
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Lists:   Blind 75, NeetCode 150
// Pattern: Sliding Window
// ----------------------------------------------------------------------------
// prices[i] is a stock's price on day i. Buy on one day and sell on a later
// day. Return the largest profit you can make, or 0 if no trade makes money.
//
// Example 1: prices = [7,1,5,3,6,4]  ->  5   (buy at 1, sell at 6)
// Example 2: prices = [7,6,4,3,1]    ->  0   (prices only fall)
//
// Constraints: 1 <= n <= 10^5; 0 <= prices[i] <= 10^4.
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>
#include <vector>

namespace lc0121 {

class Solution {
public:
    // TODO: not implemented yet
    int maxProfit(std::vector<int>& prices) {
        throw std::logic_error("lc0121::maxProfit not implemented");
    }
};

}  // namespace lc0121
