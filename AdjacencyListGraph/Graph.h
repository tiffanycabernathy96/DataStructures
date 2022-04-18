#pragma once
struct Edge {
	Node *start, *end;
	int weight;
	Edge(Node* start, Node* end, int weight);
	Edge();
	bool operator==(const Edge* iEdge);
};

struct Node {
	int name;
	Edge* next;
	Node(int name);
	Node();
	bool operator==(const Node* iNode);
};