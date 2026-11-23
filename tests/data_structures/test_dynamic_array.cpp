#include <gtest/gtest.h>
#include "data_structures/dynamic_array.hpp"

TEST(DynamicArrayTest, StartsEmpty) {
    DynamicArray<int> arr;
    EXPECT_TRUE(arr.empty());
    EXPECT_EQ(arr.size(), 0u);
    EXPECT_EQ(arr.front(), std::nullopt);
    EXPECT_EQ(arr.back(), std::nullopt);
}

TEST(DynamicArrayTest, PushBack) {
    DynamicArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    EXPECT_EQ(arr.size(), 2u);
    EXPECT_EQ(arr.front(), 1);
    EXPECT_EQ(arr.back(), 2);
}

TEST(DynamicArrayTest, PushFront) {
    DynamicArray<int> arr;
    arr.push_front(1);
    arr.push_front(2);
    EXPECT_EQ(arr.size(), 2u);
    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 1);
}

TEST(DynamicArrayTest, InsertAt) {
    DynamicArray<int> arr;
    arr.insert_at(0, 1);   // [1]
    arr.insert_at(1, 3);   // [1, 3]  (index == size appends)
    arr.insert_at(1, 2);   // [1, 2, 3]
    EXPECT_EQ(arr.size(), 3u);
    EXPECT_EQ(arr.get(0), 1);
    EXPECT_EQ(arr.get(1), 2);
    EXPECT_EQ(arr.get(2), 3);
}

TEST(DynamicArrayTest, IndexWrites) {
    DynamicArray<int> arr;
    arr.insert_at(0, 1);
    arr[0] = 42;
    EXPECT_EQ(arr.get(0), 42);
}

TEST(DynamicArrayTest, RemoveAt) {
    DynamicArray<int> arr;
    arr.insert_at(0, 1);
    arr.insert_at(1, 2);
    arr.insert_at(2, 3);
    arr.remove_at(1);      // [1, 3]
    EXPECT_EQ(arr.size(), 2u);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 3);
}

TEST(DynamicArrayTest, PopFrontReturnsFirst) {
    DynamicArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    EXPECT_EQ(arr.pop_front(), 1);
    EXPECT_EQ(arr.pop_front(), 2);
    EXPECT_TRUE(arr.empty());
}

TEST(DynamicArrayTest, PopBackReturnsLast) {
    DynamicArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    EXPECT_EQ(arr.pop_back(), 2);
    EXPECT_EQ(arr.pop_back(), 1);
    EXPECT_TRUE(arr.empty());
}

TEST(DynamicArrayTest, PopThrowsOnEmpty) {
    DynamicArray<int> arr;
    EXPECT_THROW(arr.pop_front(), std::underflow_error);
    EXPECT_THROW(arr.pop_back(), std::underflow_error);
}

TEST(DynamicArrayTest, GrowsPastInitialCapacity) {
    DynamicArray<int> arr(2);
    for (int i = 0; i < 100; i++) {
        arr.push_back(i);
    }
    EXPECT_EQ(arr.size(), 100u);
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(arr[i], i);
    }
}

TEST(DynamicArrayTest, ShrinksAndKeepsElements) {
    DynamicArray<int> arr;
    for (int i = 0; i < 100; i++) {
        arr.push_back(i);
    }
    for (int i = 0; i < 95; i++) {
        arr.pop_front();
    }
    EXPECT_EQ(arr.size(), 5u);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arr[i], 95 + i);
    }
}

TEST(DynamicArrayTest, ClearThenReuse) {
    DynamicArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.clear();
    EXPECT_TRUE(arr.empty());
    arr.push_back(3);
    EXPECT_EQ(arr.size(), 1u);
    EXPECT_EQ(arr[0], 3);
}

TEST(DynamicArrayTest, InsertOwnElementWhileResizing) {
    DynamicArray<int> arr(2);
    arr.insert_at(0, 1);
    arr.insert_at(1, 2);       // full
    arr.insert_at(0, arr[1]);  // item refers into arr and a resize happens first
    EXPECT_EQ(arr.size(), 3u);
    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 2);
}

TEST(DynamicArrayTest, EmptyAfterPopBackThenRegrows) {
    DynamicArray<int> arr;
    for (int i = 0; i < 100; i++) {
        arr.push_back(i);
    }
    for (int i = 99; i >= 0; i--) {
        EXPECT_EQ(arr.pop_back(), i);
    }
    EXPECT_TRUE(arr.empty());
    arr.push_back(7);   // capacity must not have shrunk to 0
    EXPECT_EQ(arr[0], 7);
}

TEST(DynamicArrayTest, ConstAccess) {
    DynamicArray<int> arr;
    arr.insert_at(0, 5);
    const DynamicArray<int>& view = arr;
    EXPECT_EQ(view.get(0), 5);
    EXPECT_EQ(view[0], 5);
}
