#include <gtest/gtest.h>
#include "data_structures/singly_linked_list.hpp"

TEST(SinglyLinkedListTest, StartsEmpty) {
    SinglyLinkedList<int> list;
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0u);
    EXPECT_EQ(list.front(), std::nullopt);
    EXPECT_EQ(list.back(), std::nullopt);
}

TEST(SinglyLinkedListTest, PushFront) {
    SinglyLinkedList<int> list;
    list.push_front(10);
    list.push_front(20);
    EXPECT_EQ(list.front(), 20);
    EXPECT_EQ(list.back(), 10);
    EXPECT_EQ(list.size(), 2u);
}

TEST(SinglyLinkedListTest, PushBack) {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 2);
    EXPECT_EQ(list.size(), 2u);
}

TEST(SinglyLinkedListTest, GetAndIndex) {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(2), 3);
    list[1] = 42;
    EXPECT_EQ(list[1], 42);
}

TEST(SinglyLinkedListTest, PopFront) {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_EQ(list.pop_front(), 2);
    EXPECT_TRUE(list.empty());
}

TEST(SinglyLinkedListTest, PopBack) {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.pop_back(), 2);
    EXPECT_EQ(list.back(), 1);
    EXPECT_EQ(list.pop_back(), 1);
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.front(), std::nullopt);
}

TEST(SinglyLinkedListTest, PopThrowsOnEmpty) {
    SinglyLinkedList<int> list;
    EXPECT_THROW(list.pop_front(), std::underflow_error);
    EXPECT_THROW(list.pop_back(), std::underflow_error);
}

TEST(SinglyLinkedListTest, ClearThenReuse) {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.front(), std::nullopt);

    list.push_back(3);
    EXPECT_EQ(list.front(), 3);
    EXPECT_EQ(list.size(), 1u);
}

TEST(SinglyLinkedListTest, ConstAccess) {
    SinglyLinkedList<int> list;
    list.push_back(5);
    const SinglyLinkedList<int>& view = list;
    EXPECT_EQ(view.get(0), 5);
    EXPECT_EQ(view[0], 5);
}
