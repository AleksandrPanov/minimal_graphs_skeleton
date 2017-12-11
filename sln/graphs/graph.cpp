#include "graph.h"
#include <fstream>

int Graph::getSize() const
{
	return n;
}

void Graph::printEdges(std::ofstream & of, Edges& edges)
{
	for (auto &edge : edges)
	{
		of << edge.first << ' ' << edge.second << '\n';
	}
}

void Graph::printEdges(std::ostream & os, Edges& edges)
{
	for (auto &edge : edges)
	{
		os << edge.first << ' ' << edge.second << '\n';
	}
}
