#include <gtest/gtest.h>
#include <vector>
#include "problems/05_linked_list/0143_reorder_list.hpp"

static std::vector<int> solve(const std::vector<int>& values) {
    ListNode* head = build_list(values);
    lc0143::Solution().reorderList(head);
    std::vector<int> result = to_vector(head);
    free_list(head);
    return result;
}

TEST(ReorderListTest, EvenLength) {
    EXPECT_EQ(solve({1, 2, 3, 4}), (std::vector<int>{1, 4, 2, 3}));
}

TEST(ReorderListTest, OddLength) {
    EXPECT_EQ(solve({1, 2, 3, 4, 5}), (std::vector<int>{1, 5, 2, 4, 3}));
}

TEST(ReorderListTest, SingleNode) {
    EXPECT_EQ(solve({1}), std::vector<int>{1});
}
