#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "problems/11_graphs/0417_pacific_atlantic_water_flow.hpp"

using Matrix = std::vector<std::vector<int>>;

// Cells may come back in any order, so sort before comparing.
static Matrix solve(Matrix heights) {
    Matrix result = lc0417::Solution().pacificAtlantic(heights);
    std::sort(result.begin(), result.end());
    return result;
}

TEST(PacificAtlanticWaterFlowTest, Example1) {
    Matrix heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    Matrix expected = {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}};
    EXPECT_EQ(solve(heights), expected);
}

TEST(PacificAtlanticWaterFlowTest, SingleCell) {
    EXPECT_EQ(solve({{1}}), (Matrix{{0, 0}}));
}

TEST(PacificAtlanticWaterFlowTest, FlatGridFlowsEverywhere) {
    EXPECT_EQ(solve({{1, 1}, {1, 1}}), (Matrix{{0, 0}, {0, 1}, {1, 0}, {1, 1}}));
}
