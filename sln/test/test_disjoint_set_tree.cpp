#include "../../gtest/gtest/gtest.h"
#include "../disjoint_sets/disjoint_sets_tree.h"
TEST(disjoint_sets_tree, can_create_correctly)
{
	DisjointSetRank set(10);
	EXPECT_EQ(set.getSize(), 10);
	EXPECT_EQ(set.getNumSet(), 10);
}

TEST(disjoint_sets_tree, can_union_correctly)
{
	DisjointSetRank set(10);
	set.union_sets(1, 0);
	EXPECT_EQ(set.getSize(), 10);
	EXPECT_EQ(set.getNumSet(), 9);
	EXPECT_EQ(set.find_set(0), set.find_set(1));
}

TEST(disjoint_sets_tree, can_union_all_correctly)
{
	DisjointSetRank set(10);
	for (int i = 1; i < set.getSize(); i++)
	{
		set.union_sets(i, i - 1);
	}
	EXPECT_EQ(set.getSize(), 10);
	EXPECT_EQ(set.getNumSet(), 1);
	for (int i = 1; i < set.getSize(); i++)
		EXPECT_EQ(set.find_set(0), set.find_set(i));
}