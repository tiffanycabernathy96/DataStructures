#pragma once
struct Node;
struct Edge {
	Node *end;
	int weight;
	Edge* next;
	Edge(Node* end, int weight);
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