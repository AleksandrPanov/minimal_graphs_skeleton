#pragma once
#include <vector>
typedef std::vector<std::pair<int, std::pair<int, int>>> EdgesWeight;
EdgesWeight algKraskal(EdgesWeight &edges, int n);