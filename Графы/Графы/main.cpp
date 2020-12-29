#include <iostream>
#include "Graph.h"
#include <fstream>
#include <float.h>
#include "GraphAlgorithms.h"

using namespace std;
int main(void) {
	/*Test graph*/
	/*Node node1 = Node("Moscow");
	Node node2 = Node("Saints Peterburg");
	Node node3 = Node("Ekaterinburg");
	Node node4 = Node("Irkutsk");
	Graph cities = Graph(true, true);
	cities.addNode(&node1);
	cities.addNode(&node2);
	cities.addNode(&node3);
	cities.addNode(&node4);
	cities.createEdge(&node1, &node2, 3);
	cities.createEdge(&node2, &node3, 10);
	cities.createEdge(&node1, &node4, 30);
	cout << cities << endl;*/
	void connectedParts();
	void secondTask();
	connectedParts();
	secondTask();
	system("pause");
}

//задача на компоненты связности 
void connectedParts() {
	GraphAlgorithms graphAlg = GraphAlgorithms();
	vector<Node*> all_nodes;
	Graph graph = graphAlg.readGraph("TestGraph.txt", all_nodes, false, false);
	vector<bool> visited(graph.getNodes().size());
	graphAlg.depthSearch(*graph.getNodes().at(0), visited, *graph.getNodes().at(0), graph);
	ofstream out;
	out.setf(ios::boolalpha);
	out.open("out/outputFirstTask.txt");
	if (!out.is_open()) {
		cout << "Oops! Error occurred while writing to the file!";
		return;
	}
	for (int i = 0; i < visited.size(); i++) {
		out << "Node: " << graph.getNodes().at(i)->getName() << " is visited: " << visited.at(i) << endl;
	}
	for (int i = 0; i < all_nodes.size(); i++) {
		delete all_nodes.at(i);
	}
	all_nodes.clear();
}

// задача на поиск кратчайшего пути
void secondTask() {
	vector<Node*> all_nodes;
	GraphAlgorithms graphAlg = GraphAlgorithms();
	Graph graph = graphAlg.readGraph("dijkstra.txt", all_nodes, true, true);
	vector<double> roads(graph.getNodes().size(), DBL_MAX);
	roads[0] = 0; // ставим растояние до старотовой вершины равным нулю, в нашем случае старт - вершина № 1, так что и обнуляем первую ячейку
	vector<bool> visited(graph.getNodes().size(), false);
	int target_index = -1;
	for (int i = 0; i < graph.getNodes().size(); i++) {
		if (graph.getNodes().at(i)->getName() == "9") { 
			target_index = i; 
			break;
		}
	}
	double result = graphAlg.Dijkstra(*graph.getNodes().at(0), *graph.getNodes().at(target_index), graph, roads, visited);
	ofstream out;
	out.open("out/dijkstraOutput.txt");
	if (!out.is_open()) {
		cout << "Oops! Error occurred while writing to the file!";
		return;
	}
	out << "The min weight from node" << graph.getNodes().at(0)->getName() << " to " << graph.getNodes().at(target_index)->getName() << " is " << result;
}
