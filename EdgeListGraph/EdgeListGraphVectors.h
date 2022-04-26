#pragma once
#include "Graph.h"
#include <vector>
using namespace std;

class EdgeListGraphVectors {
	vector<Node> nodes;
	vector<Edge> edges;

	void deleteEdges(int iNode);

	void bfsSearch(int iStart, vector<bool> &iVisited);
	void dfsR(int iStart, vector<bool>& iVisited);
public:
	EdgeListGraphVectors(vector<Node>& iNodes, vector<Edge>& iEdges);
	~EdgeListGraphVectors();

	void addNode(int iNode);
	void deleteNode(int iNode);

	void addEdge(Edge iEdge);
	void deleteEdge(Edge iEdge);

	void printByNodes();

	void print();

	void bfs(int iStart = -1);
	void dfs(int iStart = -1);
};