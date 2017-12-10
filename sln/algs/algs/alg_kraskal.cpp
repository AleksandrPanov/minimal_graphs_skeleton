#include "alg_kraskal.h"
#include "../../disjoint_sets/disjoint_sets.h"
#include "../../graphs/tree.h"
#include <algorithm>

#define v1 second.first
#define v2 second.second

vector<Tree*>& algKraskal(Edges & edges, int n)
{
	DisjoinSet set(n);
	vector<Tree*> trees(n);
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
	return std::move(trees);
}
