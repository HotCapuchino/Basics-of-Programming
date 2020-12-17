#include "Node.h"
#include "Edge.h"

using namespace std;
Node::Node() {
}

Node::Node(string name) {
	this->name = name;
}

Node::~Node() {
	neighbours.clear();
}

void Node::addNeighbour(Node* neighbour) {
	for (int i = 0; i < neighbours.size(); i++) {
		if (neighbours.at(i) == neighbour) return;
	}
	neighbours.push_back(neighbour);
}

void Node::removeNeighbour(Node* neighbour) {
	if (!neighbours.empty()) {
		for (int i = 0; i < neighbours.size(); i++) {
			if (neighbours.at(i) == neighbour)
				neighbours.erase(neighbours.begin() + i);
		}
	}
}

string Node::getName() {
	return name;
}

vector<Node*> Node::getNeighbours() {
	return neighbours;
}

bool Node::operator==(Node* node)
{
	if (node->neighbours == this->neighbours) {
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<<(ostream& out, Node& node) {
	out << "Node name: " << node.getName();
	if (node.getNeighbours().size() > 0) {
		out << "\nNode neighbours:\n";
		for (int i = 0; i < node.getNeighbours().size(); i++) {
			out << "\t" << i + 1 << ":" << node.getNeighbours().at(i)->getName() << endl;
		}
	} else {
		out << "\nNode has no neighbours";
	}
	return out;
}
