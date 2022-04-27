#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

struct TreeNode {
	int data;
	int height;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int iData);
};

class AVLTree : public Tree {
	TreeNode* root;

	int height(TreeNode* iNode);
	int max(TreeNode* iNode);
	int calcBalanceFactor(TreeNode* iNode);

	TreeNode* insertR(TreeNode* iNode, int iData);
	TreeNode* removeR(TreeNode* iNode, int iData);
	void deleteTree(TreeNode* iNode);

	TreeNode* leftRotate(TreeNode* iNode);
	TreeNode* rightRotate(TreeNode* iNode);

	void printR(TreeNode* iNode, string iIndent, bool iLast);
public:
	AVLTree();
	~AVLTree();

	TreeNode* getRoot();
	
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