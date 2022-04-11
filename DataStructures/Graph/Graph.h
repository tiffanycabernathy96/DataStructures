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

const int NUMNODES = 5;

class Graph {
	
	virtual void addEdge(Edge* edge) = 0;
	virtual void deleteEdge(Edge* edge) = 0;

	virtual void print() = 0;
};