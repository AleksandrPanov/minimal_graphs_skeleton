#pragma once
#include <vector>
#include "disjoint_sets_abstract.h"
class DisjointSet : public AbstractDisjointSet
{
private:
	std::vector <node> tree;
public:
	DisjointSet(){}
	DisjointSet(int size);
	int getSize() { return tree.size(); }
	void make_set(int v);
	int find_set(int v);
	bool union_sets(int a, int b);	
};