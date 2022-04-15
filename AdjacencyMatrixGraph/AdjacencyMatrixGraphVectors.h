#pragma once
#include "Graph.h"
#include <vector>
using namespace std;

class AdjacencyMatrixGraphVectors {

private:
	vector<vector<int>> adjMatrix;
	int numVertices;
public:
	AdjacencyMatrixGraphVectors(int iVertices);
	~AdjacencyMatrixGraphVectors();

	void addEdge(Edge iEdge);
	void deleteEdge(Edge iEdge);

	void printMatrix();
	void print();
};