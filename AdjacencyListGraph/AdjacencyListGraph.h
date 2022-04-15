#pragma once
#include "Graph.h"

struct Edge {
	int start, end, weight;
	Edge(int start, int end, int weight);
	Edge();
};

struct Node {
	int name;
	Node(int name);
	Node();
};

class AdjacencyListGraph : public Graph {


public:
	AdjacencyListGraph(Node nodes[], Edge edges[]);
	~AdjacencyListGraph();

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);

	void print();
};