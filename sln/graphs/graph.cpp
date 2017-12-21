#include "graph.h"
#include <fstream>

int Graph::getSize() const
{
	return n;
}

void Graph::printEdges(std::ofstream & of, EdgesWeight& edges)
{
	for (auto &edge : edges)
	{
		of << edge.second.first << ' ' << edge.second.second << ' '<<edge.first<< '\n';
	}
}

void Graph::printEdges(std::ostream & os, EdgesWeight& edges)
{
	for (auto &edge : edges)
	{
		os << edge.second.first << ' ' << edge.second.second << ' ' << edge.first << '\n';
	}
}

