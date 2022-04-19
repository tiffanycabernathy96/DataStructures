#pragma once
#include "Graph.h"
#include <vector>
using namespace std;

class EdgeListGraphVectors {
	vector<Node> nodes;
	vector<Edge> edges;

	void deleteEdges(int node);

	void bfsSearch(int iStart, vector<bool> &visited);
public:
	EdgeListGraphVectors(vector<Node>& iNodes, vector<Edge>& iEdges);
	~EdgeListGraphVectors();

	void addNode(int node);
	void deleteNode(int node);

	void addEdge(Edge edge);
	void deleteEdge(Edge edge);

	void printByNodes();

	void print();

	void bfs();
	void dfs();
};