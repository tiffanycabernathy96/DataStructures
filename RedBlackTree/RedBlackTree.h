#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

struct TreeNode {
	int data;
	bool color; 
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int iData, bool iColor);
};

class RedBlackTree: public Tree {
private:
	TreeNode* root;
	TreeNode* NIL;
	void deleteTree(TreeNode* node);

	void insertRebalance(TreeNode* node);
	void deleteRebalance(TreeNode* node);
	void replace(TreeNode* iOldN, TreeNode* iNewN);

	void leftRotate(TreeNode* iNode);
	void rightRotate(TreeNode* iNode);

	TreeNode* searchTreeR(TreeNode* iNode, int iData);
	void printR(TreeNode* iNode, string iIndent, bool iLast);
public:
	RedBlackTree();
	~RedBlackTree();

	TreeNode* getRoot();

	TreeNode* minimum(TreeNode* iNode);
	TreeNode* maximum(TreeNode* iNode);

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