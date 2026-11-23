#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "problems/16_intervals/0056_merge_intervals.hpp"

using Intervals = std::vector<std::vector<int>>;

// The merged intervals may come back in any order, so sort before comparing.
static Intervals solve(Intervals intervals) {
    Intervals result = lc0056::Solution().merge(intervals);
    std::sort(result.begin(), result.end());
    return result;
}

TEST(MergeIntervalsTest, Example1) {
    EXPECT_EQ(solve({{1, 3}, {2, 6}, {8, 10}, {15, 18}}), (Intervals{{1, 6}, {8, 10}, {15, 18}}));
}

TEST(MergeIntervalsTest, TouchingAndUnsorted) {
    EXPECT_EQ(solve({{1, 4}, {4, 5}}), (Intervals{{1, 5}}));
    EXPECT_EQ(solve({{4, 7}, {1, 4}}), (Intervals{{1, 7}}));
}

TEST(MergeIntervalsTest, OneInsideAnother) {
    EXPECT_EQ(solve({{1, 10}, {2, 3}, {4, 5}}), (Intervals{{1, 10}}));   // end is max(ends), not the last end
}
