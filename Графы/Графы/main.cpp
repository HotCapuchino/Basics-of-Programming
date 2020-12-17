#include <iostream>
#include "Graph.h"
#include <fstream>
#include <float.h>

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
	/*connectedParts();*/
	secondTask();
	system("pause");
}

//задача на компоненты св€зности 
void connectedParts() {
	void depthSearch(Node& start_node, vector<bool>& visited, Node& previous_node, Graph& graph);
	vector<Node*> all_nodes;
	Graph readGraph(string file_name, vector<Node*>& all_nodes, bool directed, bool measured);
	Graph graph = readGraph("TestGraph.txt", all_nodes, false, false);
	vector<bool> visited(graph.getNodes().size());
	depthSearch(*graph.getNodes().at(0), visited, *graph.getNodes().at(0), graph);
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

// поиск в глубину
void depthSearch(Node& start_node, vector<bool>& visited, Node& previous_node, Graph& graph) {
	for (int i = 0; i < graph.getNodes().size(); i++) {
		if (graph.getNodes().at(i) == &start_node) {
			visited[i] = true;
			break;
		}
	}
	for (Node* neighbour : start_node.getNeighbours()) {
		for (int i = 0; i < graph.getNodes().size(); i++) {
			if (graph.getNodes().at(i) == neighbour && !visited.at(i)) {
				previous_node = start_node;
				depthSearch(*neighbour, visited, previous_node, graph);
			}
		}
	}
}

// задача на поиск кратчайшего пути 
void secondTask() {
	double Dijkstra(Node& start_node, Node& target_node, Graph& graph, vector<double>& roads, vector<bool>& visited);
	Graph readGraph(string file_name, vector<Node*>& all_nodes, bool directed, bool measured);
	vector<Node*> all_nodes;
	Graph graph = readGraph("dijkstra.txt", all_nodes, true, true);
	vector<double> roads(graph.getNodes().size(), DBL_MAX);
	/*for (int i = 0; i < graph.getNodes().size(); i++) {
		cout << graph.getNodes().at(i)->getName() << endl;
	} */
	roads[0] = 0; // ставим расто€ние до старотовой вершины равным нулю, в нашем случае старт - вершина є 1, так что и обнул€ем первую €чейку
	vector<bool> visited(graph.getNodes().size(), false);
	int target_index = -1;
	for (int i = 0; i < graph.getNodes().size(); i++) {
		if (graph.getNodes().at(i)->getName() == "9") { 
			target_index = i; 
			break;
		}
	}
	double result = Dijkstra(*graph.getNodes().at(0), *graph.getNodes().at(target_index), graph, roads, visited);
	ofstream out;
	out.open("out/dijkstraOutput.txt");
	if (!out.is_open()) {
		cout << "Oops! Error occurred while writing to the file!";
		return;
	}
	out << "The min weight from node" << graph.getNodes().at(0)->getName() << " to " << graph.getNodes().at(target_index)->getName() << " is " << result;
}

// алгоритм ƒейкстры
double Dijkstra(Node& start_node, Node& target_node, Graph& graph, vector<double>& roads, vector<bool>& visited) {
	Node* current_node = &start_node;
	double min_road = DBL_MAX;
	bool everything_is_visited = false;
	int current_node_index = -1;
	int neighbour_index = -1;
	while (!everything_is_visited) {
		everything_is_visited = true;
		for (int i = 0; i < roads.size(); i++) {
			if (roads.at(i) < min_road && !visited.at(i)) {
				current_node = graph.getNodes().at(i);
				current_node_index = i;
				break;
			}
		}
		Edge* buf_edge = nullptr;
		for (int i = 0; i < current_node->getNeighbours().size(); i++) {
			buf_edge = graph.getEdge(current_node, current_node->getNeighbours().at(i));
			neighbour_index = graph.getNodeIndex(current_node->getNeighbours().at(i)); // getting apropriate Node index to provide correlation: roads[i] = graph.getNodes[i] = visited[i]
			if (buf_edge != nullptr && buf_edge->getWeight() + roads.at(current_node_index) < roads.at(neighbour_index)) {
				roads.at(neighbour_index) = buf_edge->getWeight() + roads.at(current_node_index);
			}
		}
		for (int i = 0; i < visited.size(); i++) {
			if (!visited.at(i)) {
				everything_is_visited = false;
				break;
			}
		}
		visited.at(graph.getNodeIndex(current_node)) = true;
	}
	/*current_node = &start_node;
	current_node_index = graph.getNodeIndex(current_node);
	string route;
	route.append(current_node->getName() + " ");
	while (current_node != &target_node) {
		route += " -> ";
		min_road = DBL_MAX;
		Node* min_node = nullptr;
		for (int i = 0; i < current_node->getNeighbours().size(); i++) {
			neighbour_index = graph.getNodeIndex(current_node->getNeighbours().at(i));
			if (roads.at(neighbour_index) < min_road) { 
				min_node = current_node->getNeighbours().at(i);
				min_road = roads.at(neighbour_index);
			}
		}
		route.append(min_node->getName());
		current_node = min_node;
	}
	route.append(" -> " + target_node.getName());
	route.append("; Weight of the root is: " + to_string(roads.at(graph.getNodeIndex(&target_node))));
	return route;*/
	return roads.at(graph.getNodeIndex(&target_node));
}

// чтение графа
Graph readGraph(string file_name, vector<Node*>& all_nodes, bool directed, bool measured) {
	Graph graph = Graph(directed, measured);
	fstream in;
	in.open("res/" + file_name);
	if (!in.is_open()) {
		cout << "Oops! Error occurred wile opening the file!";
		return graph;
	}
	string s1 = "";
	int src = 0;
	int target = 0;
	double weight = 0.0;
	bool start_found = false;
	bool end_found = false;
	Node* start = nullptr;
	Node* end = nullptr;
	while (getline(in, s1)) {
		start_found = false;
		end_found = false;
		char* buffer = new char[s1.size()];
		copy(s1.begin(), s1.end(), buffer);
		if (measured) {
			sscanf_s(buffer, "%d %d %lf", &src, &target, &weight);
		}
		else {
			sscanf_s(buffer, "%d %d", &src, &target);
		}
		if (src == target) continue;
		for (int i = 0; i < all_nodes.size(); i++) {
			if (all_nodes.at(i)->getName() == to_string(src)) {
				start = all_nodes.at(i);
				start_found = true;
				break;
			}
		}
		for (int i = 0; i < all_nodes.size(); i++) {
			if (all_nodes.at(i)->getName() == to_string(target)) {
				end = all_nodes.at(i);
				end_found = true;
				break;
			}
		}
		if (!start_found) {
			start = new Node(to_string(src));
			all_nodes.push_back(start);
		}
		if (!end_found) {
			end = new Node(to_string(target));
			all_nodes.push_back(end);
		} 
		graph.addNode(start);
		graph.addNode(end);
		if (measured) {
			graph.createEdge(start, end, weight);
		}
		else {
			graph.createEdge(start, end);
		}
	}
	return graph;
}