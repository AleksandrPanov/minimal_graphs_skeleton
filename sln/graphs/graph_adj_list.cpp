#include "graph_adj_list.h"
#include <algorithm>
using std::vector;
using std::pair;
GraphAdjList::GraphAdjList(){}
GraphAdjList::GraphAdjList(const GraphAdjList & g)
{
	delete[] adjacencyList;
	n = g.getSize();
	for (int i = 0; i < n; i++)
		adjacencyList[i] = g.adjacencyList[i];
	weight = g.weight;
}

std::vector<pair<int, pair<int, int>>> GraphAdjList::getSortedEdges()
{
	std::vector<pair<int, std::pair<int, int>>> edges;
	for (int i = 0; i < n; i++)
	{
		for (auto &v : adjacencyList[i])
		{
			auto edge = pair<int, pair<int, int>>(weight[i][v], pair<int, int>(i, v));
		}
	}
	std::sort(edges.begin(), edges.end());
	return edges;
}

void GraphAdjList::SetGraph(int n, vector<int>* adjList, vector<vector<int>> &w)
{
	delete[] adjacencyList;
	this->n = n;
	for (int i = 0; i < n; i++)
		adjacencyList[i] = adjList[i];
	weight = w;
}

GraphAdjList::~GraphAdjList()
{
	delete[] adjacencyList;
}

