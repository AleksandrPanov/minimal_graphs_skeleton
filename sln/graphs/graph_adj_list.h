#pragma once
#include "graph.h"
class GraphAdjList : public Graph
{
protected:
	std::vector<int>* adjacencyList;//������ ���������, ����� ������� �������
public:
	GraphAdjList();
	GraphAdjList(const GraphAdjList& g);

	std::vector<std::pair<int, std::pair<int, int>>> getSortedEdges();//���/�������1/�������2
	void SetGraph(int n, std::vector<int>* adjList);

	~GraphAdjList();
};