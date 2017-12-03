#pragma once
#include <vector>
using namespace std;
class Graph
{
protected:
	int n;// ����� ������
	std::vector<std::pair<int, int>>* adjacencyList;// ������ ���������, ����� ������� �������/���*/
public:
	Graph();
	Graph(const Graph& g);

	int getSize() const;
	std::vector<std::pair<int, std::pair<int, int>>> getSortedEdges();// ���/�������1/�������2
	void SetGraph(int n, std::vector<std::pair<int, int>>* adjList);

	~Graph();
};