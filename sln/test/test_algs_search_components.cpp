#include "../../gtest/gtest/gtest.h"
#include "../algs/algs/connected_component.h"
using std::pair;
using std::vector;
typedef std::pair<int, int> Edge;
typedef std::pair<int, std::pair<int, int>> EdgeWeight;

EdgesWeight getGraph1()
{
	EdgesWeight g;
	EdgeWeight e0(1,Edge(0,1)), e1(1, Edge(0, 2)), e2(1, Edge(5, 6)), e3(1, Edge(3, 4)), e4(1, Edge(2, 1));
	g.push_back(e0);
	g.push_back(e1);
	g.push_back(e2);
	g.push_back(e3);
	g.push_back(e4);
	return g;
}

TEST(alg_connected_comp, adjacency_list_is_right)
{
	int n = 7;
	auto g = getGraph1();
	vector<vector<pair<int, int>>> adjacencyList;
	setAdjacencyList(adjacencyList, g, n);
	EXPECT_EQ(adjacencyList[0].size(),2);
	EXPECT_EQ(adjacencyList[0][0].first, 1);
	EXPECT_EQ(adjacencyList[0][1].first, 2);

	EXPECT_EQ(adjacencyList[1].size(), 2);
	EXPECT_EQ(adjacencyList[1][0].first, 0);
	EXPECT_EQ(adjacencyList[1][1].first, 2);

	EXPECT_EQ(adjacencyList[2].size(), 2);
	EXPECT_EQ(adjacencyList[2][0].first, 0);
	EXPECT_EQ(adjacencyList[2][1].first, 1);
}

TEST(alg_connected_comp, bfs_is_right)
{
	int n = 7;
	auto g = getGraph1();
	vector<vector<pair<int, int>>> adjacencyList;
	setAdjacencyList(adjacencyList, g, n);
	vector<bool> was(7, false);
	auto component1 = bfs(0, was, adjacencyList);
	auto component2 = bfs(3, was, adjacencyList);
	auto component3 = bfs(5, was, adjacencyList);
	EXPECT_EQ(component1.size(), 3);
	EXPECT_EQ(component2.size(), 1);
	EXPECT_EQ(component3.size(), 1);
}