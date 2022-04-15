//Tiffany Abernathy - Implementation of Edge List Graph Using Arrays. Directed and Weighted. 
#include "EdgeListGraph.h"
#include <iostream>
using namespace std;

EdgeListGraph::EdgeListGraph(Node *iNodes, Edge *iEdges, int iNumNodes, int iNumEdges) {
	numNodes = iNumNodes;
	numEdges = iNumEdges;
	nodes = new Node * [numNodes]();
	edges = new Edge * [numEdges]();
	for (int i = 0; i < numNodes; i++) {
		nodes[i] = new Node(iNodes[i].name);
	}
	for (int i = 0; i < numEdges; i++) {
		edges[i] = new Edge(iEdges[i].start, iEdges[i].end, iEdges[i].weight);
	}
}
EdgeListGraph::~EdgeListGraph() {
	for (int i = 0; i < numNodes; i++)
		delete nodes[i];
	delete[] nodes;
	for (int i = 0; i < numEdges; i++) 
		delete edges[i];
	delete[] edges;
}

void EdgeListGraph::addNode(int node) {
	Node** tempNodes = new Node * [numNodes+1]();
	for (int i = 0; i < numNodes; i++) {
		tempNodes[i] = nodes[i];
	}
	tempNodes[numNodes] = new Node(node);
	numNodes++;
	delete[] nodes;
	nodes = tempNodes;
}
void EdgeListGraph::deleteNode(int node) {
	numNodes--;
	Node** tempNodes = new Node * [numNodes]();
	int index = 0;
	for (int i = 0; i < numNodes+1; i++) {
		if (nodes[i]->name != node) {
			tempNodes[index] = nodes[i];
			index++;
		}
		else
			delete nodes[i];
	}
	delete[] nodes;
	nodes = tempNodes;
	deleteEdges(node);
}

void EdgeListGraph::addEdge(Edge* edge) {
	Edge** tempEdges = new Edge * [numEdges + 1]();
	for (int i = 0; i < numEdges; i++) {
		tempEdges[i] = edges[i];
	}
	tempEdges[numEdges] = edge;
	numEdges++;
	delete[] edges;
	edges = tempEdges;
}
void EdgeListGraph::deleteEdge(Edge* edge) {
	numEdges--;
	Edge** tempEdges = new Edge * [numEdges]();
	int index = 0;
	for (int i = 0; i < numEdges+1; i++) {
		if (edges[i] != edge) {
			tempEdges[index] = edges[i];
			index++;
		}
		else
			delete edges[i];
	}
	delete[] edges;
	edges = tempEdges;
}
void EdgeListGraph::deleteEdges(int node) {
	int numEdgesToDelete = 0;
	int currentIndex = 0;
	int* indexesToKeep = new int[numEdges];
	for (int i = 0; i < numEdges; i++) {
		if (edges[i]->start == node || edges[i]->end == node) {
			numEdgesToDelete++;
			delete edges[i];
		}
		else {
			indexesToKeep[currentIndex] = i;
			currentIndex++;
		}
	}
	int newNumEdges = numEdges - numEdgesToDelete;
	Edge** tempEdges = new Edge * [newNumEdges];
	for (int i = 0; i < currentIndex; i++) {
		tempEdges[i] = edges[indexesToKeep[i]];
	}
	numEdges = newNumEdges;
	delete[] edges;
	edges = tempEdges;
}

void EdgeListGraph::printByNodes() {
	cout << "Graph Edges by Node: " << endl;
	for (int i = 0; i < numNodes; i++) {
		cout << "Edges from Node " << nodes[i]->name << endl;
		for (int j = 0; j < numEdges; j++) {
			if (edges[j]->start == nodes[i]->name)
				cout << "Start: " << edges[j]->start << " End: " << edges[j]->end << " Weight: " << edges[j]->weight << endl;
		}
	}
}

void EdgeListGraph::print() {
	cout << "Graph Edges: " << endl;
	for (int i = 0; i < numEdges; i++) {
		cout << "Start: " << edges[i]->start << " End: " << edges[i]->end << " Weight: " << edges[i]->weight << endl;
	}
	cout << endl;
}

/*int main()
{
	cout << "Adding Nodes 0 through 4" << endl;
	Node nodes[] = { Node(0), Node(1), Node(2), Node(3), Node(4) };
	cout << "Adding Starting Edges" << endl;
	Edge edges[] = { Edge(0, 1, 5), Edge(1, 3, 10), Edge(1, 0, 6), Edge(2, 4, 8), Edge(3, 2, 1) };
	EdgeListGraph graph(nodes, edges, 5, 5);
	graph.printByNodes();
	cout << "Adding Node 5" << endl;
	graph.addNode(5);
	graph.printByNodes();
	cout << "Adding Edge 5, 2 with weight 7" << endl;
	graph.addEdge(new Edge(5, 2, 7));
	graph.printByNodes();
	cout << "Deleting Node 1 and corresponding Edges" << endl;
	cout << "Edges before Deletion" << endl;
	graph.print();
	graph.deleteNode(1);
	cout << "Edges after Deletion" << endl;
	graph.print();
}*/