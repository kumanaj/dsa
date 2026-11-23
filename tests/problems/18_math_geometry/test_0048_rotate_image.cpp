#include <gtest/gtest.h>
#include <vector>
#include "problems/18_math_geometry/0048_rotate_image.hpp"

using Matrix = std::vector<std::vector<int>>;

static Matrix solve(Matrix matrix) {
    lc0048::Solution().rotate(matrix);
    return matrix;
}

TEST(RotateImageTest, ThreeByThree) {
    EXPECT_EQ(solve({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}), (Matrix{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}));
}

TEST(RotateImageTest, FourByFour) {
    Matrix matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Matrix expected = {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
    EXPECT_EQ(solve(matrix), expected);
}

TEST(RotateImageTest, OneByOne) {
    EXPECT_EQ(solve({{42}}), (Matrix{{42}}));
}
