#include <gtest/gtest.h>
#include "problems/10_heap/0295_find_median_from_data_stream.hpp"

TEST(FindMedianFromDataStreamTest, Example) {
    lc0295::MedianFinder finder;
    finder.addNum(1);
    finder.addNum(2);
    EXPECT_DOUBLE_EQ(finder.findMedian(), 1.5);
    finder.addNum(3);
    EXPECT_DOUBLE_EQ(finder.findMedian(), 2.0);
}

TEST(FindMedianFromDataStreamTest, SingleNumber) {
    lc0295::MedianFinder finder;
    finder.addNum(-7);
    EXPECT_DOUBLE_EQ(finder.findMedian(), -7.0);
}

TEST(FindMedianFromDataStreamTest, UnsortedWithNegatives) {
    lc0295::MedianFinder finder;
    finder.addNum(5);
    EXPECT_DOUBLE_EQ(finder.findMedian(), 5.0);
    finder.addNum(-1);
    EXPECT_DOUBLE_EQ(finder.findMedian(), 2.0);
    finder.addNum(3);
    EXPECT_DOUBLE_EQ(finder.findMedian(), 3.0);
    finder.addNum(8);
    EXPECT_DOUBLE_EQ(finder.findMedian(), 4.0);
}
