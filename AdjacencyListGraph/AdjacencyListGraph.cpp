//Tiffany Abernathy - Implementation of Adjacency List Graph using Arrays
#include "AdjacencyListGraph.h"
#include <iostream>
using namespace std;

AdjacencyListGraph::AdjacencyListGraph(int iNumVertices) {
    if (iNumVertices <= 0) {
        cout << "Enter a Valid Number of Vertices" << endl;
    }
    else {
        //Set the num vertices associated with the graph
        numVerticies = iNumVertices;
        //Initialize the graph with that number of verticies
        adjList = new Node * [numVerticies];
        //Initialize each node with the name as the index to make things easier. 
        for (int i = 0; i < numVerticies; i++) {
            adjList[i] = new Node(i);
        }
    }
}
    
AdjacencyListGraph::~AdjacencyListGraph() {
    for (int i = 0; i < numVerticies; i++) {
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

void AdjacencyListGraph::addEdge(int start, int end, int weight) {
    if (start < 0 || start >= numVerticies || end < 0 || end >= numVerticies) {
        cout << "Invalid Edge" << endl;
        return;
    }
    //Create the new Edge
    Edge* newEdge = new Edge(adjList[end], weight);
    //Check if the starting node has the root set
    if(!adjList[start]->next){
        //If not set the root to the new Edge. 
        adjList[start]->next = newEdge;
    }
    //Check if the roots end node is greater than the new edges
    else if (adjList[start]->next->end->name > end) {
        //If so put the new node as root and new nodes next as old root. 
        newEdge->next = adjList[start]->next;
        adjList[start]->next = newEdge;
    }
    //Otherwise find the place in the list where the new Edge belongs. Keeping end nodes in order. 
    else {
        Edge* parent = adjList[start]->next;
        while (parent->next) {
            if (parent->next->end->name > end) {
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
void AdjacencyListGraph::deleteEdge(int start, int end, int weight) {
    Edge* parent = adjList[start]->next;
    //Confirm the root is not null and the inputted values are valid
    if (parent && start > 0 && start < numVerticies && end > 0 && end < numVerticies) {
        //The deleted edge is the root edge of the node
        if (parent->end->name == end && parent->weight == weight) {
            adjList[start]->next = parent->next;
            delete parent;
            return;
        }
        //Otherwise the deleted edge is elsewhere in the list of edges
        while (parent->next) {
            //The end nodes are in order and the next one is above the value therefore the deleted node doesn't exist
            if (parent->next->end->name > end)
                break;
            if (parent->next->end->name == end && parent->next->weight == weight) {
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
    for (int i = 0; i < numVerticies; i++)
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

int main()
{
    AdjacencyListGraph graph(5);
    cout << "Adding Edges: [1,2], [1,4], [1,3]" << endl;
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 4, 8);
    graph.addEdge(1, 3, 7);
    graph.print();
    cout << "Adding Edges: [2,2], [2,1]" << endl;
    graph.addEdge(2, 2, 4);
    graph.addEdge(2, 1, 5);
    graph.print();
    cout << "Deleting Edge: [1,4]" << endl;
    graph.deleteEdge(1, 3, 7);
    graph.print();
    cout << "Deleting an Edge that Doesn't Exist" << endl;
    graph.deleteEdge(3, 2, 9);
    cout << "Attempting to Delete an Edge but the Weights don't Match" << endl;
    graph.deleteEdge(1, 2, 7);
    cout << "Deleting the Root Edge of a Node [1,2]" << endl;
    graph.deleteEdge(1, 2, 10);
    graph.print();
}
