#pragma once
#include "graph.h"
class GraphAdjList : public Graph
{
protected:
	std::vector<int>* adjacencyList;//список смежности, номер смежной вершины
public:
	GraphAdjList();
	GraphAdjList(const GraphAdjList& g);

	std::vector<std::pair<int, std::pair<int, int>>> getSortedEdges();//вес/вершина1/вершина2
	void SetGraph(int n, std::vector<int>* adjList);

	~GraphAdjList();
};