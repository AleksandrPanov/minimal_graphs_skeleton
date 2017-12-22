#include "alg_boroute.h"
#include "../../disjoint_sets/disjoint_sets.h"
#include <algorithm>
using std::vector;

typedef std::pair<int, int> Edge;
typedef std::pair<int, std::pair<int, int>> EdgeWeight;

#define v1 second.first
#define v2 second.second
#define w first

const int INF = 1000000000;
EdgesWeight algBoroute(EdgesWeight & edges, int n)
{
	DisjointSet set(n);
	EdgesWeight result;
	result.reserve(n - 1);
	const EdgeWeight emptyEdge = EdgeWeight(INF, Edge(-1, -1));
	EdgesWeight minEdges(n, emptyEdge);
	while (1)
	{
		for (auto& edge : edges)
		{
			if (set.find_set(edge.v1) != set.find_set(edge.v2))
			{
				minEdges[edge.v1] = std::min(minEdges[edge.v1], edge);
				minEdges[edge.v2] = std::min(minEdges[edge.v2], edge);
			}
		}
		for (auto edge : minEdges)
		{
			if (edge.w != INF)
			{
				set.union_sets(edge.v1, edge.v2);
				result.push_back(edge);
				minEdges[edge.v1] = emptyEdge;
				minEdges[edge.v2] = emptyEdge;
				if (set.getNumSet() == 1)
					return result;
			}
		}
	}
	return result;
}
