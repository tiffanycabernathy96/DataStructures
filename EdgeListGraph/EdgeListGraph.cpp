//Tiffany Abernathy - Implementation of Edge List Graph Using Arrays. Directed and Weighted. 
//Implementation of BFS and DFS - Works for Disconnected and Connected Graphs. Optional Input for Start Value

#include "EdgeListGraph.h"
#include <iostream>
#include <queue>;
using namespace std;

//Private Functions
void EdgeListGraph::deleteEdges(int iNode) {
	int numEdgesToDelete = 0;
	int currentIndex = 0;
	int* indexesToKeep = new int[numEdges];
	for (int i = 0; i < numEdges; i++) {
		if (edges[i]->start == iNode || edges[i]->end == iNode) {
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

void EdgeListGraph::bfsSearch(int iStart, bool* iVisited) {
	Node* nTemp = nodes[iStart];
	queue<Node*> que;
	iVisited[nTemp->name] = true;
	que.push(nTemp);
	while (!que.empty()) {
		nTemp = que.front();
		cout << nTemp->name << " ";
		que.pop();
		for (int j = 0; j < numEdges; j++) {
			if (!iVisited[edges[j]->end] && edges[j]->start == nTemp->name) {
				iVisited[edges[j]->end] = true;
				que.push(nodes[edges[j]->end]);
			}
		}
	}
}

void EdgeListGraph::dfsR(int iStart, bool* iVisited) {
	Node* nTemp = nodes[iStart];
	iVisited[iStart] = true;
	cout << iStart << " ";
	for (int i = 0; i < numEdges; i++) {
		if (!iVisited[edges[i]->end] && edges[i]->start == nodes[iStart]->name) {
			dfsR(edges[i]->end, iVisited);
		}
	}
}

//Public Functions
EdgeListGraph::EdgeListGraph(Node *iNodes, Edge *iEdges, int iNumNodes, int iNumEdges) {
	numVertices = iNumNodes;
	numEdges = iNumEdges;
	nodes = new Node * [numVertices]();
	edges = new Edge * [numEdges]();
	for (int i = 0; i < numVertices; i++) {
		nodes[i] = new Node(iNodes[i].name);
	}
	for (int i = 0; i < numEdges; i++) {
		edges[i] = new Edge(iEdges[i].start, iEdges[i].end, iEdges[i].weight);
	}
}

EdgeListGraph::~EdgeListGraph() {
	for (int i = 0; i < numVertices; i++)
		delete nodes[i];
	delete[] nodes;
	for (int i = 0; i < numEdges; i++) 
		delete edges[i];
	delete[] edges;
}

void EdgeListGraph::addNode(int iNode) {
	Node** tempNodes = new Node * [numVertices +1]();
	for (int i = 0; i < numVertices; i++) {
		tempNodes[i] = nodes[i];
	}
	tempNodes[numVertices] = new Node(iNode);
	numVertices++;
	delete[] nodes;
	nodes = tempNodes;
}

void EdgeListGraph::deleteNode(int iNode) {
	numVertices--;
	Node** tempNodes = new Node * [numVertices]();
	int index = 0;
	for (int i = 0; i < numVertices +1; i++) {
		if (nodes[i]->name != iNode) {
			tempNodes[index] = nodes[i];
			index++;
		}
		else
			delete nodes[i];
	}
	delete[] nodes;
	nodes = tempNodes;
	deleteEdges(iNode);
}

void EdgeListGraph::addEdge(Edge* iEdge) {
	Edge** tempEdges = new Edge * [numEdges + 1]();
	for (int i = 0; i < numEdges; i++) {
		tempEdges[i] = edges[i];
	}
	tempEdges[numEdges] = iEdge;
	numEdges++;
	delete[] edges;
	edges = tempEdges;
}

void EdgeListGraph::deleteEdge(Edge* iEdge) {
	numEdges--;
	Edge** tempEdges = new Edge * [numEdges]();
	int index = 0;
	for (int i = 0; i < numEdges+1; i++) {
		if (edges[i] != iEdge) {
			tempEdges[index] = edges[i];
			index++;
		}
		else
			delete edges[i];
	}
	delete[] edges;
	edges = tempEdges;
}

void EdgeListGraph::printByNodes() {
	cout << "Graph Edges by Node: " << endl;
	for (int i = 0; i < numVertices; i++) {
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

void EdgeListGraph::bfs(int iStart) {
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

void EdgeListGraph::dfs(int iStart) {
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

int main()
{
	cout << "Graph 1 - Showing Ability to Add Nodes/Edges" << endl;
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
	//cout << "Deleting Node 1 and corresponding Edges" << endl;
	//cout << "Edges before Deletion" << endl;
	//graph.print();
	//graph.deleteNode(1);
	//cout << "Edges after Deletion" << endl;
	//graph.print();

	cout << endl << "Graph 2 - Showing DFS and BFS" << endl;
	Node nodes2[] = { Node(0), Node(1), Node(2), Node(3), Node(4), Node(5), Node(6), Node(7)};
	Edge edges2[] = { Edge(0, 4, 5), Edge(1, 2, 10), Edge(1, 5, 6), Edge(2, 1, 8), Edge(2, 5, 1), Edge(2, 6, 10), Edge(3, 1, 10), Edge(3, 5, 10), Edge(3, 7, 10), Edge(5, 6, 10),
					  Edge(6, 2, 10) , Edge(6, 4, 10) , Edge(7, 6, 10) };
	EdgeListGraph graph2(nodes2, edges2, 8, 13);

	graph2.print();

	cout << endl << "BFS Searches - Ignoring Disconnects" << endl;
	cout << "BFS at 5" << endl;
	graph2.bfs(5);
	//5 6 2 4 1
	cout << endl << "BFS at 1" << endl;
	graph2.bfs(1);
	//1 2 5 6 4
	cout << endl << "BFS at 3" << endl;
	graph2.bfs(3);
	//3 1 5 7 2 6 4
	cout << endl << endl << "DFS Searches - Ignoring Disconnects" << endl;
	cout << "DFS at 5" << endl;
	graph2.dfs(5);
	//5 6 2 1 4
	cout << endl << "DFS at 1" << endl;
	graph2.dfs(1);
	//1 2 5 6 4
	cout << endl << "DFS at 3" << endl;
	graph2.dfs(3);
	//3 1 2 5 6 4 7
}