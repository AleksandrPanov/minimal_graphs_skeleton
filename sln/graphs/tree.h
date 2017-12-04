#pragma once
#include "graph.h" 
struct Node
{
	int v;
	Node *parent;
	std::vector<Node *> child;

	~Node()	{}
};
class Tree : public Graph
{
protected:
	Node node;
public:
	Tree();
	~Tree();
};