//Tiffany Abernathy - Interface for Graph Implementations
#include "Graph.h"

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

