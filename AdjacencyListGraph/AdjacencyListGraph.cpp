//Tiffany Abernathy - Implementation of Adjacency List Graph

#include "AdjacencyListGraph.h"

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

AdjacencyListGraph::AdjacencyListGraph(Node nodes[], Edge edges[]) {
    
}
AdjacencyListGraph::~AdjacencyListGraph() {

}

void AdjacencyListGraph::addEdge(Edge* edge) {

}
void AdjacencyListGraph::deleteEdge(Edge* edge) {

}

void AdjacencyListGraph::print() {

}

int main()
{
    std::cout << "Hello World!\n";
}
