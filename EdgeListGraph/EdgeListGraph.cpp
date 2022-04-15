//Tiffany Abernathy - Implementation of Edge List Graph Using Arrays
#include "Graph.h"
#include "EdgeListGraph.h"

Edge::Edge(int start, int end, int weight) {
	this->start = start;
	this->end = end;
	this->weight = weight;
}
Edge::Edge() {
	this->start = -1;
	this->end = -1;
	this->weight = -1;
}
Node::Node(int name) {
	this->name = name;
}
Node::Node() {
	this->name = -1;
}

EdgeListGraph::EdgeListGraph(Node *iNodes, Edge *iEdges, int iNumNodes, int iNumEdges) {
	this->numNodes = iNumNodes;
	this->numEdges = iNumEdges;
	this->nodes = new Node * [numNodes]();
	this->edges = new Edge * [numEdges]();
	for (int i = 0; i < numNodes; i++) {
		this->nodes[i] = new Node(iNodes[i].name);
	}
	for (int i = 0; i < numEdges; i++) {
		this->edges[i] = new Edge(iEdges[i].start, iEdges[i].end, iEdges[i].weight);
	}
}
EdgeListGraph::~EdgeListGraph() {

}

void EdgeListGraph::addNode(Node* node) {
	Node** tempNodes = new Node * [numNodes+1]();
	for (int i = 0; i < numNodes; i++) {
		tempNodes[i] = this->nodes[i];
	}
	tempNodes[numNodes] = node;
	numNodes++;
	delete []this->nodes;
	this->nodes = tempNodes;
}
void EdgeListGraph::deleteNode(Node* node) {

}

void EdgeListGraph::addEdge(Edge* edge) {
	Edge** tempEdges = new Edge * [numEdges + 1]();
	for (int i = 0; i < numEdges; i++) {
		tempEdges[i] = this->edges[i];
	}
	tempEdges[numEdges] = edge;
	numEdges++;
	delete[]this->edges;
	this->edges = tempEdges;

}
void EdgeListGraph::deleteEdge(Edge* edge) {

}

void EdgeListGraph::print(Node* node) {
	cout << "Edges from Node " << node->name << endl;
	for (int i = 0; i < numEdges; i++) {
		if(edges[i]->start == node->name)
			cout << "Start: " << edges[i]->start << " End: " << edges[i]->end << " Weight: " << edges[i]->weight << endl;
	}
}

void EdgeListGraph::print() {
	cout << "Graph: " << endl;
	for (int i = 0; i < numNodes; i++) {
		print(nodes[i]);
	}
	//for (int i = 0; i < numEdges; i++) {
	//	cout << "Start: " << edges[i]->start << " End: " << edges[i]->end << " Weight: " << edges[i]->weight << endl;
	//}
	cout << endl;
}

int main()
{
	cout << "Adding Nodes 0 through 4" << endl;
	Node nodes[] = { Node(0), Node(1), Node(2), Node(3), Node(4) };
	cout << "Adding Starting Edges" << endl;
	Edge edges[] = { Edge(0, 1, 5), Edge(1, 3, 10), Edge(1, 0, 6), Edge(2, 4, 8), Edge(3, 2, 1) };
	EdgeListGraph graph(nodes, edges, 5, 5);
	graph.print();
	cout << "Adding Node 5" << endl;
	graph.addNode(new Node(5));
	graph.print();
	cout << "Adding Edge 5, 2 with weight 7" << endl;
	graph.addEdge(new Edge(5, 2, 7));
	graph.print();
}
