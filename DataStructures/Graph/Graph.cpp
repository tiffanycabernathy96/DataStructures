//Tiffany Abernathy - Testing of 3 types of Graphs
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "EdgeList.h"

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
int main()
{
    Node nodes[] = { Node(0), Node(1), Node(2), Node(3), Node(4) };
    Edge edges[] = { Edge(0, 1, 5), Edge(1, 3, 10), Edge(1, 0, 6), Edge(2, 4, 8), Edge(3, 2, 1)};
    int numNodes = sizeof(nodes) / sizeof(nodes[0]);
    int numEdges = sizeof(edges) / sizeof(edges[0]);
    
    //EdgeListGraph edgeList = EdgeListGraph(nodes, edges, numNodes, numEdges);
    //edgeList.print();
   
}

