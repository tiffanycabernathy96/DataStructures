#pragma once
#include<iostream>
#include <queue>
using namespace std;
struct TreeNode {
	int data;
	bool color; 
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data, bool color);
};
class RedBlackTree {
private:
	TreeNode* root;
	void deleteTree(TreeNode* node);

	void insertRebalance(TreeNode* node);
	void deleteRebalance(TreeNode* node);
	void replace(TreeNode* oldN, TreeNode* newN);

	TreeNode* searchTreeR(TreeNode* node, int data);
	void printR(TreeNode* node, string indent, bool last);
public:
	RedBlackTree();
	~RedBlackTree();

	TreeNode* getRoot();

	TreeNode* minimum(TreeNode* node);
	TreeNode* maximum(TreeNode* node);

	void leftRotate(TreeNode* node);
	void rightRotate(TreeNode* node);
	void insert(int data);
	void remove(int data);

	//DFS Traversals
	void printPreOrder(TreeNode* node);
	void printInOrder(TreeNode* node);
	void printPostOrder(TreeNode* node);

	//BFS Traversal
	void printLevelOrder(TreeNode* node);

	TreeNode* searchTree(int data);
	void printTree();
	
};