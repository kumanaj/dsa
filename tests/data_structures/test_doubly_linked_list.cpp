#include <gtest/gtest.h>
#include "data_structures/doubly_linked_list.hpp"

TEST(DoublyLinkedListTest, StartsEmpty) {
    DoublyLinkedList<int> list;
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0u);
    EXPECT_EQ(list.front(), std::nullopt);
    EXPECT_EQ(list.back(), std::nullopt);
}

TEST(DoublyLinkedListTest, PushFront) {
    DoublyLinkedList<int> list;
    list.push_front(10);
    list.push_front(20);
    EXPECT_EQ(list.front(), 20);
    EXPECT_EQ(list.back(), 10);
    EXPECT_EQ(list.size(), 2u);
}

TEST(DoublyLinkedListTest, PushBack) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 2);
    EXPECT_EQ(list.size(), 2u);
}

TEST(DoublyLinkedListTest, GetAndIndex) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(2), 3);
    list[1] = 42;
    EXPECT_EQ(list[1], 42);
}

TEST(DoublyLinkedListTest, PopFront) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_EQ(list.front(), 2);
    EXPECT_EQ(list.pop_front(), 2);
    EXPECT_TRUE(list.empty());
}

TEST(DoublyLinkedListTest, PopBack) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.pop_back(), 2);
    EXPECT_EQ(list.back(), 1);
    EXPECT_EQ(list.pop_back(), 1);
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.back(), std::nullopt);
}

TEST(DoublyLinkedListTest, PopThrowsOnEmpty) {
    DoublyLinkedList<int> list;
    EXPECT_THROW(list.pop_front(), std::underflow_error);
    EXPECT_THROW(list.pop_back(), std::underflow_error);
}

TEST(DoublyLinkedListTest, MixedEnds) {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_front(1);
    list.push_back(3);
    EXPECT_EQ(list.pop_back(), 3);
    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_EQ(list.front(), 2);
    EXPECT_EQ(list.back(), 2);
}

TEST(DoublyLinkedListTest, ClearThenReuse) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.front(), std::nullopt);

    list.push_back(3);
    EXPECT_EQ(list.front(), 3);
    EXPECT_EQ(list.back(), 3);
    EXPECT_EQ(list.size(), 1u);
}

TEST(DoublyLinkedListTest, ConstAccess) {
    DoublyLinkedList<int> list;
    list.push_back(5);
    const DoublyLinkedList<int>& view = list;
    EXPECT_EQ(view.get(0), 5);
    EXPECT_EQ(view[0], 5);
}
