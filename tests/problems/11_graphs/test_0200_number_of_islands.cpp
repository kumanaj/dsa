#include <gtest/gtest.h>
#include <vector>
#include "problems/11_graphs/0200_number_of_islands.hpp"

using Grid = std::vector<std::vector<char>>;

static int solve(Grid grid) {
    return lc0200::Solution().numIslands(grid);
}

TEST(NumberOfIslandsTest, Example1) {
    Grid grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    EXPECT_EQ(solve(grid), 1);
}

TEST(NumberOfIslandsTest, Example2) {
    Grid grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    EXPECT_EQ(solve(grid), 3);
}

TEST(NumberOfIslandsTest, DiagonalIsNotConnected) {
    EXPECT_EQ(solve({{'1', '0'}, {'0', '1'}}), 2);
}
