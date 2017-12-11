#pragma once
#include <vector>

typedef std::vector<std::pair<int, int>> Edges;
typedef std::vector<std::pair<int, std::pair<int, int>>> EdgesWeight;

class Graph
{
protected:
	int n = 0;
public:
	int getSize() const;
	virtual Edges getEdges() { return std::move(Edges()); }

	static void printEdges(std::ofstream &of, Edges& edges);
	
	static void printEdges(std::ostream &os, Edges& edges);
};