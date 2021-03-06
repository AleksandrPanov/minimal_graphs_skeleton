#pragma once
#include <vector>
#include "disjoint_sets_abstract.h"
class DisjointSetArray : public AbstractDisjointSet
{
private:
	std::vector<int> ar;
public:
	DisjointSetArray() {}
	DisjointSetArray(int size);
	int getSize();
	void make_set(int v);
	int find_set(int v);
	bool union_sets(int a, int b);
};