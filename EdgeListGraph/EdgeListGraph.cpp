//Tiffany Abernathy - Implementation of Edge List Graph

#include "EdgeListGraph.h"

EdgeListGraph::EdgeListGraph(Node nodes[], Edge edges[]) {
	this->nodes = new Node * [NUMNODES]();
	this->edges = new Edge * [NUMEDGES]();
	for (int i = 0; i < NUMNODES; i++) {
		this->nodes[i] = new Node(nodes[i].name);
	}
	for (int i = 0; i < NUMEDGES; i++) {
		this->edges[i] = new Edge(edges[i].start, edges[i].end, edges[i].weight);
	}
}
EdgeListGraph::~EdgeListGraph() {

}

void EdgeListGraph::addEdge(Edge* edge) {

}
void EdgeListGraph::deleteEdge(Edge* edge) {

}

void EdgeListGraph::print() {
	for (int i = 0; i < NUMEDGES; i++) {
		cout << "Start: " << edges[i]->start << " End: " << edges[i]->end << " Weight: " << edges[i]->weight << endl;
	}
}

int main()
{
    std::cout << "Hello World!\n";
}
