#pragma once
#include "graph.h" 
struct Node
{
	int v = -1;
	Node *parent = 0;
	std::vector<Node *> child;
};
class Tree : public Graph
{
protected:
	Node head;
public:
	Tree();
	Tree(int v);
	void unionTrees(Tree &tree);
	void deleteNodes(Node *node);
	Edges getEdges() override;
	~Tree();
};