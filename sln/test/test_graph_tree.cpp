#include "../../gtest/gtest/gtest.h"
#include "../graphs/tree.h"
#include <fstream>
using std::cout;
using std::pair;
using std::ofstream;
Tree getTree()
{
	Tree tree(5);
	tree.unionRoots(1, 0);
	tree.unionRoots(1, 2);
	tree.unionRoots(3, 4);
	tree.unionRoots(1, 3);
	return tree;
}
TEST(graph_tree, can_create_correctly)
{
	Tree t(1);
	EXPECT_EQ(t.getSize(), 1);
	EXPECT_EQ(t.getRoot(), 0);
	EXPECT_EQ(t.getEdges().size(), 0);
}

TEST(graph_tree, can_union_correctly)
{
	Tree tree = getTree();
	EXPECT_EQ(tree.getRoot(), 1);
	EXPECT_EQ(tree.getNode(1).leftChild, 3);
	EXPECT_EQ(tree.getNode(3).parent, 1);
	EXPECT_EQ(tree.getNode(3).rightBrother, 2);
	EXPECT_EQ(tree.getNode(2).rightBrother, 0);
	EXPECT_EQ(tree.getNode(3).leftChild, 4);
}

TEST(graph_tree, can_print)
{
	Tree tree = getTree();
	std::vector<pair<int, int>> edges = tree.getEdges();
	Graph::printEdges(std::cout, edges);
}