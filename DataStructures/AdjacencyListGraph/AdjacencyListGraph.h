#pragma once
#include "Graph.h"

class AdjacencyListGraph : public Graph {


public:
	AdjacencyListGraph(Node nodes[], Edge edges[]);
	~AdjacencyListGraph();

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);

	void print();
};