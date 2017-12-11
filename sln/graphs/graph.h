#pragma once
#include <vector>
class Graph
{
protected:
	int n = 0;
public:
	int getSize() const;
	//virtual std::vector<std::pair<int, std::pair<int, int>>> getEdges() = 0;//вес/вершина1/вершина2
	virtual std::vector<std::pair<int, int>> getEdges() { return std::move(std::vector<std::pair<int, int>>()); }
	//virtual void SetGraph(int n, std::vector<std::pair<int, int>>* adjList) = 0;
	static void printEdges(std::ofstream &of, std::vector<std::pair<int, int>>& edges);
	static void printEdges(std::ostream &os, std::vector<std::pair<int, int>>& edges);
};