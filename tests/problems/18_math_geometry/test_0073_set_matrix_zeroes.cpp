#include <gtest/gtest.h>
#include <vector>
#include "problems/18_math_geometry/0073_set_matrix_zeroes.hpp"

using Matrix = std::vector<std::vector<int>>;

static Matrix solve(Matrix matrix) {
    lc0073::Solution().setZeroes(matrix);
    return matrix;
}

TEST(SetMatrixZeroesTest, Example1) {
    EXPECT_EQ(solve({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}), (Matrix{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}));
}

TEST(SetMatrixZeroesTest, ZerosInFirstRow) {
    EXPECT_EQ(solve({{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}), (Matrix{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}}));
}

TEST(SetMatrixZeroesTest, ZerosInFirstColumnAndCorner) {
    Matrix matrix = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
    Matrix expected = {{0, 0, 3, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    EXPECT_EQ(solve(matrix), expected);
}
