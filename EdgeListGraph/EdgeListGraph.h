#pragma once
#include "Graph.h"

class EdgeListGraph{
	Edge** edges;
	Node** nodes;
	int numVertices;
	int numEdges;

	void deleteEdges(int node);

	void bfsSearch(int iStart, bool* visited);
public:
	EdgeListGraph(Node *iNodes, Edge *iEdges, int iNumNodes, int iNumEdges);
	~EdgeListGraph();

	void addNode(int node);
	void deleteNode(int node);

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);
	
	void printByNodes();

	void print();

	void bfs();
	void dfs();
};