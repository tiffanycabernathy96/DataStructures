#include "Graph.h"

Edge::Edge(Node* iStart, Node* iEnd, int iWeight) {
	start = iStart;
	end = iEnd;
	weight = iWeight;
}
bool Edge::operator == (const Edge* iEdge) {
	if (start == iEdge->start && end == iEdge->end && weight == iEdge->weight)
		return true;
	else
		return false;
}
Edge::Edge() {
	start = nullptr;
	end = nullptr;
	weight = -1;
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