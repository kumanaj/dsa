#include <gtest/gtest.h>
#include <vector>
#include "problems/05_linked_list/0019_remove_nth_node_from_end_of_list.hpp"

static std::vector<int> solve(const std::vector<int>& values, int n) {
    ListNode* head = lc0019::Solution().removeNthFromEnd(build_list(values), n);
    std::vector<int> result = to_vector(head);
    free_list(head);
    return result;
}

TEST(RemoveNthNodeFromEndOfListTest, Example1) {
    EXPECT_EQ(solve({1, 2, 3, 4, 5}, 2), (std::vector<int>{1, 2, 3, 5}));
}

TEST(RemoveNthNodeFromEndOfListTest, OnlyNode) {
    EXPECT_EQ(solve({1}, 1), std::vector<int>{});
}

TEST(RemoveNthNodeFromEndOfListTest, RemoveHead) {
    EXPECT_EQ(solve({1, 2}, 2), std::vector<int>{2});
}
