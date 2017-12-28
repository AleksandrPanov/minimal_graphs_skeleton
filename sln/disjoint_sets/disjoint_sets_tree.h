#pragma once
#include <vector>
#include "disjoint_sets_abstract.h"
class DisjointSetRank : public AbstractDisjointSet
{
private:
	std::vector <node> tree;
public:
	DisjointSetRank() {}
	DisjointSetRank(int size);
	int getSize() { return tree.size(); }
	void make_set(int v);
	int find_set(int v);
	void union_sets(int a, int b);
};
