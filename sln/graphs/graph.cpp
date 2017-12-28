#include "graph.h"
#include <random>
#include <fstream>
using std::vector;
using std::pair;
const int INF = 1000000000;
typedef pair<int, pair<int, int>> EdgeWeight;
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

EdgesWeight Graph::getRandomGraph(int size, int numEdges, int minWeight, int maxWeight)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, size*size);
	std::uniform_int_distribution<> dis_weight(minWeight, maxWeight);

	EdgesWeight randomGraph;

	EdgesWeight edgesStore;
	EdgeWeight tmp;
	for (auto n = 0; n < size; n++)
	{
		for (auto m = n + 1; m < size; m++)
		{
			tmp.first = dis_weight(gen);
			tmp.second.first = n;
			tmp.second.second = m;
			edgesStore.emplace_back(tmp);
		}
	}
	int position;
	for (auto i = 0; i < numEdges; i++)
	{
		position = dis(gen) % edgesStore.size();
		randomGraph.emplace_back(edgesStore[position]);
		std::swap(edgesStore[position], edgesStore[edgesStore.size() - 1]);
		edgesStore.pop_back();
	}
	return randomGraph;
}

