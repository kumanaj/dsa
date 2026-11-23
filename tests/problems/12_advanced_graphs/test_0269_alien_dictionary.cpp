#include <gtest/gtest.h>
#include <set>
#include <string>
#include <vector>
#include "problems/12_advanced_graphs/0269_alien_dictionary.hpp"

using Words = std::vector<std::string>;

static std::string solve(Words words) {
    return lc0269::Solution().foreignDictionary(words);
}

// Several orders can be correct, so check the answer against the rules instead of one expected string:
// every letter in the words appears exactly once, and each adjacent word pair is in order.
static bool is_valid_order(const Words& words, const std::string& order) {
    std::set<char> letters;
    for (const auto& w : words) {
        letters.insert(w.begin(), w.end());
    }
    if (order.size() != letters.size() || std::set<char>(order.begin(), order.end()) != letters) return false;
    for (size_t i = 0; i + 1 < words.size(); i++) {
        const std::string& a = words[i];
        const std::string& b = words[i + 1];
        for (size_t j = 0; j < a.size() && j < b.size(); j++) {
            if (a[j] != b[j]) {
                if (order.find(a[j]) > order.find(b[j])) return false;
                break;
            }
        }
    }
    return true;
}

TEST(AlienDictionaryTest, Example1) {
    Words words = {"z", "o"};
    EXPECT_TRUE(is_valid_order(words, solve(words)));
}

TEST(AlienDictionaryTest, Example2) {
    Words words = {"hrn", "hrf", "er", "enn", "rfnn"};
    EXPECT_TRUE(is_valid_order(words, solve(words)));
}

TEST(AlienDictionaryTest, Impossible) {
    EXPECT_EQ(solve({"abc", "ab"}), "");      // prefix after the longer word
    EXPECT_EQ(solve({"z", "x", "z"}), "");    // z < x and x < z
}
