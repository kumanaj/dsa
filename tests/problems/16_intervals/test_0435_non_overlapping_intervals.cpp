#include <gtest/gtest.h>
#include <vector>
#include "problems/16_intervals/0435_non_overlapping_intervals.hpp"

static int solve(std::vector<std::vector<int>> intervals) {
    return lc0435::Solution().eraseOverlapIntervals(intervals);
}

TEST(NonOverlappingIntervalsTest, Example1) {
    EXPECT_EQ(solve({{1, 2}, {2, 3}, {3, 4}, {1, 3}}), 1);
}

TEST(NonOverlappingIntervalsTest, Duplicates) {
    EXPECT_EQ(solve({{1, 2}, {1, 2}, {1, 2}}), 2);
}

TEST(NonOverlappingIntervalsTest, TouchingIsFine) {
    EXPECT_EQ(solve({{1, 2}, {2, 3}}), 0);
}
