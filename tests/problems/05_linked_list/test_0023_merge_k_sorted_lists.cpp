#include <gtest/gtest.h>
#include <vector>
#include "problems/05_linked_list/0023_merge_k_sorted_lists.hpp"

static std::vector<int> solve(const std::vector<std::vector<int>>& input) {
    std::vector<ListNode*> lists;
    for (const auto& values : input) {
        lists.push_back(build_list(values));
    }
    ListNode* head = lc0023::Solution().mergeKLists(lists);
    std::vector<int> result = to_vector(head);
    free_list(head);
    return result;
}

TEST(MergeKSortedListsTest, Example1) {
    EXPECT_EQ(solve({{1, 4, 5}, {1, 3, 4}, {2, 6}}), (std::vector<int>{1, 1, 2, 3, 4, 4, 5, 6}));
}

TEST(MergeKSortedListsTest, NoLists) {
    EXPECT_EQ(solve({}), std::vector<int>{});
}

TEST(MergeKSortedListsTest, SomeListsEmpty) {
    EXPECT_EQ(solve({{}, {2}, {}, {1, 3}}), (std::vector<int>{1, 2, 3}));
}
