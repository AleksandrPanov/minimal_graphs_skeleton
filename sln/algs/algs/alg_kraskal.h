#pragma once
#include <vector>
class Tree;
typedef std::vector<std::pair<int, std::pair<int, int>>> EdgesWeight;
void algKraskal(EdgesWeight & edges, int n, std::vector<Tree*> &trees);