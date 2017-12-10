#pragma once
#include <vector>
struct node
{
	int rank;
	int parent;
	node(){}
};
class DisjoinSet
{
private:
	std::vector <node> tree;
	int numSet = 0;
public:
	DisjoinSet(){}
	DisjoinSet(int size);
	int getSize() { return tree.size(); }
	int getNumSet() { return numSet; }
	void make_set(int v);

	int find_set(int v);

	void union_sets(int a, int b);
	
};