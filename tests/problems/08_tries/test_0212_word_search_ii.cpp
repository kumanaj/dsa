#include <gtest/gtest.h>
#include <algorithm>
#include <string>
#include <vector>
#include "problems/08_tries/0212_word_search_ii.hpp"

using Board = std::vector<std::vector<char>>;
using Words = std::vector<std::string>;

// Words may come back in any order, so sort before comparing.
static Words solve(Board board, Words words) {
    Words result = lc0212::Solution().findWords(board, words);
    std::sort(result.begin(), result.end());
    return result;
}

TEST(WordSearchIiTest, Example1) {
    Board board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    EXPECT_EQ(solve(board, {"oath", "pea", "eat", "rain"}), (Words{"eat", "oath"}));
}

TEST(WordSearchIiTest, CellUsedTwice) {
    EXPECT_EQ(solve({{'a', 'b'}, {'c', 'd'}}, {"abcb"}), Words{});
}

TEST(WordSearchIiTest, FoundByTwoPathsListedOnce) {
    // "ab" can be spelled along either row; "aaa" would need a third 'a'.
    EXPECT_EQ(solve({{'a', 'b'}, {'a', 'b'}}, {"ab", "aaa"}), Words{"ab"});
}
