#include <gtest/gtest.h>
#include <optional>
#include <string>
#include <vector>
#include "problems/07_trees/0297_serialize_and_deserialize_binary_tree.hpp"

using Level = std::vector<std::optional<int>>;

// Any format is fine as long as the tree survives the round trip.
static Level round_trip(const Level& tree) {
    TreeNode* root = build_tree(tree);
    lc0297::Codec codec;
    std::string data = codec.serialize(root);
    TreeNode* copy = codec.deserialize(data);
    Level result = to_level_order(copy);
    free_tree(root);
    free_tree(copy);
    return result;
}

TEST(SerializeAndDeserializeBinaryTreeTest, Example1) {
    Level tree = {1, 2, 3, null, null, 4, 5};
    EXPECT_EQ(round_trip(tree), tree);
}

TEST(SerializeAndDeserializeBinaryTreeTest, Empty) {
    EXPECT_EQ(round_trip({}), Level{});
}

TEST(SerializeAndDeserializeBinaryTreeTest, NegativeAndMultiDigitValues) {
    Level tree = {-1000, 1000, null, 12, -3};
    EXPECT_EQ(round_trip(tree), tree);
}
