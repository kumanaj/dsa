#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "problems/01_arrays_hashing/0271_encode_and_decode_strings.hpp"

// Any encoding is fine as long as decode(encode(strs)) gives back strs.
static std::vector<std::string> round_trip(std::vector<std::string> strs) {
    lc0271::Solution codec;
    std::string encoded = codec.encode(strs);
    return codec.decode(encoded);
}

TEST(EncodeAndDecodeStringsTest, Example1) {
    std::vector<std::string> strs = {"neet", "code", "love", "you"};
    EXPECT_EQ(round_trip(strs), strs);
}

TEST(EncodeAndDecodeStringsTest, EmptyListAndEmptyStrings) {
    EXPECT_EQ(round_trip({}), std::vector<std::string>{});
    std::vector<std::string> empties = {"", "", ""};
    EXPECT_EQ(round_trip(empties), empties);
}

TEST(EncodeAndDecodeStringsTest, DelimiterLikeCharacters) {
    // Breaks encodings that just join with a separator or assume no digits/'#'.
    std::vector<std::string> strs = {"4#ab", "#", "", ":;,|", "12#34#"};
    EXPECT_EQ(round_trip(strs), strs);
}
