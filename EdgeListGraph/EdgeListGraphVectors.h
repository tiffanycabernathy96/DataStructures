#pragma once
#include "Graph.h"
#include <vector>
using namespace std;

class EdgeListGraphVectors {
	vector<Node> nodes;
	vector<Edge> edges;
public:
	EdgeListGraphVectors(vector<Node>& iNodes, vector<Edge>& iEdges);
	~EdgeListGraphVectors();

	void addNode(int node);
	void deleteNode(int node);

	void addEdge(Edge edge);
	void deleteEdge(Edge edge);
	void deleteEdges(int node);

	void printByNodes();

	void print();
};