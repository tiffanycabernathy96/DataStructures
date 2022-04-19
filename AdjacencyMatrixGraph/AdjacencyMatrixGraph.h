#pragma once
#include "Graph.h"

class AdjacencyMatrixGraph {
	
private:
	int** adjMatrix;
	int numVertices;

	void bfsSearch(int iStart, bool* visited);
public:
	AdjacencyMatrixGraph(int iVertices);
	~AdjacencyMatrixGraph();

	void addEdge(Edge iEdge);
	void deleteEdge(Edge iEdge);

	void printMatrix();
	void print();

	void bfs();
	void dfs();
};