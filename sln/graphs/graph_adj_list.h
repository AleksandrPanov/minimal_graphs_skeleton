#pragma once
#include "graph.h"
class GraphAdjList : public Graph
{
protected:
	std::vector<int>* adjacencyList;//список смежности, номер смежной вершины
	std::vector<std::vector<int>> weight;
public:
	GraphAdjList();
	GraphAdjList(const GraphAdjList& g);

	std::vector<std::pair<int, std::pair<int, int>>> getSortedEdges();//вес/вершина1/вершина2
	void SetGraph(int n, std::vector<int>* adjList, std::vector<std::vector<int>> &w);

	~GraphAdjList();
};