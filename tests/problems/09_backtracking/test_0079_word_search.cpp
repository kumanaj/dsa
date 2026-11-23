#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "problems/09_backtracking/0079_word_search.hpp"

using Board = std::vector<std::vector<char>>;

static bool solve(Board board, const std::string& word) {
    return lc0079::Solution().exist(board, word);
}

static const Board kBoard = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

TEST(WordSearchTest, Example1) {
    EXPECT_TRUE(solve(kBoard, "ABCCED"));
}

TEST(WordSearchTest, Example2) {
    EXPECT_TRUE(solve(kBoard, "SEE"));
}

TEST(WordSearchTest, CellUsedTwice) {
    EXPECT_FALSE(solve(kBoard, "ABCB"));
}
