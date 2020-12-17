#pragma once
#include "Node.h"
#include "Edge.h"
#include <vector>
#include <iostream>

using namespace std;
class Graph {
private:
	vector<Node*> nodes_of_the_graph;
	vector<Edge*> edges_of_the_graph;
	bool directed = false;
	bool measured = false;
public:
	Graph(bool directed, bool measured);
	~Graph();
	void addNode(Node* node);
	void removeNode(Node* node);
	void createEdge(Node* start, Node* end, double weight = 0);
	void deleteEdge(Node* start, Node* end);
	vector<Node*> getNodes();
	vector<Edge*> getEdges();
	Edge* getEdge(Node* start, Node* end);
	int getNodeIndex(Node* target_node);
	friend ostream& operator<<(ostream& out, Graph& graph);
};

