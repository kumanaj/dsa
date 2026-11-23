#include <gtest/gtest.h>
#include <vector>
#include "problems/18_math_geometry/0054_spiral_matrix.hpp"

using Matrix = std::vector<std::vector<int>>;

static std::vector<int> solve(Matrix matrix) {
    return lc0054::Solution().spiralOrder(matrix);
}

TEST(SpiralMatrixTest, Square) {
    EXPECT_EQ(solve({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}), (std::vector<int>{1, 2, 3, 6, 9, 8, 7, 4, 5}));
}

TEST(SpiralMatrixTest, Wide) {
    EXPECT_EQ(solve({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}),
              (std::vector<int>{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}));
}

TEST(SpiralMatrixTest, SingleColumn) {
    EXPECT_EQ(solve({{1}, {2}, {3}}), (std::vector<int>{1, 2, 3}));   // catches visiting cells twice
}
