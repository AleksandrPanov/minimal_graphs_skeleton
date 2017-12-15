#pragma once
#include "graph.h" 
struct Node
{
	int parent = -1;
	int leftChild = -1;
	int rightBrother = -1;
};
class Tree : public Graph
{
protected:
	int root = 0;
	std::vector<Node> nodes;
public:
	Tree() {};
	Tree(int n)
	{
		this->n = n;
		nodes = std::vector<Node>(n);
	}
	void unionRoots(int v1, int v2);
	int getRoot() const { return root; }
	Node getNode(int i) const { return nodes[i]; }
	Edges getEdges() override;
};