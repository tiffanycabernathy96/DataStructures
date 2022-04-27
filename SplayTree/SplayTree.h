#pragma once
#include "Tree.h"

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int iData);
};

class SplayTree : public Tree {
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
