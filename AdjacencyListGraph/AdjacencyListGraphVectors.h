#pragma once
#include "Graph.h"
#include <vector>
using namespace std;

class AdjacencyListGraphVectors {
	vector<Node> adjList;

	void bfsSearch(int iStart, vector<bool>& iVisited);
	void dfsR(int iStart, vector<bool>& iVisited);
public:
	AdjacencyListGraphVectors(int iNumVertices);
	~AdjacencyListGraphVectors();

	void addEdge(int iStart, int iEnd, int iWeight);
	void deleteEdge(int iStart, int iEnd, int iWeight);

	void print();

	void bfs(int iStart = -1);
	void dfs(int iStart = -1);
};