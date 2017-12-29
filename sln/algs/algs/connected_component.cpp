#include "connected_component.h"
using std::vector;
using std::pair;
#define v1 second.first
#define v2 second.second
#define w first
typedef pair<int, int> Edge;
typedef pair<int, pair<int, int>> EdgeWeight;
typedef pair<int, int> v2_w;

std::vector<int> bfs(int v, Was &was, vector<vector<pair<int, int>>> &adjacencyList)
{
	std::vector<int> oneComponet;
	was[v] = true;
	oneComponet.push_back(v);
	int cur = 0;
	while(cur < oneComponet.size())
	{
		int v = oneComponet[cur++];
		for (v2_w &to : adjacencyList[v])
		{
			if (!was[to.first])
			{
				was[to.first] = true;
				oneComponet.push_back(to.first);
			}
		}
	}
	return oneComponet;
}
void setAdjacencyList(vector<vector<pair<int, int>>> &adjacencyList, const EdgesWeight & edges, int n)
{
	adjacencyList = vector<vector<pair<int, int>>>(n);
	for (auto &edge : edges)
	{
		adjacencyList[edge.v1].emplace_back(v2_w(edge.v2, edge.w));
		adjacencyList[edge.v2].emplace_back(v2_w(edge.v1, edge.w));
	}
}

EdgesWeight getEdgesOneComp(vector<int> &oneComp, vector<vector<pair<int, int>>> &adjacencyList, int n)
{
	EdgesWeight oneEdgesComp;
	vector<vector<bool>> was(n);
	for (int i = 0; i < n; i++)
		was[i] = vector<bool>(n, false);
	for (int ver1:oneComp)
	{
		for (auto ver2 : adjacencyList[ver1])
		{
			if (!was[ver1][ver2.first])
			{
				was[ver1][ver2.first] = true;
				was[ver2.first][ver1] = true;
				oneEdgesComp.emplace_back(EdgeWeight(ver2.second, Edge(ver1, ver2.first)));
			}
		}
	}
	return oneEdgesComp;
}

vector<EdgesWeight> getConnectedComponent(const EdgesWeight &edges, int n)
{
	vector<EdgesWeight> vecComponents;
	vector<vector<pair<int, int>>> adjacencyList;
	setAdjacencyList(adjacencyList, edges, n);
	vector<bool> was(n, false);
	vector <vector<bool>> wasEdge(n);
	for (int i = 0; i < n; i++)
		wasEdge[i] = vector<bool>(n, false);
	for (int i = 0; i < n; i++)
	{
		if (!was[i])
		{
			auto comp = bfs(i, was, adjacencyList);
			auto edgesComp = getEdgesOneComp(comp, adjacencyList, n);
			if (edgesComp.size() != 0)
			{
				vecComponents.emplace_back(edgesComp);
			}
		}
	}
	vecComponents.shrink_to_fit();
	return vecComponents;
}
