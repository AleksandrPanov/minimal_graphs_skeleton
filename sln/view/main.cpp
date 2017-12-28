#include "../graphs/graph.h"
#include "../algs/algs/alg_boroute.h"
#include "../algs/algs/alg_kraskal.h"
#include "../algs/algs/alg_prima.h"
#include "../algs/algs/connected_component.h"

#include <vector>
#include <iostream>
#include <string>
using std::vector;
using std::cout;
using std::cin;
using std::string;
int main()
{
	string menu = "1 start all algorithms\n2 start Kruskal's algoritm\n";
	menu +="3 start Prim's algoritm\n4 start Boroute's algoritm\n5 set graph\n0 exit\n";
	string choise;
	int numV = 0, numE = 0, minW = 1, maxW = 1000;
	vector<EdgesWeight> graph;
	while (1)
	{
		if (numV != 0)
		{
			cout << "number of vertices "<< numV << " number of edges "<< numE << '\n';
		}
		cout << menu;
		cin >> choise;
		if (choise == "0") break;
		else if (choise == "1")
		{
			double start = 0;
			cout << "running Kruskal's algoritm\n";
			for (auto& comp : graph)
			{
				algKraskal(comp, numV, TypeDisjointSet::tree_full_optimization);
			}
			cout << "final Kruskal's algoritm\n";
		    
			cout << "running Prim's algoritm\n";
			for (auto comp : graph)
			{
				auto adjacencyMatrix = Graph::getAdjacencyMatrixFromEdges(comp, numV);
				algPrima(adjacencyMatrix, numV);
			}
			cout << "final Prim's algoritm\n";

			cout << "running Boroute's algoritm\n";
			for (auto& comp : graph)
			{
				algBoroute(comp, numV);
			}
			cout << "final Boroute's algoritm\n";
			cin >> choise;
		}
		else if (choise == "5")
		{
			cout << "print number of vertices:\n";
			cin >> numV;
			cout << "print type of graph:\n1 tight graph m = n^2/4 \n2 tight graph m = n^2/log(n) \n";
			cout<<"3 sparse graph m = 2n \n4 sparse graph m = 5n \n";
			cin >> choise;
			if (choise == "1")
			{
				numE = (numV*numV) / 4;
			}
			else if (choise == "2")
			{
				numE = (numV*numV) / log(numV);
			}
			else if (choise == "3")
			{
				numE = 2 * numV;
			}
			else if (choise == "4")
			{
				numE = 5 * numV;
			}
			else
			{
				numV = 0;
				continue;
			}
			EdgesWeight tmpGraph;
			tmpGraph = Graph::getRandomGraph(numV, numE, minW, maxW);
			graph = getConnectedComponent(tmpGraph, numV);
		}
		system("cls");
	}
	return 0;
}