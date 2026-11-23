#include <gtest/gtest.h>
#include <vector>
#include "problems/16_intervals/0057_insert_interval.hpp"

using Intervals = std::vector<std::vector<int>>;

static Intervals solve(Intervals intervals, std::vector<int> new_interval) {
    return lc0057::Solution().insert(intervals, new_interval);
}

TEST(InsertIntervalTest, Example1) {
    EXPECT_EQ(solve({{1, 3}, {6, 9}}, {2, 5}), (Intervals{{1, 5}, {6, 9}}));
}

TEST(InsertIntervalTest, MergesSeveral) {
    EXPECT_EQ(solve({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}),
              (Intervals{{1, 2}, {3, 10}, {12, 16}}));
}

TEST(InsertIntervalTest, EdgeCases) {
    EXPECT_EQ(solve({}, {5, 7}), (Intervals{{5, 7}}));                  // empty list
    EXPECT_EQ(solve({{1, 2}}, {3, 4}), (Intervals{{1, 2}, {3, 4}}));    // goes at the end
    EXPECT_EQ(solve({{1, 5}}, {5, 7}), (Intervals{{1, 7}}));            // touching intervals merge
}
