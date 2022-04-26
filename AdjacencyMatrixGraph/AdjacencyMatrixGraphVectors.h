#pragma once
#include "Graph.h"
#include <vector>
using namespace std;

class AdjacencyMatrixGraphVectors {

private:
	vector<vector<int>> adjMatrix;
	int numVertices;

	void bfsSearch(int iStart, vector<bool> *visited);
	void dfsR(int iStart, vector<bool> *visited);
public:
	AdjacencyMatrixGraphVectors(int iVertices);
	~AdjacencyMatrixGraphVectors();

	void addEdge(Edge iEdge);
	void deleteEdge(Edge iEdge);

	void printMatrix();
	void print();

	void bfs(int start = -1);
	void dfs(int start = -1);
};