#pragma once
#include <vector>
using namespace std;
class Graph
{
protected:
	int n;
public:
	int getSize() const;
	virtual std::vector<std::pair<int, std::pair<int, int>>> getSortedEdges() = 0;//���/�������1/�������2
	virtual void SetGraph(int n, std::vector<std::pair<int, int>>* adjList) = 0;
};