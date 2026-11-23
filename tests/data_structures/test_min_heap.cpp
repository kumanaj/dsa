#include <gtest/gtest.h>
#include <vector>
#include "data_structures/min_heap.hpp"

TEST(MinHeapTest, StartsEmpty) {
    MinHeap<int> h;
    EXPECT_TRUE(h.empty());
    EXPECT_EQ(h.size(), 0u);
    EXPECT_EQ(h.top(), std::nullopt);
}

TEST(MinHeapTest, PushKeepsMinOnTop) {
    MinHeap<int> h;
    h.push(5);
    EXPECT_EQ(h.top(), 5);
    h.push(3);
    EXPECT_EQ(h.top(), 3);
    h.push(8);
    EXPECT_EQ(h.top(), 3);
    EXPECT_EQ(h.size(), 3u);
}

TEST(MinHeapTest, PopReturnsInSortedOrder) {
    MinHeap<int> h;
    for (int v : {5, 1, 4, 2, 3}) {
        h.push(v);
    }
    for (int i = 1; i <= 5; i++) {
        EXPECT_EQ(h.pop(), i);
    }
    EXPECT_TRUE(h.empty());
}

TEST(MinHeapTest, PopThrowsOnEmpty) {
    MinHeap<int> h;
    EXPECT_THROW(h.pop(), std::underflow_error);
}

TEST(MinHeapTest, KeepsDuplicates) {
    MinHeap<int> h;
    h.push(2);
    h.push(2);
    h.push(1);
    EXPECT_EQ(h.pop(), 1);
    EXPECT_EQ(h.pop(), 2);
    EXPECT_EQ(h.pop(), 2);
}

TEST(MinHeapTest, BuildFromVector) {
    std::vector<int> values = {9, 4, 7, 1, 8, 2};
    MinHeap<int> h(values);
    EXPECT_EQ(h.size(), 6u);
    EXPECT_EQ(h.top(), 1);
    for (int expected : {1, 2, 4, 7, 8, 9}) {
        EXPECT_EQ(h.pop(), expected);
    }
}

TEST(MinHeapTest, SortsManyValues) {
    MinHeap<int> h;
    for (int i = 0; i < 100; i++) {
        h.push((i * 37) % 100);   // every value 0..99 once, shuffled
    }
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(h.pop(), i);
    }
}

TEST(MinHeapTest, ClearThenReuse) {
    MinHeap<int> h;
    h.push(1);
    h.push(2);
    h.clear();
    EXPECT_TRUE(h.empty());
    h.push(3);
    EXPECT_EQ(h.top(), 3);
}
