#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "problems/01_arrays_hashing/0347_top_k_frequent_elements.hpp"

// The answer may come back in any order, so sort before comparing.
static std::vector<int> solve(std::vector<int> nums, int k) {
    std::vector<int> result = lc0347::Solution().topKFrequent(nums, k);
    std::sort(result.begin(), result.end());
    return result;
}

TEST(TopKFrequentElementsTest, Example1) {
    EXPECT_EQ(solve({1, 1, 1, 2, 2, 3}, 2), (std::vector<int>{1, 2}));
}

TEST(TopKFrequentElementsTest, Example2) {
    EXPECT_EQ(solve({1}, 1), (std::vector<int>{1}));
}

TEST(TopKFrequentElementsTest, NegativeValues) {
    EXPECT_EQ(solve({4, 1, -1, 2, -1, 2, 3}, 2), (std::vector<int>{-1, 2}));
}
