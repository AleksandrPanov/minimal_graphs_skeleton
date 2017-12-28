#pragma once
#include <vector>
typedef std::vector<std::pair<int, std::pair<int, int>>> EdgesWeight;
typedef std::vector<bool> Was;

std::vector<EdgesWeight> getConnectedComponent(const EdgesWeight &edges, int n);
std::vector<int> bfs(int v, Was &was,  std::vector<std::vector<std::pair<int, int>>> &adjacencyList);
void setAdjacencyList(std::vector<std::vector<std::pair<int, int>>> &adjacencyList,const EdgesWeight &edges, int n);