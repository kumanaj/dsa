#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "problems/02_two_pointers/0015_three_sum.hpp"

using Triplets = std::vector<std::vector<int>>;

// Triplets and their values may come back in any order, so sort both before comparing.
static Triplets solve(std::vector<int> nums) {
    Triplets result = lc0015::Solution().threeSum(nums);
    for (auto& t : result) {
        std::sort(t.begin(), t.end());
    }
    std::sort(result.begin(), result.end());
    return result;
}

TEST(ThreeSumTest, Example1) {
    EXPECT_EQ(solve({-1, 0, 1, 2, -1, -4}), (Triplets{{-1, -1, 2}, {-1, 0, 1}}));
}

TEST(ThreeSumTest, NoTriplet) {
    EXPECT_EQ(solve({0, 1, 1}), Triplets{});
}

TEST(ThreeSumTest, NoDuplicateTriplets) {
    EXPECT_EQ(solve({0, 0, 0, 0}), (Triplets{{0, 0, 0}}));
}
