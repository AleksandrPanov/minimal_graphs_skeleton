#include "../../gtest/gtest/gtest.h"
#include "../algs/algs/alg_kraskal.h"
#include "../algs/algs/alg_prima.h"
#include "../algs/algs/alg_boroute.h"
#include "../graphs/graph.h"
using std::pair;
using std::vector;
typedef std::pair<int, int> Edge;
typedef std::pair<int, std::pair<int, int>> EdgeWeight;
EdgesWeight getGraph(int &n)
{
	n = 6;
	EdgesWeight gr(7);
	gr[0] = EdgeWeight(2, Edge(0, 1));
	gr[1] = EdgeWeight(1, Edge(0, 2));
	gr[2] = EdgeWeight(1, Edge(0, 4));
	gr[3] = EdgeWeight(3, Edge(2, 3));
	gr[4] = EdgeWeight(5, Edge(5, 4));
	gr[5] = EdgeWeight(2, Edge(4, 3));
	gr[6] = EdgeWeight(1, Edge(4, 1));
	return gr;
}

EdgesWeight getGraph2(int &n)
{
	n = 6;
	EdgesWeight gr(10);
	gr[0] = EdgeWeight(1, Edge(0, 1));
	gr[1] = EdgeWeight(2, Edge(0, 2));
	gr[2] = EdgeWeight(5, Edge(2, 1));
	gr[3] = EdgeWeight(1, Edge(1, 3));
	gr[4] = EdgeWeight(2, Edge(0, 3));
	gr[5] = EdgeWeight(3, Edge(3, 2));
	gr[6] = EdgeWeight(2, Edge(1, 4));
	gr[7] = EdgeWeight(1, Edge(1, 5));
	gr[8] = EdgeWeight(3, Edge(4, 5));
	gr[9] = EdgeWeight(1, Edge(4, 2));
	return gr;
}
TEST(alg_kraskal, alg_kraskal_work1)
{
	int n;
	auto graph = getGraph(n);
	auto ansEdges = algKraskal(graph, n, TypeDisjointSet::tree_full_optimization);
	Graph::printEdges(std::cout, ansEdges);
	EXPECT_EQ(Graph::findWeight(ansEdges), 10);
}

TEST(alg_prima, alg_prima_work1)
{
	int n;
	auto graph = getGraph(n);
	vector<vector<int>> g = Graph::getAdjacencyMatrixFromEdges(graph, n);
	auto ansEdges = algPrima(g,n);
	Graph::printEdges(std::cout, ansEdges);
	EXPECT_EQ(Graph::findWeight(ansEdges), 10);
}

TEST(alg_boroute, alg_boroute_work1)
{
	int n;
	auto graph = getGraph(n);
	EdgesWeight ansEdges = algBoroute(graph, n);
	Graph::printEdges(std::cout, ansEdges);
	EXPECT_EQ(Graph::findWeight(ansEdges), 10);
}

TEST(alg_boroute, alg_boroute_work2)
{
	int n;
	auto graph = getGraph2(n);
	EdgesWeight ansEdges = algBoroute(graph, n);
	EdgesWeight ansEdges1 = algKraskal(graph, n, TypeDisjointSet::tree_full_optimization);
	Graph::printEdges(std::cout, ansEdges);
	EXPECT_EQ(Graph::findWeight(ansEdges), Graph::findWeight(ansEdges1));
}