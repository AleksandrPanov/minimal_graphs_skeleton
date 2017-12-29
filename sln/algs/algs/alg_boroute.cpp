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
EdgesWeight algBoroute(const EdgesWeight & edges, int n)
{
	DisjointSet set(n);
	int tmp;
	EdgesWeight result;
	result.reserve(n - 1);
	const EdgeWeight emptyEdge = EdgeWeight(INF, Edge(-1, -1));
	EdgesWeight minEdges(n, emptyEdge);
	while (1)
	{
		tmp = set.getNumSet();
		for (auto& edge : edges)
		{
			int set1 = set.find_set(edge.v1), set2 = set.find_set(edge.v2);
			if (set1 != set2)
			{
				minEdges[set1] = std::min(minEdges[set1], edge);
				minEdges[set2] = std::min(minEdges[set2], edge);
			}
		}
		for (auto edge : minEdges)
		{
			if (edge.w != INF)
			{
				int set1 = set.find_set(edge.v1), set2 = set.find_set(edge.v2);
				if (set.union_sets(set1, set2))
				{
					minEdges[set1] = emptyEdge;
					minEdges[set2] = emptyEdge;
					result.push_back(edge);
				}
			}
		}
		if (set.getNumSet() == tmp)
			return result;
	}
	return result;
}
