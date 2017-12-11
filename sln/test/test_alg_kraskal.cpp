#include "../../gtest/gtest/gtest.h"
#include "../algs/algs/alg_kraskal.h"
using std::pair;
typedef pair<int, pair<int,int>> EdgeWeight;
typedef pair<int, int> Edge;
EdgesWeight SetGraph()
{
	EdgesWeight gr(8);
	gr[0] = EdgeWeight(3, Edge(0, 1));
	gr[1] = EdgeWeight(2, Edge(0, 2));
	gr[2] = EdgeWeight(1, Edge(0, 3));
	gr[3] = EdgeWeight(2, Edge(0, 4));
	gr[4] = EdgeWeight(1, Edge(0, 1));
}
TEST(alg_kraskal, alg_kraskal_work1)
{

}