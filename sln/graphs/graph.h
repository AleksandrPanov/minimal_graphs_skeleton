#pragma once
#include <vector>
typedef std::vector<std::pair<int, std::pair<int, int>>> EdgesWeight;

class Graph
{
protected:
	int n = 0;
public:
	int getSize() const;
	virtual EdgesWeight getEdges() { return EdgesWeight(); }
	static std::vector<std::vector<int>> getAdjacencyMatrixFromEdges(EdgesWeight &edgesWeight, int n);
	static void printEdges(std::ofstream &of, EdgesWeight& edges);
	static void printEdges(std::ostream &os, EdgesWeight& edges);
	static int findWeight(EdgesWeight &edges);
	static EdgesWeight getRandomGraph(int size, int numEdges, int minWeight, int maxWeight);
};