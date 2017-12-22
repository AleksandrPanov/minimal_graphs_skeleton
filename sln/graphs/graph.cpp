#include "graph.h"
#include <fstream>
using std::vector;
const int INF = 1000000000;
int Graph::getSize() const
{
	return n;
}

vector<vector<int>> Graph::getAdjacencyMatrixFromEdges(EdgesWeight & edgesWeight, int n)
{
	vector<vector<int>> vv(n);
	for (int i = 0; i < n; i++)
		vv[i] = vector<int>(n, INF);
	for (auto &edge : edgesWeight)
	{
		vv[edge.second.first][edge.second.second] = vv[edge.second.second][edge.second.first] = edge.first;
	}
	return vv;
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

int Graph::findWeight(EdgesWeight & edges)
{
	int w = 0;
	for (auto &edge : edges)
	{
		w += edge.first;
	}
	return w;
}

