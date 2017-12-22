#include "disjoint_sets.h"
#include <algorithm>
#include <numeric>
using std::vector;
using std::swap;
DisjointSet::DisjointSet(int size)
{
	tree = vector<node>(size);
	for (int i = 0; i < size; i++)
		make_set(i);
}

void DisjointSet::make_set(int v)
{
	numSet++;
	tree[v].parent = v;
	tree[v].rank = 0;
}

int DisjointSet::find_set(int v)
{
	if (v == tree[v].parent)
		return v;
	return tree[v].parent = find_set(tree[v].parent);
}

void DisjointSet::union_sets(int a, int b)
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
