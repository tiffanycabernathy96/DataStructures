#pragma once
#include "Graph.h"

class EdgeListGraph : public Graph {
	Edge** edges;
	Node** nodes;
public:
	EdgeListGraph(Node nodes[], Edge edges[]);
	~EdgeListGraph();

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);

	void print();
};