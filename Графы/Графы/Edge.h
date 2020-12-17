#pragma once
#include "Node.h"

class Edge {
private:
	Node* start;
	Node* end;
	double weight;
	Edge();
public:
	Edge(Node* start, Node* end);
	void setWeight(double weight);
	double getWeight();
	Node* getStart();
	Node* getEnd();
	~Edge();
	bool operator ==(Edge* edge);
	friend ostream& operator<<(ostream& out, Edge& edge);
};

