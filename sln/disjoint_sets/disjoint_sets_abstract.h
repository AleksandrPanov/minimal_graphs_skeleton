#pragma once
struct node
{
	int rank;
	int parent;
	node() {}
};
class AbstractDisjointSet
{
protected:
	int numSet = 0;
public:
	AbstractDisjointSet() {}
	AbstractDisjointSet(int n) {}
	virtual int getSize() = 0;
	int getNumSet() { return numSet; };
	virtual void make_set(int v) = 0;
	virtual int find_set(int v) = 0;
	virtual bool union_sets(int a, int b) = 0;
};