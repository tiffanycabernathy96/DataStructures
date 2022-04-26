#pragma once
#include "Graph.h"

class EdgeListGraph{
	Edge** edges;
	Node** nodes;
	int numVertices;
	int numEdges;

	void deleteEdges(int iNode);

	void bfsSearch(int iStart, bool* iVisited);
	void dfsR(int iStart, bool* iVisited);
public:
	EdgeListGraph(Node *iNodes, Edge *iEdges, int iNumNodes, int iNumEdges);
	~EdgeListGraph();

	void addNode(int iNode);
	void deleteNode(int iNode);

	void addEdge(Edge* iEdge);
	void deleteEdge(Edge* iEdge);
	
	void printByNodes();

	void print();

	void bfs(int iStart = -1);
	void dfs(int iStart = -1);
};