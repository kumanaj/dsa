#include <gtest/gtest.h>
#include <vector>
#include "problems/03_sliding_window/0121_best_time_to_buy_and_sell_stock.hpp"

static int solve(std::vector<int> prices) {
    return lc0121::Solution().maxProfit(prices);
}

TEST(BestTimeToBuyAndSellStockTest, Example1) {
    EXPECT_EQ(solve({7, 1, 5, 3, 6, 4}), 5);
}

TEST(BestTimeToBuyAndSellStockTest, Example2) {
    EXPECT_EQ(solve({7, 6, 4, 3, 1}), 0);
}

TEST(BestTimeToBuyAndSellStockTest, LowestPriceComesLast) {
    EXPECT_EQ(solve({2, 4, 1}), 2);   // can't sell before buying at 1
}
