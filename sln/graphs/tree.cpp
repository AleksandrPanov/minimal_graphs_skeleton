#include "tree.h"

Tree::Tree()
{
}

void Tree::deleteNodes(Node * node)
{
	//delete node->parent;
	for (int i = 0; i < node->child.size(); i++)
	{
		if (node->child[i] != 0)
		{
			deleteNodes(node->child[i]);
			delete  node->child[i];
			node->child[i] = 0;
		}
	}
}

Tree::~Tree()
{
	deleteNodes(&head);
}
