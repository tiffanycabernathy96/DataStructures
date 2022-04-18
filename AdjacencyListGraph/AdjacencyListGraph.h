#pragma once
#include "Graph.h"

class AdjacencyListGraph{
	int numVerticies;
	Node** adjList;

public:
	AdjacencyListGraph(int iNumVertices);
	~AdjacencyListGraph();

	void addEdge(int start, int end, int weight);
	void deleteEdge(int start, int end, int weight);

	void print();
};