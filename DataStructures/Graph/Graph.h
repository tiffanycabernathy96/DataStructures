#pragma once
#include <iostream>
using namespace std;

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

const Node NODES[] = { Node(0), Node(1), Node(2), Node(3), Node(4) };
const Edge EDGES[] = { Edge(0, 1, 5), Edge(1, 3, 10), Edge(1, 0, 6), Edge(2, 4, 8), Edge(3, 2, 1) };
const int NUMNODES = sizeof(NODES) / sizeof(NODES[0]);
const int NUMEDGES = sizeof(EDGES) / sizeof(EDGES[0]);

class Graph {
	
	virtual void addEdge(Edge* edge) = 0;
	virtual void deleteEdge(Edge* edge) = 0;

	virtual void print() = 0;
};