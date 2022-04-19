#pragma once
#include "Graph.h"

class AdjacencyListGraph{
	int numVertices;
	Node** adjList;

	void bfsSearch(int iStart, bool* visited);
public:
	AdjacencyListGraph(int iNumVertices);
	~AdjacencyListGraph();

	void addEdge(int start, int end, int weight);
	void deleteEdge(int start, int end, int weight);

	void print();

	void bfs();
	void dfs();
};