#pragma once
#include "Graph.h"

class AdjacencyListGraph{
	int numVerticies;
	Node** adjList;

public:
	AdjacencyListGraph(int iNumVertices);
	~AdjacencyListGraph();

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);

	void print();
};