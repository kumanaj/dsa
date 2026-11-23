#pragma once
// ============================================================================
// 295. Find Median from Data Stream                                  [Hard]
// https://leetcode.com/problems/find-median-from-data-stream/
// Lists:   Blind 75, NeetCode 150
// Pattern: Heap / Priority Queue
// ----------------------------------------------------------------------------
// Implement a MedianFinder class:
//   MedianFinder()   creates an empty finder.
//   addNum(num)      adds an integer from the stream.
//   findMedian()     returns the median of everything added so far: the middle
//                    value, or the mean of the two middle values if the count
//                    is even.
//
// Example: addNum(1); addNum(2); findMedian() -> 1.5; addNum(3); findMedian() -> 2.0
//
// Constraints: -10^5 <= num <= 10^5; findMedian is only called when at least one number
//              has been added; at most 5 * 10^4 calls.
// Follow-up:   if every number is in [0, 100], how would you optimise it?
//              If 99% of the numbers are in [0, 100]?
// ----------------------------------------------------------------------------
// My notes (fill in after solving):
//   Approach:
//   Time: O(?)   Space: O(?)
// ============================================================================

#include <stdexcept>

namespace lc0295 {

class MedianFinder {
public:
    // TODO: not implemented yet
    MedianFinder() {
        throw std::logic_error("lc0295::MedianFinder::MedianFinder not implemented");
    }

    // TODO: not implemented yet
    void addNum(int num) {
        throw std::logic_error("lc0295::MedianFinder::addNum not implemented");
    }

    // TODO: not implemented yet
    double findMedian() {
        throw std::logic_error("lc0295::MedianFinder::findMedian not implemented");
    }
};

}  // namespace lc0295
