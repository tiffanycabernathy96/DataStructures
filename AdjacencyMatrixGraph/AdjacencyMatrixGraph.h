#pragma once
#include "Graph.h"

class AdjacencyMatrixGraph {
	
private:
	int** adjMatrix;
	int numVertices;

	void bfsSearch(int iStart, bool* iVisited);
	void dfsR(int iStart, bool* iVisited);
public:
	AdjacencyMatrixGraph(int iVertices);
	~AdjacencyMatrixGraph();

	void addEdge(Edge iEdge);
	void deleteEdge(Edge iEdge);

	void printMatrix();
	void print();

	void bfs(int iStart = -1);
	void dfs(int iStart = -1);
};