//Tiffany Abernathy - Implementation of Adjacency Matrix Graph Using Arrays. Directed and Weighted. 
//Implementation of BFS and DFS - Works for Disconnected and Connected Graphs. Optional Input for Start Value

#include "AdjacencyMatrixGraph.h"
#include <iostream>
#include <queue>
using namespace std;

//Private Functions
void AdjacencyMatrixGraph::bfsSearch(int iStart, bool* iVisited) {
    int vis;
    queue<int> que;
    iVisited[iStart] = true;
    que.push(iStart);

    while (!que.empty()) {

        vis = que.front();
        cout << vis << " ";
        que.pop();

        for (int i = 0; i < numVertices; i++) {
            if (!iVisited[i] && adjMatrix[vis][i] != -1) {
                que.push(i);
                iVisited[i] = true;
            }
        }
    }
}

void AdjacencyMatrixGraph::dfsR(int iStart, bool* iVisited) {
    iVisited[iStart] = true;
    cout << iStart << " ";
    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[iStart][i] != -1 && !iVisited[i]) {
            dfsR(i, iVisited);
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
                if (adjMatrix[i][j] % 10 == adjMatrix[i][j])
                    cout << "  " << adjMatrix[i][j] << "|";
                else
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

void AdjacencyMatrixGraph::bfs(int iStart) {
    //Array for Visited Nodes
    bool* visited = new bool[numVertices];
    //Mark all of them unvisited. 
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
    if (iStart != -1) {
        //Perform BFS on the given start node
        bfsSearch(iStart, visited);
    }
    else {
        //Perform BFS - Handles Disconnected Graph
        //Go through all nodes in case of disconnected graph
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i])
                bfsSearch(i, visited);
        }
    }
}

void AdjacencyMatrixGraph::dfs(int iStart) {
    //Array for Visited Nodes
    bool* visited = new bool[numVertices];
    //Mark all of them unvisited.
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
    if (iStart != -1) {
        //Perform DFS on the given start node
        dfsR(iStart, visited);
    }
    else {
        //Perform DFS - Handles Disconnected Graph
        //Go through all nodes in case of disconnected graph
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i])
                dfsR(i, visited);
        }
    }
}

//int main()
//{
//    cout << endl << "Showing DFS and BFS" << endl;
//    AdjacencyMatrixGraph graph(8);
//    graph.addEdge(Edge(0, 4, 15));
//    graph.addEdge(Edge(1, 2, 11));
//    graph.addEdge(Edge(1, 5, 10));
//    graph.addEdge(Edge(2, 1, 18));
//    graph.addEdge(Edge(2, 5, 29));
//    graph.addEdge(Edge(2, 6, 23));
//    graph.addEdge(Edge(3, 1, 10));
//    graph.addEdge(Edge(3, 5, 16));
//    graph.addEdge(Edge(3, 7, 17));
//    graph.addEdge(Edge(5, 6, 13));
//    graph.addEdge(Edge(6, 2, 14));
//    graph.addEdge(Edge(6, 4, 10));
//    graph.addEdge(Edge(7, 6, 25));
//
//    graph.printMatrix();
//
//    cout << endl << "BFS Searches - Ignoring Disconnects" << endl;
//    cout << "BFS at 5" << endl;
//    graph.bfs(5);
//    //5 6 2 4 1
//    cout << endl << "BFS at 1" << endl;
//    graph.bfs(1);
//    //1 2 5 6 4
//    cout << endl << "BFS at 3" << endl;
//    graph.bfs(3);
//    //3 1 5 7 2 6 4
//    cout << endl << endl << "DFS Searches - Ignoring Disconnects" << endl;
//    cout << "DFS at 5" << endl;
//    graph.dfs(5);
//    //5 6 2 1 4
//    cout << endl << "DFS at 1" << endl;
//    graph.dfs(1);
//    //1 2 5 6 4
//    cout << endl << "DFS at 3" << endl;
//    graph.dfs(3);
//    //3 1 2 5 6 4 7
//}