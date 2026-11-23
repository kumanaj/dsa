#include <gtest/gtest.h>
#include <vector>
#include "problems/05_linked_list/0021_merge_two_sorted_lists.hpp"

static std::vector<int> solve(const std::vector<int>& a, const std::vector<int>& b) {
    ListNode* head = lc0021::Solution().mergeTwoLists(build_list(a), build_list(b));
    std::vector<int> result = to_vector(head);
    free_list(head);
    return result;
}

TEST(MergeTwoSortedListsTest, Example1) {
    EXPECT_EQ(solve({1, 2, 4}, {1, 3, 4}), (std::vector<int>{1, 1, 2, 3, 4, 4}));
}

TEST(MergeTwoSortedListsTest, EmptyLists) {
    EXPECT_EQ(solve({}, {}), std::vector<int>{});
    EXPECT_EQ(solve({}, {0}), std::vector<int>{0});
}

TEST(MergeTwoSortedListsTest, OneListRunsOutFirst) {
    EXPECT_EQ(solve({5}, {1, 2, 3}), (std::vector<int>{1, 2, 3, 5}));
}
