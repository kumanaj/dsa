#include <gtest/gtest.h>
#include <string>
#include "data_structures/hash_map.hpp"

TEST(HashMapTest, StartsEmpty) {
    HashMap<std::string, int> m;
    EXPECT_TRUE(m.empty());
    EXPECT_EQ(m.size(), 0u);
    EXPECT_EQ(m.get("a"), std::nullopt);
    EXPECT_FALSE(m.contains("a"));
}

TEST(HashMapTest, PutAndGet) {
    HashMap<std::string, int> m;
    m.put("one", 1);
    m.put("two", 2);
    EXPECT_EQ(m.size(), 2u);
    EXPECT_EQ(m.get("one"), 1);
    EXPECT_EQ(m.get("two"), 2);
    EXPECT_TRUE(m.contains("one"));
    EXPECT_FALSE(m.contains("three"));
}

TEST(HashMapTest, PutOverwritesExistingKey) {
    HashMap<std::string, int> m;
    m.put("a", 1);
    m.put("a", 2);
    EXPECT_EQ(m.size(), 1u);
    EXPECT_EQ(m.get("a"), 2);
}

TEST(HashMapTest, Remove) {
    HashMap<std::string, int> m;
    m.put("a", 1);
    m.put("b", 2);
    EXPECT_TRUE(m.remove("a"));
    EXPECT_FALSE(m.contains("a"));
    EXPECT_EQ(m.get("b"), 2);
    EXPECT_EQ(m.size(), 1u);
    EXPECT_FALSE(m.remove("a"));   // already gone
}

TEST(HashMapTest, RemoveFromMiddleOfChain) {
    // std::hash<int> is usually the identity, so with 8 buckets these all land in bucket 0.
    HashMap<int, int> m;
    for (int k : {0, 8, 16, 24}) {
        m.put(k, k * 10);
    }
    EXPECT_TRUE(m.remove(8));
    EXPECT_FALSE(m.contains(8));
    EXPECT_EQ(m.get(0), 0);
    EXPECT_EQ(m.get(16), 160);
    EXPECT_EQ(m.get(24), 240);
    EXPECT_EQ(m.size(), 3u);
}

TEST(HashMapTest, GrowsPastInitialBuckets) {
    HashMap<int, int> m;
    for (int i = 0; i < 1000; i++) {
        m.put(i, i * i);
    }
    EXPECT_EQ(m.size(), 1000u);
    for (int i = 0; i < 1000; i++) {
        EXPECT_EQ(m.get(i), i * i);
    }
}

TEST(HashMapTest, ClearThenReuse) {
    HashMap<std::string, int> m;
    m.put("a", 1);
    m.put("b", 2);
    m.clear();
    EXPECT_TRUE(m.empty());
    EXPECT_FALSE(m.contains("a"));
    m.put("c", 3);
    EXPECT_EQ(m.size(), 1u);
    EXPECT_EQ(m.get("c"), 3);
}
