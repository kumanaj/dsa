#include <gtest/gtest.h>
#include <vector>
#include "problems/05_linked_list/0206_reverse_linked_list.hpp"

static std::vector<int> solve(const std::vector<int>& values) {
    ListNode* head = lc0206::Solution().reverseList(build_list(values));
    std::vector<int> result = to_vector(head);
    free_list(head);
    return result;
}

TEST(ReverseLinkedListTest, Example1) {
    EXPECT_EQ(solve({1, 2, 3, 4, 5}), (std::vector<int>{5, 4, 3, 2, 1}));
}

TEST(ReverseLinkedListTest, TwoNodes) {
    EXPECT_EQ(solve({1, 2}), (std::vector<int>{2, 1}));
}

TEST(ReverseLinkedListTest, Empty) {
    EXPECT_EQ(solve({}), std::vector<int>{});
}
