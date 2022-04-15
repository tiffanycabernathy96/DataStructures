#pragma once
#include "Graph.h"

struct Edge {
	int start, end, weight;
	Edge(int start, int end, int weight);
	Edge();
};

struct Node {
	int name;
	Node(int name);
	Node();
};

class EdgeListGraph : public Graph {
	Edge** edges;
	Node** nodes;
	int numNodes;
	int numEdges;
public:
	EdgeListGraph(Node *iNodes, Edge *iEdges, int iNumNodes, int iNumEdges);
	~EdgeListGraph();

	void addNode(Node* node);
	void deleteNode(Node* node);

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);

	void print(Node*);

	void print();
};