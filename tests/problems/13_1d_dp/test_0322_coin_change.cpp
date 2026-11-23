#include <gtest/gtest.h>
#include <vector>
#include "problems/13_1d_dp/0322_coin_change.hpp"

static int solve(std::vector<int> coins, int amount) {
    return lc0322::Solution().coinChange(coins, amount);
}

TEST(CoinChangeTest, Example1) {
    EXPECT_EQ(solve({1, 2, 5}, 11), 3);
}

TEST(CoinChangeTest, ImpossibleAndZero) {
    EXPECT_EQ(solve({2}, 3), -1);
    EXPECT_EQ(solve({1}, 0), 0);
}

TEST(CoinChangeTest, GreedyFails) {
    EXPECT_EQ(solve({1, 3, 4}, 6), 2);   // 3 + 3; taking the 4 first needs 3 coins
}
