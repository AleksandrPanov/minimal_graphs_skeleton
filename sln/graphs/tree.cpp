#include "tree.h"
#include <queue>
using std::queue;
using std::vector;
using std::pair;

void Tree::unionRoots(int v1, int v2)
{
	nodes[v2].parent = v1;
	nodes[v2].rightBrother = nodes[v1].leftChild;
	nodes[v1].leftChild = v2;
	if (root == v2) root = v1;
}

Edges Tree::getEdges()
{
	Edges edges(n-1);
	queue<int> q;
	q.push(root);
	int i = 0;
	while (!q.empty())
	{
		int v = q.front(), child = nodes[v].leftChild;
		while (child != -1)
		{
			edges[i++] = Edge(v, child);
			q.push(child);
			child = nodes[child].rightBrother;
		}
		q.pop();
	}
	return edges;
}
