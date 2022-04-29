//Tiffany Abernathy - Implementation of Adjacency List Graph using Arrays
//Implementation of BFS and DFS - Works for Disconnected and Connected Graphs. Optional Input for Start Value

#include "AdjacencyListGraph.h"
#include <iostream>
#include <queue>
using namespace std;

//Private Functions
void AdjacencyListGraph::bfsSearch(int iStart, bool* iVisited) {
    Node* nTemp = adjList[iStart];
    queue<Node*> que;
    iVisited[iStart] = true;
    que.push(nTemp);

    while (!que.empty()) {

        nTemp = que.front();
        Edge* eTemp = nTemp->next;
        cout << nTemp->name << " ";
        que.pop();

        while (eTemp) {
            if (!iVisited[eTemp->end->name]) {
                iVisited[eTemp->end->name] = true;
                que.push(eTemp->end);
            }
            eTemp = eTemp->next;
        }
    }
}

void AdjacencyListGraph::dfsR(int iStart, bool* iVisited) {
    Node* nTemp = adjList[iStart];
    iVisited[iStart] = true;
    cout << iStart << " ";
    Edge* eTemp = nTemp->next;
    while (eTemp) {
        if (!iVisited[eTemp->end->name]) {
            dfsR(eTemp->end->name, iVisited);
        }
        eTemp = eTemp->next;
    }
}

//Public Functions
AdjacencyListGraph::AdjacencyListGraph(int iNumVertices) {
    if (iNumVertices <= 0) {
        cout << "Enter a Valid Number of Vertices" << endl;
    }
    else {
        //Set the num vertices associated with the graph
        numVertices = iNumVertices;
        //Initialize the graph with that number of verticies
        adjList = new Node * [numVertices];
        //Initialize each node with the name as the index to make things easier. 
        for (int i = 0; i < numVertices; i++) {
            adjList[i] = new Node(i);
        }
    }
}
    
AdjacencyListGraph::~AdjacencyListGraph() {
    for (int i = 0; i < numVertices; i++) {
        while (adjList[i]->next) {
            //Delete each edge associated with this node
            Edge* temp = adjList[i]->next;
            adjList[i]->next = temp->next;
            temp->end = nullptr;
            delete temp;
        }
        //Delete the node. 
        delete adjList[i];
    }
}

void AdjacencyListGraph::addEdge(int iStart, int iEnd, int iWeight) {
    if (iStart < 0 || iStart >= numVertices || iEnd < 0 || iEnd >= numVertices) {
        cout << "Invalid Edge" << endl;
        return;
    }
    //Create the new Edge
    Edge* newEdge = new Edge(adjList[iEnd], iWeight);
    //Check if the starting node has the root set
    if(!adjList[iStart]->next){
        //If not set the root to the new Edge. 
        adjList[iStart]->next = newEdge;
    }
    //Check if the roots end node is greater than the new edges
    else if (adjList[iStart]->next->end->name > iEnd) {
        //If so put the new node as root and new nodes next as old root. 
        newEdge->next = adjList[iStart]->next;
        adjList[iStart]->next = newEdge;
    }
    //Otherwise find the place in the list where the new Edge belongs. Keeping end nodes in order. 
    else {
        Edge* parent = adjList[iStart]->next;
        while (parent->next) {
            if (parent->next->end->name > iEnd) {
                newEdge->next = parent->next;
                parent->next = newEdge;
                return;
            }
            else
                parent = parent->next;
        }
        parent->next = newEdge;
    }
}

void AdjacencyListGraph::deleteEdge(int iStart, int iEnd, int iWeight) {
    Edge* parent = adjList[iStart]->next;
    //Confirm the root is not null and the inputted values are valid
    if (parent && iStart > 0 && iStart < numVertices && iEnd > 0 && iEnd < numVertices) {
        //The deleted edge is the root edge of the node
        if (parent->end->name == iEnd && parent->weight == iWeight) {
            adjList[iStart]->next = parent->next;
            delete parent;
            return;
        }
        //Otherwise the deleted edge is elsewhere in the list of edges
        while (parent->next) {
            //The end nodes are in order and the next one is above the value therefore the deleted node doesn't exist
            if (parent->next->end->name > iEnd)
                break;
            if (parent->next->end->name == iEnd && parent->next->weight == iWeight) {
                Edge* temp = parent->next;
                parent->next = parent->next->next;
                delete temp;
                return;
            }
            parent = parent->next;
        }
    }
    cout << "Edge not found or Invalid Input" << endl;
}

