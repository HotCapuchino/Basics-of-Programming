#include "Edge.h"
#include "Node.h"



Edge::Edge(Node* start, Node* end) {
	this->start = start;
	this->end = end;
}

void Edge::setWeight(double weight) {
	this->weight = weight;
}

double Edge::getWeight() {
	return weight;
}

Node* Edge::getStart() {
	return start;
}

Node* Edge::getEnd() {
	return end;
}

Edge::~Edge() {
	delete &start;
	delete &end;
}

bool Edge::operator==(Edge* edge) {
	if (edge == this) {
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<<(ostream& out, Edge& edge) {
	out << "Edge starts in: " << edge.getStart()->getName() << ", ends in: " << edge.getEnd()->getName();
	if (edge.getWeight() >= 0.0) out << "; Edge's weight: " << edge.getWeight();
	out << endl;
	return out;
}
