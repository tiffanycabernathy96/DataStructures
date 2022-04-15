#include "Graph.h"

Edge::Edge(int iStart, int iEnd, int iWeight) {
	start = iStart;
	end = iEnd;
	weight = iWeight;
}
bool Edge::operator == (const Edge iEdge) {
	if (start == iEdge.start && end == iEdge.end && weight == iEdge.weight)
		return true;
	else
		return false;
}
Edge::Edge() {
	start = -1;
	end = -1;
	weight = -1;
}