//Tiffany Abernathy - Implementation of Adjacency List Graph using Arrays
#include "AdjacencyListGraph.h"
#include <iostream>
using namespace std;

AdjacencyListGraph::AdjacencyListGraph(int iNumVertices) {
    numVerticies = iNumVertices;
    adjList = new Node * [numVerticies];
    for (int i = 0; i < numVerticies; i++) {
        adjList[i] = new Node(i);
    }
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
