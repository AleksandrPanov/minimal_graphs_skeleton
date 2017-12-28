#include "../../gtest/gtest/gtest.h"
#include "../disjoint_sets/disjont_sets_array.h"
TEST(disjoint_sets_array, can_create_correctly)
{
	DisjointSetArray set(10);
	int t = set.getSize();
	EXPECT_EQ(set.getSize(), 10);
	EXPECT_EQ(set.getNumSet(), 10);
}

TEST(disjoint_sets_array, can_union_correctly)
{
	DisjointSetArray set(10);
	set.union_sets(1, 0);
	EXPECT_EQ(set.getSize(), 10);
	EXPECT_EQ(set.getNumSet(), 9);
	EXPECT_EQ(set.find_set(0), set.find_set(1));
}

TEST(disjoint_sets_array, can_union_all_correctly)
{
	DisjointSetArray set(10);
	for (int i = 1; i < set.getSize(); i++)
	{
		set.union_sets(i, i - 1);
	}
	EXPECT_EQ(set.getSize(), 10);
	EXPECT_EQ(set.getNumSet(), 1);
	int t0 = set.find_set(0);
	for (int i = 1; i < set.getSize(); i++)
	{
		int ti = set.find_set(i);
		EXPECT_EQ(t0, ti);
	}
}