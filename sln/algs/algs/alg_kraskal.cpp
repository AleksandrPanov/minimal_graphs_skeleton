#include "alg_kraskal.h"
#include "../../disjoint_sets/disjoint_sets.h"
#include "../../graphs/tree.h"
#include <algorithm>

#define v1 second.first
#define v2 second.second

using std::vector;
using std::pair;

Tree algKraskal(EdgesWeight &edges, int n)
{
	DisjoinSet set(n);
	Tree tree(n);
	std::sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		auto edge = edges[i];
		int nameSet1 = set.find_set(edge.v1);
		int nameSet2 = set.find_set(edge.v2);
		if (nameSet1 != nameSet2)
		{
			set.union_sets(edge.v1, edge.v2);
			tree.unionRoots(nameSet1, nameSet2, edge.first);
		}
	}
	return tree;
}
