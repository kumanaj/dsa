#include <gtest/gtest.h>
#include "data_structures/union_find.hpp"

TEST(UnionFindTest, StartsAsSingletons) {
    UnionFind uf(5);
    EXPECT_EQ(uf.size(), 5);
    EXPECT_EQ(uf.component_count(), 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(uf.find(i), i);
    }
    EXPECT_FALSE(uf.connected(0, 1));
    EXPECT_TRUE(uf.connected(2, 2));
}

TEST(UnionFindTest, UniteMergesSets) {
    UnionFind uf(5);
    EXPECT_TRUE(uf.unite(0, 1));
    EXPECT_TRUE(uf.connected(0, 1));
    EXPECT_EQ(uf.find(0), uf.find(1));
    EXPECT_EQ(uf.component_count(), 4);
}

TEST(UnionFindTest, UniteSameSetReturnsFalse) {
    UnionFind uf(5);
    uf.unite(0, 1);
    EXPECT_FALSE(uf.unite(1, 0));
    EXPECT_EQ(uf.component_count(), 4);
}

TEST(UnionFindTest, ConnectivityIsTransitive) {
    UnionFind uf(5);
    uf.unite(0, 1);
    uf.unite(1, 2);
    EXPECT_TRUE(uf.connected(0, 2));
    EXPECT_FALSE(uf.connected(0, 3));
    EXPECT_EQ(uf.component_count(), 3);
}

TEST(UnionFindTest, MergingTwoGroups) {
    UnionFind uf(6);
    uf.unite(0, 1);
    uf.unite(2, 3);
    EXPECT_FALSE(uf.connected(1, 2));
    EXPECT_EQ(uf.component_count(), 4);
    uf.unite(1, 3);
    EXPECT_TRUE(uf.connected(0, 2));
    EXPECT_EQ(uf.component_count(), 3);
}

TEST(UnionFindTest, LongChain) {
    UnionFind uf(1000);
    for (int i = 0; i + 1 < 1000; i++) {
        uf.unite(i, i + 1);
    }
    EXPECT_EQ(uf.component_count(), 1);
    EXPECT_TRUE(uf.connected(0, 999));
}
