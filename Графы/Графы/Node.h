#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Node {
private:
	vector<Node*> neighbours;
	string name;
	Node();
public:
	Node(string name);
	~Node();
	void addNeighbour(Node* neighbour);
	void removeNeighbour(Node* neighbour);
	string getName();
	vector<Node*> getNeighbours();
	bool operator ==(Node* node);
	friend class Edge;
	friend ostream& operator <<(ostream& out, Node& node);
};
