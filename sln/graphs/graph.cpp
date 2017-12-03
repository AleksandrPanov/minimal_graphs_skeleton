#include "graph.h"
Graph::Graph() {}

Graph::Graph(const Graph & g)
{
	delete[] adjacencyList;
	n = g.getSize();
	for (int i = 0; i < n; i++)
		adjacencyList[i] = g.adjacencyList[i];
}



int Graph::getSize() const
{
	return n;
}

std::vector<std::pair<int, std::pair<int, int>>> Graph::getSortedEdges()
{
	std::vector<std::pair<int, std::pair<int, int>>> edges;
	for (int i = 0; i < n; i++)
	{
		for (auto &v : adjacencyList[i])
		{
			auto edge = std::pair<int, std::pair<int, int>>(v.second, std::pair<int,int>(i, v.first));

		}
	}
	return std::vector<std::pair<int, std::pair<int, int>>>();
}

void Graph::SetGraph(int n, std::vector<std::pair<int, int>>* adjList)
{
	delete[] adjacencyList;
	this->n = n;
	for (int i = 0; i < n; i++)
		adjacencyList[i] = adjList[i];
}

Graph::~Graph()
{
	delete[] adjacencyList;
}