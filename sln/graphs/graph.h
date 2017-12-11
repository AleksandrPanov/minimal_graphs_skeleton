#pragma once
#include <vector>
class Graph
{
protected:
	int n = 0;
public:
	int getSize() const;
	//virtual std::vector<std::pair<int, std::pair<int, int>>> getEdges() = 0;//���/�������1/�������2
	virtual std::vector<std::pair<int, int>> getEdges() { return std::move(std::vector<std::pair<int, int>>()); }
	//virtual void SetGraph(int n, std::vector<std::pair<int, int>>* adjList) = 0;
};