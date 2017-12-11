#include "tree.h"
using std::vector;
using std::pair;
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

void Tree::deleteNodes(Node *node)
{
	//delete node->parent;
	if (node != 0)
	{
		for (int i = 0; i < node->child.size(); i++)
		{
			if (node->child[i] != 0)
			{
				deleteNodes(node->child[i]);
				delete  node->child[i];
				node->child[i] = 0;
			}
		}
		node = 0;
	}
}

void pushEdges(Node *node, vector<pair<int, int>>& edges)
{
	for (int i = 0; i < node->child.size(); i++)
	{
		edges.push_back(pair<int, int>(node->v, node->child[i]->v));
		pushEdges(node->child[i], edges);
	}
}

vector<pair<int, int>> Tree::getEdges()
{
	vector<pair<int, int>> edges;
	pushEdges(&head, edges);
	return std::move(edges);
}

Tree::~Tree()
{
	//deleteNodes(&head);
}
