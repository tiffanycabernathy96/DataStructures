#pragma once
#include "Graph.h"

class AdjacencyMatrix : public Graph {
	int adjMatrix[NUMNODES][NUMNODES];

public:
	AdjacencyMatrix(Node nodes[], Edge edges[], int numEdges);
	~AdjacencyMatrix();

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);

	void print();
};