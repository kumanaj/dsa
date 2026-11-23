#include <gtest/gtest.h>
#include "data_structures/queue.hpp"

TEST(QueueTest, StartsEmpty) {
    Queue<int> q;
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(q.size(), 0u);
    EXPECT_EQ(q.front(), std::nullopt);
    EXPECT_EQ(q.back(), std::nullopt);
}

TEST(QueueTest, PushAndPeek) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    EXPECT_EQ(q.size(), 2u);
    EXPECT_EQ(q.front(), 1);
    EXPECT_EQ(q.back(), 2);
}

TEST(QueueTest, PopIsFirstInFirstOut) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    EXPECT_EQ(q.pop(), 1);
    EXPECT_EQ(q.pop(), 2);
    EXPECT_EQ(q.pop(), 3);
    EXPECT_TRUE(q.empty());
}

TEST(QueueTest, PopThrowsOnEmpty) {
    Queue<int> q;
    EXPECT_THROW(q.pop(), std::underflow_error);
}

TEST(QueueTest, WrapsAround) {
    Queue<int> q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.pop();
    q.push(4);
    q.push(5);   // wraps to the start of the buffer
    q.push(6);
    EXPECT_EQ(q.size(), 4u);
    EXPECT_EQ(q.front(), 3);
    EXPECT_EQ(q.back(), 6);
    EXPECT_EQ(q.pop(), 3);
    EXPECT_EQ(q.pop(), 4);
    EXPECT_EQ(q.pop(), 5);
    EXPECT_EQ(q.pop(), 6);
}

TEST(QueueTest, GrowsWhileWrapped) {
    Queue<int> q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();     // head is no longer at index 0
    q.push(4);
    q.push(5);   // buffer is full and wrapped
    q.push(6);   // forces a resize
    for (int i = 2; i <= 6; i++) {
        EXPECT_EQ(q.pop(), i);
    }
}

TEST(QueueTest, GrowsPastInitialCapacity) {
    Queue<int> q(2);
    for (int i = 0; i < 100; i++) {
        q.push(i);
    }
    EXPECT_EQ(q.size(), 100u);
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(q.pop(), i);
    }
}

TEST(QueueTest, ClearThenReuse) {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.clear();
    EXPECT_TRUE(q.empty());
    q.push(3);
    EXPECT_EQ(q.size(), 1u);
    EXPECT_EQ(q.front(), 3);
    EXPECT_EQ(q.back(), 3);
}
