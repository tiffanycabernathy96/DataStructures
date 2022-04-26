//Tiffany Abernathy - Implementation of Edge List Graph Using Vectors. Directed and Weighted. 
//Implementation of BFS and DFS - Works for Disconnected and Connected Graphs. Optional Input for Start Value

#include "EdgeListGraphVectors.h"
#include <iostream>
#include <queue>

//Private Functions
void EdgeListGraphVectors::deleteEdges(int iNode) {
	auto itr = edges.begin();
	while (itr != edges.end()) {
		if ((*itr).start == iNode || (*itr).end == iNode) {
			itr = edges.erase(itr);
		}
		else
			itr++;
	}
}

void EdgeListGraphVectors::bfsSearch(int iStart, vector<bool>& iVisited) {
	Node nTemp = nodes[iStart];
	vector<int> que;
	iVisited[nTemp.name] = true;
	que.push_back(nTemp.name);
	while (!que.empty()) {
		nTemp = que.front();
		cout << nTemp.name << " ";
		que.erase(que.begin());
		for (int j = 0; j < edges.size(); j++) {
			if (!iVisited[edges[j].end] && edges[j].start == nTemp.name) {
				iVisited[edges[j].end] = true;
				que.push_back(edges[j].end);
			}
		}
	}
}

void EdgeListGraphVectors::dfsR(int iStart, vector<bool>& iVisited) {
	Node nTemp = nodes[iStart];
	iVisited[iStart] = true;
	cout << iStart << " ";
	for (int i = 0; i < edges.size(); i++) {
		if (!iVisited[edges[i].end] && edges[i].start == nodes[iStart].name) {
			dfsR(edges[i].end, iVisited);
		}
	}
}

//Public functions
EdgeListGraphVectors::EdgeListGraphVectors(vector<Node>& iNodes, vector<Edge>& iEdges) {
	nodes = vector<Node>();
	edges = vector<Edge>();
	for (int i = 0; i < iNodes.size(); i++) {
		nodes.push_back(Node(iNodes[i].name));
	}
	for (int i = 0; i < iEdges.size(); i++) {
		edges.push_back(Edge(iEdges[i].start, iEdges[i].end, iEdges[i].weight));
	}
}

EdgeListGraphVectors::~EdgeListGraphVectors() {
	//Using Vectors Handles this.
}

void EdgeListGraphVectors::addNode(int iNode) {
	nodes.push_back(Node(iNode));
}

void EdgeListGraphVectors::deleteNode(int iNode) {
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i].name == iNode) {
			swap(nodes[i], nodes[nodes.size()-1]);
			nodes.pop_back();
		}
	}
	deleteEdges(iNode);
}

void EdgeListGraphVectors::addEdge(Edge iEdge) {
	edges.push_back(Edge(iEdge.start, iEdge.end, iEdge.weight));
}

void EdgeListGraphVectors::deleteEdge(Edge iEdge) {
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == iEdge) {
			swap(nodes[i], nodes[nodes.size() - 1]);
			nodes.pop_back();
			return;
		}
	}
}

void EdgeListGraphVectors::printByNodes() {
	cout << "Graph Edges by Node: " << endl;
	for (int i = 0; i < nodes.size(); i++) {
		cout << "Edges from Node " << nodes[i].name << endl;
		for (int j = 0; j < edges.size(); j++) {
			if (edges[j].start == nodes[i].name)
				cout << "Start: " << edges[j].start << " End: " << edges[j].end << " Weight: " << edges[j].weight << endl;
		}
	}
}

void EdgeListGraphVectors::print() {
	cout << "Graph Edges: " << endl;
	for (int i = 0; i < edges.size(); i++) {
		cout << "Start: " << edges[i].start << " End: " << edges[i].end << " Weight: " << edges[i].weight << endl;
	}
	cout << endl;
}

void EdgeListGraphVectors::bfs(int iStart) {
	//Vector for Visited Nodes
	vector<bool> visited = vector<bool>(nodes.size(), false);

	if (iStart != -1) {
		//Perform BFS on the given start node
		bfsSearch(iStart, visited);
	}
	else {
		//Perform BFS - Handles Disconnected Graph
		//Go through all nodes in case of disconnected graph
		for (int i = 0; i < nodes.size(); i++) {
			if (!visited[i])
				bfsSearch(i, visited);
		}
	}
}

void EdgeListGraphVectors::dfs(int iStart) {
	//Vector for Visited Nodes
	vector<bool> visited = vector<bool>(nodes.size(), false);

	if (iStart != -1) {
		//Perform DFS on the given start node
		dfsR(iStart, visited);
	}
	else {
		//Perform DFS - Handles Disconnected Graph
		//Go through all nodes in case of disconnected graph
		for (int i = 0; i < nodes.size(); i++) {
			if (!visited[i])
				dfsR(i, visited);
		}
	}
}

//int main()
//{
//	cout << "Adding Nodes 0 through 4" << endl;
//	vector<Node> nodes{ Node(0), Node(1), Node(2), Node(3), Node(4) };
//	cout << "Adding Starting Edges" << endl;
//	vector<Edge> edges{ Edge(0, 1, 5), Edge(1, 3, 10), Edge(1, 0, 6), Edge(2, 4, 8), Edge(3, 2, 1) };
//	EdgeListGraphVectors graph(nodes, edges);
//	graph.printByNodes();
//	cout << "Adding Node 5" << endl;
//	graph.addNode(5);
//	graph.printByNodes();
//	cout << "Adding Edge 5, 2 with weight 7" << endl;
//	graph.addEdge(Edge(5, 2, 7));
//	graph.printByNodes();
//	//cout << "Deleting Node 1 and corresponding Edges" << endl;
//	//cout << "Edges before Deletion" << endl;
//	//graph.print();
//	//graph.deleteNode(1);
//	//cout << "Edges after Deletion" << endl;
//	//graph.print();
//
//	cout << endl << "Graph 2 - Showing DFS and BFS" << endl;
//	vector<Node> nodes2{ Node(0), Node(1), Node(2), Node(3), Node(4), Node(5), Node(6), Node(7) };
//	vector<Edge> edges2{ Edge(0, 4, 5), Edge(1, 2, 10), Edge(1, 5, 6), Edge(2, 1, 8), Edge(2, 5, 1), Edge(2, 6, 10), Edge(3, 1, 10), Edge(3, 5, 10), Edge(3, 7, 10), Edge(5, 6, 10),
//					  Edge(6, 2, 10) , Edge(6, 4, 10) , Edge(7, 6, 10) };
//	EdgeListGraphVectors graph2(nodes2, edges2);
//
//	graph2.print();
//
//	cout << endl << "BFS Searches - Ignoring Disconnects" << endl;
//	cout << "BFS at 5" << endl;
//	graph2.bfs(5);
//	//5 6 2 4 1
//	cout << endl << "BFS at 1" << endl;
//	graph2.bfs(1);
//	//1 2 5 6 4
//	cout << endl << "BFS at 3" << endl;
//	graph2.bfs(3);
//	//3 1 5 7 2 6 4
//	cout << endl << endl << "DFS Searches - Ignoring Disconnects" << endl;
//	cout << "DFS at 5" << endl;
//	graph2.dfs(5);
//	//5 6 2 1 4
//	cout << endl << "DFS at 1" << endl;
//	graph2.dfs(1);
//	//1 2 5 6 4
//	cout << endl << "DFS at 3" << endl;
//	graph2.dfs(3);
//	//3 1 2 5 6 4 7
//}
