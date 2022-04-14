#pragma once
#include "Graph.h"

class AdjacencyMatrixGraph : public Graph {
	int adjMatrix[NUMNODES][NUMNODES];

public:
	AdjacencyMatrixGraph(Node nodes[], Edge edges[]);
	~AdjacencyMatrixGraph();

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);

	void print();
};