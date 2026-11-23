#include <gtest/gtest.h>
#include <vector>
#include "problems/05_linked_list/0141_linked_list_cycle.hpp"

// Builds the list, links the tail back to index pos (-1 = no cycle), runs the solution, then cleans up.
static bool solve(const std::vector<int>& values, int pos) {
    ListNode* head = build_list(values);
    ListNode* tail = head;
    ListNode* target = nullptr;
    for (int i = 0; tail != nullptr && tail->next != nullptr; i++, tail = tail->next) {
        if (i == pos) target = tail;
    }
    if (tail != nullptr && pos == static_cast<int>(values.size()) - 1) target = tail;
    if (tail != nullptr) tail->next = target;

    bool result = lc0141::Solution().hasCycle(head);

    if (tail != nullptr) tail->next = nullptr;   // break the cycle so it can be freed
    free_list(head);
    return result;
}

TEST(LinkedListCycleTest, Example1) {
    EXPECT_TRUE(solve({3, 2, 0, -4}, 1));
}

TEST(LinkedListCycleTest, CycleToHead) {
    EXPECT_TRUE(solve({1, 2}, 0));
    EXPECT_TRUE(solve({1}, 0));   // a node pointing at itself
}

TEST(LinkedListCycleTest, NoCycle) {
    EXPECT_FALSE(solve({1}, -1));
    EXPECT_FALSE(solve({}, -1));
    EXPECT_FALSE(solve({1, 2, 3}, -1));
}
