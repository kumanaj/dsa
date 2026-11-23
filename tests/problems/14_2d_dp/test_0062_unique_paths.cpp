#include <gtest/gtest.h>
#include "problems/14_2d_dp/0062_unique_paths.hpp"

TEST(UniquePathsTest, Examples) {
    EXPECT_EQ(lc0062::Solution().uniquePaths(3, 7), 28);
    EXPECT_EQ(lc0062::Solution().uniquePaths(3, 2), 3);
}

TEST(UniquePathsTest, SingleRowOrColumn) {
    EXPECT_EQ(lc0062::Solution().uniquePaths(1, 1), 1);
    EXPECT_EQ(lc0062::Solution().uniquePaths(1, 5), 1);
}

TEST(UniquePathsTest, LargeGrid) {
    EXPECT_EQ(lc0062::Solution().uniquePaths(23, 12), 193536720);   // plain recursion is far too slow here
}