void AdjacencyListGraph::print() {
    for (int i = 0; i < numVertices; i++)
    {
        if (!adjList[i]->next)
            continue;
        Edge* temp = adjList[i]->next;
        while (temp) {
            cout << "Start: " << i << " End: " << temp->end->name << " Weight: " << temp->weight << endl;
            temp = temp->next;
        }
    }
}

void AdjacencyListGraph::printPretty() {
    for (int i = 0; i < numVertices; i++) {
        cout << "| " << i << " |";
        if (adjList[i]->next)
        {
            Edge* temp = adjList[i]->next;
            while (temp) {
                cout << " -> | " << temp->end->name << " | " << temp->weight << " |";
                temp = temp->next;
            }
        }
        cout << endl;
    }
}

void AdjacencyListGraph::bfs(int iStart) {

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

void AdjacencyListGraph::dfs(int iStart) {
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
//    cout << "Graph 1 - Showing Ability to Add/Delete Edges" << endl;
//    AdjacencyListGraph graph(5);
//    cout << "Adding Edges: [1,2], [1,4], [1,3]" << endl;
//    graph.addEdge(1, 2, 10);
//    graph.addEdge(1, 4, 8);
//    graph.addEdge(1, 3, 7);
//    graph.print();
//    cout << "Adding Edges: [2,2], [2,1]" << endl;
//    graph.addEdge(2, 2, 4);
//    graph.addEdge(2, 1, 5);
//    graph.print();
//    cout << "Deleting Edge: [1,4]" << endl;
//    graph.deleteEdge(1, 3, 7);
//    graph.print();
//    cout << "Deleting an Edge that Doesn't Exist" << endl;
//    graph.deleteEdge(3, 2, 9);
//    cout << "Attempting to Delete an Edge but the Weights don't Match" << endl;
//    graph.deleteEdge(1, 2, 7);
//    cout << "Deleting the Root Edge of a Node [1,2]" << endl;
//    graph.deleteEdge(1, 2, 10);
//    graph.print();
//
//    cout << endl << "Graph 2 - Showing DFS and BFS" << endl;
//    AdjacencyListGraph graph2(8);
//    graph2.addEdge(0, 4, 5);
//    graph2.addEdge(1, 2, 5);
//    graph2.addEdge(1, 5, 5);
//    graph2.addEdge(2, 1, 5);
//    graph2.addEdge(2, 5, 5);
//    graph2.addEdge(2, 6, 5);
//    graph2.addEdge(3, 1, 5);
//    graph2.addEdge(3, 5, 5);
//    graph2.addEdge(3, 7, 5);
//    graph2.addEdge(5, 6, 5);
//    graph2.addEdge(6, 2, 5);
//    graph2.addEdge(6, 4, 5);
//    graph2.addEdge(7, 6, 5);
//
//    graph2.printPretty();
//
//    cout << endl << "BFS Searches - Ignoring Disconnects" << endl;
//    cout << "BFS at 5" << endl;
//    graph2.bfs(5);
//    //5 6 2 4 1
//    cout << endl << "BFS at 1" << endl;
//    graph2.bfs(1);
//    //1 2 5 6 4
//    cout << endl << "BFS at 3" << endl;
//    graph2.bfs(3);
//    //3 1 5 7 2 6 4
//    cout << endl << endl << "DFS Searches - Ignoring Disconnects" << endl;
//    cout << "DFS at 5" << endl;
//    graph2.dfs(5);
//    //5 6 2 1 4
//    cout << endl << "DFS at 1" << endl;
//    graph2.dfs(1);
//    //1 2 5 6 4
//    cout << endl << "DFS at 3" << endl;
//    graph2.dfs(3);
//    //3 1 2 5 6 4 7
//}
