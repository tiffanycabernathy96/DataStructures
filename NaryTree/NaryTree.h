#pragma once
#include "Tree.h"
#include <vector>
using namespace std;

struct TreeNode {
	int data;
	vector<TreeNode> children;
	TreeNode(int iData);
	void addChild(int iData);
};

class NaryTree : public Tree {
	TreeNode* root;
public:
	NaryTree();
	~NaryTree();

	void insert(int iData);
	void remove(int iData);

	//DFS Traversals
	void printPreOrder(TreeNode* iNode);
	void printInOrder(TreeNode* iNode);
	void printPostOrder(TreeNode* iNode);

	//BFS Traversal
	void printLevelOrder(TreeNode* iNode);

	TreeNode* searchTree(int iData);

	void printTree();
};