#include "Graph.h"

Edge::Edge(Node* iEnd, int iWeight) {
	end = iEnd;
	weight = iWeight;
	next = nullptr;
}
bool Edge::operator == (const Edge* iEdge) {
	if (end == iEdge->end && weight == iEdge->weight && next == iEdge->next)
		return true;
	else
		return false;
}
Edge::Edge() {
	end = nullptr;
	weight = -1;
	next = nullptr;
}
Node::Node(int iName) {
	name = iName;
	next = nullptr;
}
Node::Node() {
	name = -1;
}
bool Node::operator==(const Node* iNode) {
	if (name == iNode->name && next == iNode->next)
		return true;
	else
		return false;
}