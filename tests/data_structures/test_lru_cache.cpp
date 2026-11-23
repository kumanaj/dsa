#include <gtest/gtest.h>
#include "data_structures/lru_cache.hpp"

TEST(LruCacheTest, MissingKeyReturnsNullopt) {
    LruCache cache(2);
    EXPECT_EQ(cache.get(1), std::nullopt);
    EXPECT_EQ(cache.size(), 0u);
}

TEST(LruCacheTest, PutAndGet) {
    LruCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    EXPECT_EQ(cache.get(1), 10);
    EXPECT_EQ(cache.get(2), 20);
    EXPECT_EQ(cache.size(), 2u);
}

TEST(LruCacheTest, PutUpdatesExistingKey) {
    LruCache cache(2);
    cache.put(1, 10);
    cache.put(1, 11);
    EXPECT_EQ(cache.get(1), 11);
    EXPECT_EQ(cache.size(), 1u);
}

TEST(LruCacheTest, EvictsLeastRecentlyUsed) {
    LruCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);   // evicts 1
    EXPECT_EQ(cache.get(1), std::nullopt);
    EXPECT_EQ(cache.get(2), 20);
    EXPECT_EQ(cache.get(3), 30);
    EXPECT_EQ(cache.size(), 2u);
}

TEST(LruCacheTest, GetRefreshesRecency) {
    LruCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    cache.get(1);       // 2 is now least recently used
    cache.put(3, 30);   // evicts 2
    EXPECT_EQ(cache.get(2), std::nullopt);
    EXPECT_EQ(cache.get(1), 10);
    EXPECT_EQ(cache.get(3), 30);
}

TEST(LruCacheTest, PutRefreshesRecency) {
    LruCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(1, 11);   // 2 is now least recently used
    cache.put(3, 30);   // evicts 2
    EXPECT_EQ(cache.get(2), std::nullopt);
    EXPECT_EQ(cache.get(1), 11);
}

TEST(LruCacheTest, CapacityOne) {
    LruCache cache(1);
    cache.put(1, 10);
    cache.put(2, 20);
    EXPECT_EQ(cache.get(1), std::nullopt);
    EXPECT_EQ(cache.get(2), 20);
    EXPECT_EQ(cache.size(), 1u);
}

TEST(LruCacheTest, LeetCodeExample) {
    LruCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(2), std::nullopt);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(1), std::nullopt);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}
