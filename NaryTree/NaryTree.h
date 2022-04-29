#pragma once
#include "Tree.h"
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
	int data;
	vector<TreeNode> children;
	TreeNode(int iData);
	void addChild(int iData);
	void addChildren(vector<int>& iData);
};

class NaryTree {
	void printR(TreeNode* iNode, string iIndent);
public:
	TreeNode* root;
	NaryTree(int iData);
	~NaryTree();

	//DFS Traversals
	void printPreOrder(TreeNode* iNode);
	void printInOrder(TreeNode* iNode);
	void printPostOrder(TreeNode* iNode);

	//BFS Traversal
	void printLevelOrder(TreeNode* iNode);

	void printTree();
};