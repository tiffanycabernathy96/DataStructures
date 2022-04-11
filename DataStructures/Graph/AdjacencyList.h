#pragma once
#include "Graph.h"

class AdjacencyList : public Graph {


public:
	AdjacencyList(Node nodes[], Edge edges[], int numEdges);
	~AdjacencyList();

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);

	void print();
};