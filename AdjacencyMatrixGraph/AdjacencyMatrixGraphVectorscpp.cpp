//Tiffany Abernathy - Implementation of Adjacency Matrix Graph Using Vectors. Directed and Weighted. 
#include "AdjacencyMatrixGraphVectors.h"
#include <iostream>
using namespace std;

//Public Fuctions
AdjacencyMatrixGraphVectors::AdjacencyMatrixGraphVectors(int iVertices) {
    numVertices = iVertices;
    adjMatrix = vector<vector<int>>();
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = -1;
    }
}
AdjacencyMatrixGraphVectors::~AdjacencyMatrixGraphVectors() {
    
}

void AdjacencyMatrixGraphVectors::addEdge(Edge iEdge) {
    if (iEdge.start >= 0 && iEdge.end < numVertices) {
        adjMatrix[iEdge.start][iEdge.end] = iEdge.weight;
        cout << "Edge Created From " << iEdge.start << " To " << iEdge.end << " Weighing " << iEdge.weight << endl;
    }
    else
        cout << "Invalid Edge" << endl;
}
void AdjacencyMatrixGraphVectors::deleteEdge(Edge iEdge) {
    if (iEdge.start >= 0 && iEdge.end < numVertices) {
        adjMatrix[iEdge.start][iEdge.end] = -1;
        cout << "Edge Deleted From " << iEdge.start << " To " << iEdge.end << " Weighing " << iEdge.weight << endl;
    }
    else
        cout << "Invalid Edge" << endl;
}
void AdjacencyMatrixGraphVectors::printMatrix() {
    cout << "Graph: " << endl;
    cout << "    ";
    for (int i = 0; i < numVertices; i++)
        cout << " " << i << "  ";
    cout << endl;

    cout << "    ";
    for (int i = 0; i < numVertices; i++)
        cout << "____";
    cout << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "  " << i << "|";
        for (int j = 0; j < numVertices; j++) {
            if (adjMatrix[i][j] != -1) {
                cout << " " << adjMatrix[i][j] << "|";
            }
            else {
                cout << "   |";
            }
        }
        cout << endl;
    }
    cout << "    ";
    for (int i = 0; i < numVertices; i++)
        cout << "____";
}
void AdjacencyMatrixGraphVectors::print() {
    cout << "Graph: " << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjMatrix[i][j] != -1) {
                cout << "Edge From " << i << " To " << j << " Weighing " << adjMatrix[i][j] << endl;
            }
        }
        cout << endl;
    }
}
/*int main()
{
    AdjacencyMatrixGraphVectors graph(5);

    graph.addEdge(Edge(0, 0, 10));
    graph.addEdge(Edge(0, 4, 10));
    graph.addEdge(Edge(1, 1, 10));
    graph.addEdge(Edge(1, 3, 10));
    graph.addEdge(Edge(2, 2, 10));
    graph.addEdge(Edge(3, 1, 10));
    graph.addEdge(Edge(3, 3, 10));
    graph.addEdge(Edge(4, 0, 10));
    graph.addEdge(Edge(4, 4, 10));

    graph.print();
    graph.printMatrix();
}*/