#include <gtest/gtest.h>
#include "data_structures/linked_list/doubly_linked_list.hpp"

TEST(DoublyLinkListTest, StartsEmpty) {
    DoublyLinkedList<int> list;
    EXPECT_TRUE(list.is_empty());
    EXPECT_EQ(list.get_size(), 0u);
}

TEST(DoublyLinkListTest, PushFront) {
    DoublyLinkedList<int> list;
    list.push_front(10);
    list.push_front(20);
    EXPECT_EQ(list.front(), 20);
    EXPECT_EQ(list.get_size(), 2u);
}

TEST(DoublyLinkListTest, PushBack) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.front(), 1);
}

TEST(DoublyLinkListTest, PopFront) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_front();
    EXPECT_EQ(list.front(), 2);
}

TEST(DoublyLinkListTest, PopThrowsOnEmpty) {
    DoublyLinkedList<int> list;
    EXPECT_THROW(list.pop_front(), std::underflow_error);
}

TEST(DoublyLinkListTest, Clear) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    EXPECT_TRUE(list.is_empty());
}
