#pragma once
#include "Graph.h"

class EdgeListGraph : public Graph {
	Edge **edges;
	Node **nodes;
	int nEdges;
public:
	EdgeListGraph(Node nodes[], Edge edges[], int numEdges);
	~EdgeListGraph();

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);

	void print();
};