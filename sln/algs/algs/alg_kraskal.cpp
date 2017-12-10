#include "alg_kraskal.h"
#include "../../disjoint_sets/disjoint_sets.h"
#include "../../graphs/tree.h"
#include <algorithm>

#define v1 second.first
#define v2 second.second

void algKraskal(Edges & edges, Tree& tree)
{
	int m = edges.size();
	DisjoinSet set(m);
	std::sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		auto edge = edges[i];
		if (set.find_set(edge.v1) != set.find_set(edge.v2))
		{
			set.union_sets(edge.v1, edge.v2);

		}
	}
}
