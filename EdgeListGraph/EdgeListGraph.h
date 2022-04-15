#pragma once
#include "Graph.h"

class EdgeListGraph{
	Edge** edges;
	Node** nodes;
	int numNodes;
	int numEdges;
public:
	EdgeListGraph(Node *iNodes, Edge *iEdges, int iNumNodes, int iNumEdges);
	~EdgeListGraph();

	void addNode(int node);
	void deleteNode(int node);

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);
	void deleteEdges(int node);

	void printByNodes();

	void print();
};