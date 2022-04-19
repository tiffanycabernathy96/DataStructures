//Tiffany Abernathy - Implementation of Adjacency Matrix Graph Using Arrays. Directed and Weighted. 
#include "AdjacencyMatrixGraph.h"
#include <iostream>
#include <queue>
using namespace std;

//Private Functions
void AdjacencyMatrixGraph::bfsSearch(int iStart, bool* visited) {
    int vis;
    queue<int> que;
    visited[iStart] = true;
    que.push(iStart);

    while (!que.empty()) {

        vis = que.front();
        cout << vis << " ";
        que.pop();

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i] && adjMatrix[vis][i] != -1) {
                que.push(i);
                visited[i] = true;
            }
        }
    }
}

//Public Fuctions
AdjacencyMatrixGraph::AdjacencyMatrixGraph(int iVertices) {
    numVertices = iVertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++)
        adjMatrix[i] = new int[numVertices];
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = -1;
    }
}
AdjacencyMatrixGraph::~AdjacencyMatrixGraph() {
    for (int i = 0; i < numVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void AdjacencyMatrixGraph::addEdge(Edge iEdge) {
    if (iEdge.start >= 0 && iEdge.end < numVertices) {
        adjMatrix[iEdge.start][iEdge.end] = iEdge.weight;
        cout << "Edge Created From " << iEdge.start << " To " << iEdge.end << " Weighing " << iEdge.weight << endl;
    }
    else
        cout << "Invalid Edge" << endl;
}
void AdjacencyMatrixGraph::deleteEdge(Edge iEdge) {
    if (iEdge.start >= 0 && iEdge.end < numVertices) {
        adjMatrix[iEdge.start][iEdge.end] = -1;
        cout << "Edge Deleted From " << iEdge.start << " To " << iEdge.end << " Weighing " << iEdge.weight << endl;
    }
    else
        cout << "Invalid Edge" << endl;
}
void AdjacencyMatrixGraph::printMatrix() {
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
        cout <<"  " << i << "|";
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
    cout << endl;
}
void AdjacencyMatrixGraph::print() {
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

void AdjacencyMatrixGraph::bfs() {
    //Array for Visited Nodes
    bool* visited = new bool[numVertices];
    //Mark all of them unvisited. 
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
    //Go through all nodes in case of disconnected graph
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i])
            bfsSearch(i, visited);
    }
}

void AdjacencyMatrixGraph::dfs() {

}

//int main()
//{
//    AdjacencyMatrixGraph graph(5);
//
//    graph.addEdge(Edge(0, 0, 10));
//    graph.addEdge(Edge(0, 4, 10));
//    graph.addEdge(Edge(1, 1, 10));
//    graph.addEdge(Edge(1, 3, 10));
//    graph.addEdge(Edge(2, 2, 10));
//    graph.addEdge(Edge(3, 1, 10));
//    graph.addEdge(Edge(3, 3, 10));
//    graph.addEdge(Edge(4, 0, 10));
//    graph.addEdge(Edge(4, 4, 10));
//
//    graph.print();
//    graph.printMatrix();
//    graph.bfs();
//}