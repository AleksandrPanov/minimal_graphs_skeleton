#include "alg_kraskal.h"
#include "../../disjoint_sets/disjoint_sets.h"
#include "../../graphs/tree.h"
#include <algorithm>

#define v1 second.first
#define v2 second.second

using std::vector;
using std::pair;

void algKraskal(EdgesWeight & edges, int n, vector<Tree*> &trees)
{
	DisjoinSet set(n);
	trees = vector<Tree*>(n);
	for (int i = 0; i < n; i++)
		trees[i] = new Tree(i);
	std::sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		auto edge = edges[i];
		int nameSet1 = set.find_set(edge.v1);
		int nameSet2 = set.find_set(edge.v2);
		if (nameSet1 != nameSet2)
		{
			set.union_sets(edge.v1, edge.v2);
			trees[nameSet1]->unionTrees(*trees[nameSet2]);
			trees[nameSet2] = 0;
		}
	}
}
