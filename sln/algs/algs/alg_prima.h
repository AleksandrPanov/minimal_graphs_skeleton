#pragma once
#include <vector>
typedef std::vector<std::pair<int, std::pair<int, int>>> EdgesWeight;
EdgesWeight algPrima(std::vector<std::vector<int>> &g, int n);

