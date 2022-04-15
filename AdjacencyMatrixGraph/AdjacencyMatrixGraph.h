#pragma once
const int NUMNODES=5;

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

class AdjacencyMatrixGraph {
	
private:
	//int adjMatrix[NUMNODES][NUMNODES];

public:
	AdjacencyMatrixGraph();
	~AdjacencyMatrixGraph();

	void addEdge(Edge* edge);
	void deleteEdge(Edge* edge);

	void print();
};