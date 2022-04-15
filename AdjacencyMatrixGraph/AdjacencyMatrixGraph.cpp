//Tiffany Abernathy - Implementation of Adjacency Matrix Graph
#include "AdjacencyMatrixGraph.h"
#include <iostream>
using namespace std;

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

//Public Fuctions
AdjacencyMatrixGraph::AdjacencyMatrixGraph() {
    
}
AdjacencyMatrixGraph::~AdjacencyMatrixGraph() {

}

void AdjacencyMatrixGraph::addEdge(Edge* edge) {

}
void AdjacencyMatrixGraph::deleteEdge(Edge* edge) {

}

void AdjacencyMatrixGraph::print() {

}

int main()
{
    std::cout << "Hello World!\n";
}