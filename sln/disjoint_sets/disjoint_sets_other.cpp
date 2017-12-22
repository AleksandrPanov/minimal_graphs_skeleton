#include "disjoint_sets_other.h"
#include "disjoint_sets.h"
#include <algorithm>
using std::vector;
DisjointSetArray::DisjointSetArray(int size)
{
	ar = vector<int>(size);
	for (int i = 0; i < size; i++)
		make_set(i);
}

void DisjointSetArray::make_set(int v)
{
	ar[v] = v;
}

int DisjointSetArray::find_set(int v)
{
	return ar[v];
}

void DisjointSetArray::union_sets(int a, int b)
{
	int c = std::min(a, b);
	for (int i = 0; i < ar.size(); i++)
	{
		if (ar[i] == a || ar[i] == b)
			ar[i] = c;
	}
}

DisjointSetRank::DisjointSetRank(int size)
{
	tree = vector<node>(size);
	for (int i = 0; i < size; i++)
		make_set(i);
}

void DisjointSetRank::make_set(int v)
{
	numSet++;
	tree[v].parent = v;
	tree[v].rank = 0;
}

int DisjointSetRank::find_set(int v)
{
	if (v == tree[v].parent)
		return v;
	return (find_set(tree[v].parent));
}

void DisjointSetRank::union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
	{
		numSet--;
		if (tree[a].rank < tree[b].rank)
			std::swap(a, b);
		tree[b].parent = a;
		if (tree[a].rank == tree[b].rank)
			++tree[a].rank;
	}
}
