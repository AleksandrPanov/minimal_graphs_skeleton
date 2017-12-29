#include "../graphs/graph.h"
#include "../algs/algs/alg_boroute.h"
#include "../algs/algs/alg_kraskal.h"
#include "../algs/algs/alg_prima.h"
#include "../algs/algs/connected_component.h"

#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
using std::vector;
using std::cout;
using std::cin;
using std::string;
int main()
{
	string menu = "1 start all algorithms\n2 start Kruskal's algoritm\n";
	menu += "3 start Prim's algoritm\n4 start Boroute's algoritm\n5 set graph\n";
	menu += "6 print graph\n0 exit\n";
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
			EdgesWeight result;
			double start_time, end_time, finish_time = 0;
			cout << "number of connected components = " << graph.size()<<"\n";
			cout << "running Boroute's algoritm\n";
			start_time = clock();
			for (int i = 0; i < graph.size(); i++)
			{
				result = algBoroute(graph[i], numV);
			}
			end_time = clock();
			cout << "final Boroute's algoritm, time = " << (end_time - start_time) / CLOCKS_PER_SEC <<" , weight = " << Graph::findWeight(result) << "\n";

			cout << "running Prim's algoritm\n";
			start_time = clock();
			for (auto comp : graph)
			{
				auto adjacencyMatrix = Graph::getAdjacencyMatrixFromEdges(comp, numV);
				start_time = clock();
				result = algPrima(adjacencyMatrix, numV);
				end_time = clock();
				finish_time += (end_time - start_time);
			}
			end_time = clock();
			cout << "final Prim's algoritm, time = " << finish_time / CLOCKS_PER_SEC << " , weight = " << Graph::findWeight(result) << "\n";

			cout << "running Kruskal's algoritm\n";
			start_time = clock();
			for (auto& comp : graph)
			{
				result = algKraskal(comp, numV, TypeDisjointSet::tree_full_optimization);
			}
			end_time = clock();
			cout << "final Kruskal's algoritm, time = " << (end_time - start_time) / CLOCKS_PER_SEC << " , weight = " << Graph::findWeight(result) <<  "\n";

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
				numE = std::min(numV*numV / 4, numV*(numV - 1) / 2);
			}
			else if (choise == "2")
			{
				numE = std::min( (int)(numV*numV / log(numV)), numV*(numV - 1) / 2);
			}
			else if (choise == "3")
			{
				numE = std::min(2 * numV, numV*(numV-1)/2);
			}
			else if (choise == "4")
			{
				numE = std::min(5 * numV, numV*(numV - 1) / 2);
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
		else if (choise == "6")
		{
			for (auto& comp : graph)
			{
				Graph::printEdges(cout, comp);
				cout << '\n';
			}
			cin >> choise;
		}
		system("cls");
	}
	return 0;
}