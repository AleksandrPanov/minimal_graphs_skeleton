#include "alg_prima.h"
using std::vector;
typedef std::pair<int, int> Edge;
typedef std::pair<int, std::pair<int, int>> EdgeWeight;

const int INF = 1000000000;
int getMinV(int n, vector<bool> &used, int *min_edges)
{
	int v = -1;
	for (int j = 0; j < n; ++j)
		if (!used[j] && (v == -1 || min_edges[j] < min_edges[v]))
			v = j;
	return v;
}
EdgesWeight algPrima(vector<vector<int>> &g, int n)
{
	EdgesWeight resultEdges;
	resultEdges.reserve(n - 1);
	vector<bool> used(n);
	vector<int> min_edges(n, INF), sel_edges(n, -1);
	min_edges[0] = 0;
	for (int i = 0; i < n; ++i) 
	{
		int v = getMinV(n, used, &min_edges[0]);
		if (min_edges[v] == INF) 
		{
			return resultEdges;
		}

		used[v] = true;
		//добавяем мин ребро в ответ, если такое ребро имеется
		if (sel_edges[v] != -1)
		{
			resultEdges.emplace_back(EdgeWeight(g[v][sel_edges[v]], Edge(v, sel_edges[v])));
		}
		//обновляем минимальные ребра
		for (int to = 0; to < n; ++to)
			if (g[v][to] < min_edges[to]) 
			{
				min_edges[to] = g[v][to];
				sel_edges[to] = v;
			}
	}
	return resultEdges;
}
