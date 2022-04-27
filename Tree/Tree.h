//Tiffany Abernathy - Interface for Tree Implementations
#pragma once

struct TreeNode;

class Tree {
	virtual void insert(int iData) = 0;
	virtual void remove(int iData) = 0;

	//DFS Traversals
	virtual void printPreOrder(TreeNode* iNode) = 0;
	virtual void printInOrder(TreeNode* iNode) = 0;
	virtual void printPostOrder(TreeNode* iNode) = 0;

	//BFS Traversal
	virtual void printLevelOrder(TreeNode* iNode) = 0;

	virtual TreeNode* searchTree(int iData) = 0;

	virtual void printTree() = 0;
};