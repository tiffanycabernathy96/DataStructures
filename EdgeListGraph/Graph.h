#pragma once
struct Edge {
	int start, end, weight;
	Edge(int start, int end, int weight);
	Edge();
	bool operator==(const Edge iEdge);
};

struct Node {
	int name;
	Node(int name);
	Node();
	bool operator==(const Node iNode);
};