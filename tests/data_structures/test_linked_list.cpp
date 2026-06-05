#include <gtest/gtest.h>
#include "linked_list/linked_list.hpp"

TEST(LinkedListTest, StartsEmpty) {
    LinkedList<int> l;
    EXPECT_TRUE(l.empty());
    EXPECT_EQ(l.size(), 0u);
}
TEST(LinkedListTest, PushFront) {
    LinkedList<int> l;
    l.push_front(10); l.push_front(20);
    EXPECT_EQ(l.front(), 20);
    EXPECT_EQ(l.size(), 2u);
}
TEST(LinkedListTest, PushBack) {
    LinkedList<int> l;
    l.push_back(1); l.push_back(2);
    EXPECT_EQ(l.front(), 1);
}
TEST(LinkedListTest, PopFront) {
    LinkedList<int> l;
    l.push_back(1); l.push_back(2);
    l.pop_front();
    EXPECT_EQ(l.front(), 2);
}
TEST(LinkedListTest, PopThrowsOnEmpty) {
    LinkedList<int> l;
    EXPECT_THROW(l.pop_front(), std::underflow_error);
}
TEST(LinkedListTest, Clear) {
    LinkedList<int> l;
    l.push_back(1); l.push_back(2);
    l.clear();
    EXPECT_TRUE(l.empty());
}
