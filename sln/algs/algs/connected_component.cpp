#include "connected_component.h"
using std::vector;
using std::pair;
#define v1 second.first
#define v2 second.second
#define w first
typedef pair<int, int> Edge;
typedef pair<int, pair<int, int>> EdgeWeight;
typedef pair<int, int> v2_w;

EdgesWeight bfs(int v,vector<bool> &was, vector<vector<pair<int, int>>> &adjacencyList)
{
	EdgesWeight oneComponet;
	was[v] = true;
	vector<int> vers;
	vers.push_back(v);
	int cur = 0;
	while(cur < vers.size())
	{
		int v = vers[cur++];
		for (v2_w &to : adjacencyList[v])
		{
			if (!was[to.first])
			{
				was[to.first] = true;
				vers.push_back(to.first);
				oneComponet.push_back(EdgeWeight(to.second, Edge(v, to.first)));
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
		adjacencyList[edge.v1].push_back(v2_w(edge.v2, edge.w));
		adjacencyList[edge.v2].push_back(v2_w(edge.v1, edge.w));
	}
}
vector<EdgesWeight> getConnectedComponent(const EdgesWeight &edges, int n)
{
	vector<EdgesWeight> vecComponents;
	vector<vector<pair<int, int>>> adjacencyList;
	setAdjacencyList(adjacencyList, edges, n);
	vector<bool> was(n, false);
	for (int i = 0; i < n; i++)
	{
		if (!was[i])
		{
			auto comp = bfs(i, was, adjacencyList);
			vecComponents.push_back(comp);
		}
	}
	vecComponents.shrink_to_fit();
	return vecComponents;
}
