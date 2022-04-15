#pragma once
#include <iostream>
using namespace std;

struct Node;
struct Edge;

class Graph {
public:
	
	virtual void addNode(int node) = 0;
	virtual void deleteNode(int node) = 0;

	virtual void addEdge(Edge* edge) = 0;
	virtual void deleteEdge(Edge* edge) = 0;

	virtual void print() = 0;
};