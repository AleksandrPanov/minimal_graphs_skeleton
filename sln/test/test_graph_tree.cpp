#include "../../gtest/gtest/gtest.h"
#include "../graphs/tree.h"
using std::pair;
TEST(graph_tree, can_create_correctly)
{
	Tree t(0);
	EXPECT_EQ(t.getSize(), 1);
	EXPECT_EQ(t.getEdges().size(), 0);
}

TEST(graph_tree, can_union_correctly)
{
	Tree t0(0), t1(1), t2(2), t3(3);
	t0.unionTrees(t1);
	t0.unionTrees(t2);
	t2.unionTrees(t3);
	//EXPECT_EQ(t0.getSize(), 4);
	std::vector<pair<int, int>> edges = t0.getEdges();
	EXPECT_EQ(edges.size(), 3);
	auto t = edges[0];
	auto res = pair<int, int>(0, 1);
	EXPECT_EQ(t, res);
}