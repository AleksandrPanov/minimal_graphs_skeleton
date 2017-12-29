#include "disjont_sets_array.h"
#include <algorithm>
using std::vector;

int DisjointSetArray::getSize()
{
	return ar.size();
}

DisjointSetArray::DisjointSetArray(int size)
{
	ar = vector<int>(size);
	for (int i = 0; i < size; i++)
		make_set(i);
}

void DisjointSetArray::make_set(int v)
{
	ar[v] = v;
	numSet++;
}

int DisjointSetArray::find_set(int v)
{
	return ar[v];
}

bool DisjointSetArray::union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a == b) return false;
	numSet--;
	int c = std::min(a, b);
	for (int i = 0; i < ar.size(); i++)
	{
		if (ar[i] == a || ar[i] == b)
		{
			ar[i] = c;
		}
	}
	return true;
}