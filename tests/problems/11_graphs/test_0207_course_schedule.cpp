#include <gtest/gtest.h>
#include <vector>
#include "problems/11_graphs/0207_course_schedule.hpp"

static bool solve(int n, std::vector<std::vector<int>> prerequisites) {
    return lc0207::Solution().canFinish(n, prerequisites);
}

TEST(CourseScheduleTest, NoCycle) {
    EXPECT_TRUE(solve(2, {{1, 0}}));
    // Diamond: 0 -> 1 -> 3 and 0 -> 2 -> 3. Reaching 3 twice is not a cycle.
    EXPECT_TRUE(solve(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}));
}

TEST(CourseScheduleTest, TwoCourseCycle) {
    EXPECT_FALSE(solve(2, {{1, 0}, {0, 1}}));
}

TEST(CourseScheduleTest, LongerCycle) {
    EXPECT_FALSE(solve(4, {{0, 1}, {1, 2}, {2, 0}, {3, 0}}));
}
