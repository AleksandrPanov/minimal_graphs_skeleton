#include "tree.h"

Tree::Tree()
{
}

Tree::Tree(int v)
{
	n = 1;
	head.v = v;
}

void Tree::unionTrees(Tree & tree)
{
	head.child.push_back(&tree.head);
	tree.head.parent = &head;
	n += tree.n;
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
