#include "tree.h"
#include <queue>
using std::queue;
using std::vector;
using std::pair;
typedef std::pair<int, int> Edge;
typedef std::pair<int, std::pair<int, int>> EdgeWeight;

void Tree::unionRoots(int v1, int v2, int w)
{
	nodes[v2].parent = v1;
	nodes[v2].rightBrother = nodes[v1].leftChild;
	nodes[v1].leftChild = v2;
	nodes[v2].weight = w;
	if (root == v2) root = v1;
}

EdgesWeight Tree::getEdges()
{
	EdgesWeight edges(n-1);
	queue<int> q;
	q.push(root);
	int i = 0;
	while (!q.empty())
	{
		int v = q.front(), child = nodes[v].leftChild, w;
		while (child != -1)
		{
			w = nodes[child].weight;
			edges[i++] = EdgeWeight(w, Edge(v, child));
			q.push(child);
			child = nodes[child].rightBrother;
		}
		q.pop();
	}
	return edges;
}

