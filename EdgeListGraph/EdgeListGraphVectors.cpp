//Tiffany Abernathy - Implementation of Edge List Graph Using Vectors. Directed and Weighted. 
#include "EdgeListGraphVectors.h"
#include <iostream>

EdgeListGraphVectors::EdgeListGraphVectors(vector<Node>& iNodes, vector<Edge>& iEdges) {
	nodes = vector<Node>();
	edges = vector<Edge>();
	for (int i = 0; i < iNodes.size(); i++) {
		nodes.push_back(Node(iNodes[i].name));
	}
	for (int i = 0; i < iEdges.size(); i++) {
		edges.push_back(Edge(iEdges[i].start, iEdges[i].end, iEdges[i].weight));
	}
}
EdgeListGraphVectors::~EdgeListGraphVectors() {
	//Using Vectors Handles this.
}

void EdgeListGraphVectors::addNode(int node) {
	nodes.push_back(Node(node));
}
void EdgeListGraphVectors::deleteNode(int node) {
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i].name == node) {
			swap(nodes[i], nodes[nodes.size()-1]);
			nodes.pop_back();
		}
	}
	deleteEdges(node);
}

void EdgeListGraphVectors::addEdge(Edge edge) {
	edges.push_back(Edge(edge.start, edge.end, edge.weight));
}
void EdgeListGraphVectors::deleteEdge(Edge edge) {
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == edge) {
			swap(nodes[i], nodes[nodes.size() - 1]);
			nodes.pop_back();
			return;
		}
	}
}
void EdgeListGraphVectors::deleteEdges(int node) {
	auto itr = edges.begin();
	while (itr != edges.end()) {
		if ((*itr).start == node || (*itr).end == node) {
			itr = edges.erase(itr);
		}
		else
			itr++;
	}
}

void EdgeListGraphVectors::printByNodes() {
	cout << "Graph Edges by Node: " << endl;
	for (int i = 0; i < nodes.size(); i++) {
		cout << "Edges from Node " << nodes[i].name << endl;
		for (int j = 0; j < edges.size(); j++) {
			if (edges[j].start == nodes[i].name)
				cout << "Start: " << edges[j].start << " End: " << edges[j].end << " Weight: " << edges[j].weight << endl;
		}
	}
}

void EdgeListGraphVectors::print() {
	cout << "Graph Edges: " << endl;
	for (int i = 0; i < edges.size(); i++) {
		cout << "Start: " << edges[i].start << " End: " << edges[i].end << " Weight: " << edges[i].weight << endl;
	}
	cout << endl;
}

int main()
{
	cout << "Adding Nodes 0 through 4" << endl;
	vector<Node> nodes{ Node(0), Node(1), Node(2), Node(3), Node(4) };
	cout << "Adding Starting Edges" << endl;
	vector<Edge> edges{ Edge(0, 1, 5), Edge(1, 3, 10), Edge(1, 0, 6), Edge(2, 4, 8), Edge(3, 2, 1) };
	EdgeListGraphVectors graph(nodes, edges);
	graph.printByNodes();
	cout << "Adding Node 5" << endl;
	graph.addNode(5);
	graph.printByNodes();
	cout << "Adding Edge 5, 2 with weight 7" << endl;
	graph.addEdge(Edge(5, 2, 7));
	graph.printByNodes();
	cout << "Deleting Node 1 and corresponding Edges" << endl;
	cout << "Edges before Deletion" << endl;
	graph.print();
	graph.deleteNode(1);
	cout << "Edges after Deletion" << endl;
	graph.print();
}
