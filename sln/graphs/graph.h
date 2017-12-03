#pragma once
#include <vector>
using namespace std;
class Graph
{
protected:
	int n;// число вершин
	std::vector<std::pair<int, int>>* adjacencyList;// список смежности, номер смежной вершины/вес*/
public:
	Graph();
	Graph(const Graph& g);

	int getSize() const;
	std::vector<std::pair<int, std::pair<int, int>>> getSortedEdges();// вес/вершина1/вершина2
	void SetGraph(int n, std::vector<std::pair<int, int>>* adjList);

	~Graph();
};