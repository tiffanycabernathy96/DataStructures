//Tiffany Abernathy - Interface for Tree Implementations
#pragma once

struct TreeNode;

class Tree {
	virtual void insert(int data) = 0;
	virtual void remove(int data) = 0;

	//DFS Traversals
	virtual void printPreOrder(TreeNode* node) = 0;
	virtual void printInOrder(TreeNode* node) = 0;
	virtual void printPostOrder(TreeNode* node) = 0;

	//BFS Traversal
	virtual void printLevelOrder(TreeNode* node) = 0;

	virtual TreeNode* searchTree(int data) = 0;

	virtual void printTree() = 0;
};