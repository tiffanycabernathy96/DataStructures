#pragma once
#include "Graph.h"

class AdjacencyListGraph{
	int numVertices;
	Node** adjList;

	void bfsSearch(int iStart, bool* iVisited);
	void dfsR(int iStart, bool* iVisited);
public:
	AdjacencyListGraph(int iNumVertices);
	~AdjacencyListGraph();

	void addEdge(int iStart, int iEnd, int iWeight);
	void deleteEdge(int iStart, int iEnd, int iWeight);

	void print();

	void bfs(int iStart = -1);
	void dfs(int iStart = -1);
};