#include "alg_kraskal.h"
#include "../../disjoint_sets/disjoint_sets.h"
#include "../../disjoint_sets/disjont_sets_array.h"
#include "../../disjoint_sets/disjoint_sets_tree.h"
#include <algorithm>
#define v1 second.first
#define v2 second.second
#define w first

using std::vector;
using std::pair;

typedef std::pair<int, int> Edge;
typedef std::pair<int, std::pair<int, int>> EdgeWeight;

EdgesWeight algKraskal(EdgesWeight &edges, int n, TypeDisjointSet choise)
{
	AbstractDisjointSet *set;
	if (choise == TypeDisjointSet::array)
	{
		set = new DisjointSetArray(n);
	}
	else if (choise == TypeDisjointSet::tree_full_optimization)
	{
		set =new DisjointSet(n);
	}
	else if (choise == TypeDisjointSet::tree_rank)
	{
		set = new DisjointSetRank(n);
	}
	EdgesWeight result;
	result.reserve(n - 1);
	std::sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		auto edge = edges[i];
		int nameSet1 = set->find_set(edge.v1);
		int nameSet2 = set->find_set(edge.v2);
		if (nameSet1 != nameSet2)
		{
			set->union_sets(edge.v1, edge.v2);
			result.emplace_back(EdgeWeight(edge.w, Edge(edge.v1, edge.v2)));
		}
	}
	return result;
}
