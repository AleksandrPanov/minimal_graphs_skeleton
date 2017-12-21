#pragma once
#include <vector>

typedef std::vector<std::pair<int, int>> Edges;
typedef std::vector<std::pair<int, std::pair<int, int>>> EdgesWeight;
typedef std::pair<int, int> Edge;
typedef std::pair<int, std::pair<int, int>> EdgeWeight;

class Graph
{
protected:
	int n = 0;
public:
	int getSize() const;
	virtual EdgesWeight getEdges() { return EdgesWeight(); }

	static void printEdges(std::ofstream &of, EdgesWeight& edges);
	static void printEdges(std::ostream &os, EdgesWeight& edges);
};