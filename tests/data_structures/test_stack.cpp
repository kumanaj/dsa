#include <gtest/gtest.h>
#include "data_structures/stack.hpp"

TEST(StackTest, StartsEmpty) {
    Stack<int> s;
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0u);
    EXPECT_EQ(s.top(), std::nullopt);
}

TEST(StackTest, PushAndTop) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    EXPECT_EQ(s.size(), 2u);
    EXPECT_EQ(s.top(), 2);
}

TEST(StackTest, PopIsLastInFirstOut) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.pop(), 3);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 1);
    EXPECT_TRUE(s.empty());
}

TEST(StackTest, PopThrowsOnEmpty) {
    Stack<int> s;
    EXPECT_THROW(s.pop(), std::underflow_error);
}

TEST(StackTest, ClearThenReuse) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.clear();
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.top(), std::nullopt);
    s.push(3);
    EXPECT_EQ(s.size(), 1u);
    EXPECT_EQ(s.top(), 3);
}
