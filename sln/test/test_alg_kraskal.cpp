#include "../../gtest/gtest/gtest.h"
#include "../algs/algs/alg_kraskal.h"
#include "../graphs/tree.h"
using std::pair;
typedef pair<int, pair<int,int>> EdgeWeight;
typedef pair<int, int> Edge;
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
TEST(alg_kraskal, alg_kraskal_work1)
{
	int n;
	auto graph = getGraph(n);
	auto ansTree = algKraskal(graph, n);
}