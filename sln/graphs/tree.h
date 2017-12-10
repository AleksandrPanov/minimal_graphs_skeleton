#pragma once
#include "graph.h" 
struct Node
{
	int v;
	Node *parent = 0;
	std::vector<Node *> child;
};
class Tree : public Graph
{
protected:
	Node head;
public:
	Tree();
	void deleteNodes(Node *node);
	~Tree();
};