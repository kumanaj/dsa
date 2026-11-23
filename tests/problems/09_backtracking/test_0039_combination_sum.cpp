#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "problems/09_backtracking/0039_combination_sum.hpp"

using Combos = std::vector<std::vector<int>>;

// Combinations and their numbers may come back in any order, so sort both before comparing.
static Combos solve(std::vector<int> candidates, int target) {
    Combos result = lc0039::Solution().combinationSum(candidates, target);
    for (auto& c : result) {
        std::sort(c.begin(), c.end());
    }
    std::sort(result.begin(), result.end());
    return result;
}

TEST(CombinationSumTest, Example1) {
    EXPECT_EQ(solve({2, 3, 6, 7}, 7), (Combos{{2, 2, 3}, {7}}));
}

TEST(CombinationSumTest, Example2) {
    EXPECT_EQ(solve({2, 3, 5}, 8), (Combos{{2, 2, 2, 2}, {2, 3, 3}, {3, 5}}));
}

TEST(CombinationSumTest, NoCombination) {
    EXPECT_EQ(solve({2}, 1), Combos{});
}
