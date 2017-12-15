#pragma once
#include <vector>
class Tree;
typedef std::vector<std::pair<int, std::pair<int, int>>> EdgesWeight;
Tree algKraskal(EdgesWeight &edges, int n);