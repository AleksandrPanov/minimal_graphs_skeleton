#include "disjoint_sets.h"
#include <algorithm>
#include <numeric>
using std::vector;
using std::swap;
DisjoinSet::DisjoinSet(int size)
{
	tree = vector<node>(size);
	for (int i = 0; i < size; i++)
		make_set(i);
}

void DisjoinSet::make_set(int v)
{
	numSet++;
	tree[v].parent = v;
	tree[v].rank = 0;
}

int DisjoinSet::find_set(int v)
{
	if (v == tree[v].parent)
		return v;
	return tree[v].parent = find_set(tree[v].parent);
}

void DisjoinSet::union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b) 
	{
		numSet--;
		if (tree[a].rank < tree[b].rank)
			swap(a, b);
		tree[b].parent = a;
		if (tree[a].rank == tree[b].rank)
			++tree[a].rank;
	}
}
