#include <gtest/gtest.h>
#include <vector>
#include "problems/16_intervals/0253_meeting_rooms_ii.hpp"

using lc0253::Interval;

static int solve(std::vector<Interval> intervals) {
    return lc0253::Solution().minMeetingRooms(intervals);
}

TEST(MeetingRoomsIiTest, Example1) {
    EXPECT_EQ(solve({Interval(0, 40), Interval(5, 10), Interval(15, 20)}), 2);
}

TEST(MeetingRoomsIiTest, BackToBackReusesRoom) {
    EXPECT_EQ(solve({Interval(0, 8), Interval(8, 10)}), 1);
    EXPECT_EQ(solve({}), 0);
}

TEST(MeetingRoomsIiTest, AllOverlap) {
    EXPECT_EQ(solve({Interval(1, 5), Interval(2, 6), Interval(3, 7)}), 3);
}
