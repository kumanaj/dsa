#include <gtest/gtest.h>
#include <vector>
#include "problems/16_intervals/0252_meeting_rooms.hpp"

using lc0252::Interval;

static bool solve(std::vector<Interval> intervals) {
    return lc0252::Solution().canAttendMeetings(intervals);
}

TEST(MeetingRoomsTest, Overlap) {
    EXPECT_FALSE(solve({Interval(0, 30), Interval(5, 10), Interval(15, 20)}));
}

TEST(MeetingRoomsTest, NoOverlap) {
    EXPECT_TRUE(solve({Interval(5, 8), Interval(9, 15)}));
    EXPECT_TRUE(solve({}));
}

TEST(MeetingRoomsTest, BackToBackAndUnsorted) {
    EXPECT_TRUE(solve({Interval(8, 10), Interval(0, 8)}));
}
