#include "Graph.h"
#include "Node.h"


Graph::Graph(bool directed, bool measured) {
	this->directed = directed;
	this->measured = measured;
}

Graph::~Graph() {
	nodes_of_the_graph.clear();
}

void Graph::addNode(Node* node) {
	for (int i = 0; i < nodes_of_the_graph.size(); i++) {
		if (nodes_of_the_graph.at(i) == node) {
			nodes_of_the_graph[i] = node;
			return;
		}
	}
	nodes_of_the_graph.push_back(node);
}

void Graph::removeNode(Node* node) {
	if (!nodes_of_the_graph.empty()) {
		for (int i = 0; i < nodes_of_the_graph.size(); i++) {
			if (nodes_of_the_graph.at(i) == node) {
				vector<Node*> deleting_node_neighbours = node->getNeighbours();
				nodes_of_the_graph.erase(nodes_of_the_graph.begin() + i); // deleting exisiting node from the nodes list of the Graph
				// deleting node from all neighbours lists
				for (int j = 0; j < deleting_node_neighbours.size(); j++) {
					deleting_node_neighbours.at(j)->removeNeighbour(node);
				}
				break;
			}
		}
		node->~Node();
	}
}

void Graph::createEdge(Node* start, Node* end, double weight) {
	for (int i = 0; i < edges_of_the_graph.size(); i++){
		if (edges_of_the_graph.at(i)->getStart() == start
			&& edges_of_the_graph.at(i)->getEnd() == end) return;
	}
	Edge* new_edge = new Edge(start, end);
	if (measured) {
		if (weight < 0.0) {
			cout << "Value of the edge cannot be negative!\n";
			return;
		} 
		if (weight == 0) {
			cout << "You have created a measured graph, so please provide a function with 3 args, with its weight as the third arg!\n";
			return;
		}
		new_edge->setWeight(weight);
	}
	if (!directed) {
		end->addNeighbour(start);
	}
	start->addNeighbour(end);
	edges_of_the_graph.push_back(new_edge);
}

void Graph::deleteEdge(Node* start, Node* end) {
	if (!edges_of_the_graph.empty()) {
		for (int i = 0; i < edges_of_the_graph.size(); i++)
		{	
			if (edges_of_the_graph.at(i)->getStart() == start
				&& edges_of_the_graph.at(i)->getEnd() == end) {
				edges_of_the_graph.erase(edges_of_the_graph.begin() + i);
				break;
			}
		}
	}
	if (directed) {
		vector<Node*> neighbours = start->getNeighbours();
		for (int i = 0; i < neighbours.size(); i++) {
			neighbours.at(i)->removeNeighbour(start);
		}
	}
	start->removeNeighbour(end);
}

vector<Node*> Graph::getNodes() {
	return nodes_of_the_graph;
}

vector<Edge*> Graph::getEdges() {
	return edges_of_the_graph;
}

Edge* Graph::getEdge(Node* start, Node* end) {
	for (int i = 0; i < edges_of_the_graph.size(); i++) {
		if (start == edges_of_the_graph.at(i)->getStart()
			&& end == edges_of_the_graph.at(i)->getEnd())
			return edges_of_the_graph.at(i);
	}
	return nullptr;
}

int Graph::getNodeIndex(Node* target_node) {
	for (int i = 0; i < nodes_of_the_graph.size(); i++) {
		if (target_node == nodes_of_the_graph.at(i)) return i;
	}
	return -1;
}

ostream& operator<<(ostream& out, Graph& graph) {
	out << "Graph's nodes:\n" << "---------" << endl;
	for (int i = 0; i < graph.getNodes().size(); i++) {
		out << "#" << i + 1 << ":\n" << *(graph.getNodes().at(i)) << endl;
		out << "---------" << endl;
	}
	out << "Graph's edges:\n" << "---------" << endl;
	for (int i = 0; i < graph.getEdges().size(); i++) {
		out << "#" << i + 1 << ":\n" << *(graph.getEdges().at(i)) << endl;
		out << "---------" << endl;
	}
	return out;
}
