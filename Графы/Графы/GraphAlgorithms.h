#pragma once
#include "Graph.h"
#include <fstream>

class GraphAlgorithms
{
public:
	GraphAlgorithms();
	void depthSearch(Node& start_node, vector<bool>& visited, Node& previous_node, Graph& graph); 
	double Dijkstra(Node& start_node, Node& target_node, Graph& graph, vector<double>& roads, vector<bool>& visited);
	Graph readGraph(string file_name, vector<Node*>& all_nodes, bool directed, bool measured);
	~GraphAlgorithms();
};

