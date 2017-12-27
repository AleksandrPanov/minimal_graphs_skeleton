#pragma once
#include <vector>
typedef std::vector<std::pair<int, std::pair<int, int>>> EdgesWeight;

std::vector<EdgesWeight> getConnectedComponent(const EdgesWeight &edges, int n);
void bfs(int v, std::vector<bool> &was, std::vector<std::vector<std::pair<int, int>>> &adjacencyList, 
	std::vector<EdgesWeight> &vecComponents);
void setAdjacencyList(std::vector<std::vector<std::pair<int, int>>> &adjacencyList,const EdgesWeight &edges, int n);