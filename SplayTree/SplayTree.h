#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

struct TreeNode {
	int data;
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int iData);
};

class SplayTree : public Tree {
	TreeNode* root;
	void deleteTree(TreeNode* node);

	void splay(TreeNode* iNode);
	TreeNode* join(TreeNode* iLeftTree, TreeNode* iRightTree);

	void leftRotate(TreeNode* iNode);
	void rightRotate(TreeNode* iNode);

	TreeNode* searchTreeR(TreeNode* iNode, int iData);
	void printR(TreeNode* iNode, string iIndent, bool iLast);
public:
	SplayTree();
	~SplayTree();

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
