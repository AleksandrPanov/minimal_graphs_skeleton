#pragma once
#include <vector>
enum TypeDisjointSet
{
	array, tree_rank, tree_full_optimization
};
typedef std::vector<std::pair<int, std::pair<int, int>>> EdgesWeight;
EdgesWeight algKraskal(EdgesWeight &edges, int n, TypeDisjointSet choise);