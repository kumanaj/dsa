#include <gtest/gtest.h>
#include <vector>
#include "problems/15_greedy/0055_jump_game.hpp"

static bool solve(std::vector<int> nums) {
    return lc0055::Solution().canJump(nums);
}

TEST(JumpGameTest, Example1) {
    EXPECT_TRUE(solve({2, 3, 1, 1, 4}));
}

TEST(JumpGameTest, StuckOnZero) {
    EXPECT_FALSE(solve({3, 2, 1, 0, 4}));
}

TEST(JumpGameTest, AlreadyAtTheEnd) {
    EXPECT_TRUE(solve({0}));
}
