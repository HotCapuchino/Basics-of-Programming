#include "GraphAlgorithms.h"



GraphAlgorithms::GraphAlgorithms() {}

void GraphAlgorithms::depthSearch(Node & start_node, vector<bool>& visited, Node & previous_node, Graph & graph) {
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

double GraphAlgorithms::Dijkstra(Node & start_node, Node & target_node, Graph & graph, vector<double>& roads, vector<bool>& visited) {
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
	return roads.at(graph.getNodeIndex(&target_node));
}

Graph GraphAlgorithms::readGraph(string file_name, vector<Node*>& all_nodes, bool directed, bool measured) {
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

GraphAlgorithms::~GraphAlgorithms() {}