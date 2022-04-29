// Tiffany Abernathy - n-ary Tree Implementation
// Implementation of BFS and DFS Traversals

#include "NaryTree.h"
#include <iostream>
#include <queue>
#include <list>
using namespace std;

TreeNode::TreeNode(int iData) {
    data = iData;
}

void TreeNode::addChild(int iData) {
    children.push_back(TreeNode(iData));
}

void TreeNode::addChildren(vector<int>& iData) {
	for (int i : iData) {
		children.push_back(TreeNode(i));
	}
}

//Private Functions
void NaryTree::printR(TreeNode* iNode, string iIndent) {
	if (iNode) {
		if (iNode->children.size() == 0) {
			cout << iIndent;
			cout << "L----";
		}
		else if (iIndent == "") {
			cout << iIndent;
			cout << "R----";
		}
		else {
			cout << iIndent;
			cout << "N----";
		}
		
		iIndent += "|  ";
		cout << "Data: " << iNode->data << endl;
		for (TreeNode child : iNode->children) {
			printR((&child), iIndent);
		}
	}
}

//Public Functions
NaryTree::NaryTree(int iData) {
    root = new TreeNode(iData);
}
NaryTree::~NaryTree() {
    delete root;
}

//DFS Traversals
void NaryTree::printPreOrder(TreeNode* iNode) {
    //Root - Left - Right
	if (iNode) {
		cout << iNode->data << " ";
		int i = 0;
		for (TreeNode node : iNode->children) {
			printPreOrder(&node);
			i++;
		}
	}
	return;
}

void NaryTree::printInOrder(TreeNode* iNode) {
    //Left - Root - Right
    if (iNode) {
        int total = iNode->children.size();

        for (int i = 0; i < (total - 1); i++) {
            printInOrder(&iNode->children[i]);
        }
        cout << iNode->data << " ";
		if(total != 0)
			printInOrder(&iNode->children[total - 1]);
    }
}

void NaryTree::printPostOrder(TreeNode* iNode) {
    //Left - Right - Root
	if (iNode) {
		list<int> result;
		list<TreeNode> stack;

		stack.push_back(*iNode);
		while (!stack.empty()) {
			TreeNode temp = stack.back();
			stack.pop_back();
			result.push_front(temp.data);

			for (TreeNode child : temp.children) {
				stack.push_back(child);
			}
		}
		for (int i : result) {
			cout << i << " ";
		}
	}
	return;
}

//BFS Traversal
void NaryTree::printLevelOrder(TreeNode* iNode) {
	vector<vector<int>> result;
	if (!iNode)
		return;
	queue<TreeNode> q;
	q.push(*iNode);
	while (!q.empty()) {
		int size = q.size();
		vector<int> level;
		while (size--) {
			TreeNode temp = q.front();
			level.push_back(temp.data);
			q.pop();
			for (TreeNode node : temp.children) {
				q.push(node);
			}
		}
		result.push_back(level);
	}
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
	}
}

void NaryTree::printTree() {
	if (this->root) {
		printR(this->root, "");
	}
}

int main()
{
    NaryTree *tree = new NaryTree(10);
	vector<int> children{ 8, 5 };
	tree->root->addChildren(children);
	children = { 2, 1, 6 };
	tree->root->children[0].addChildren(children);
	children = { 9, 11 };
	tree->root->children[0].children[1].addChildren(children);
	children = { 7, 8, 3, 4 };
	tree->root->children[1].addChildren(children);
	tree->root->children[1].children[0].addChild(-1);
	children = { 2, 1, 3 };
	tree->root->children[1].children[3].addChildren(children);
	tree->printTree();
	cout << "Pre Order: ";
	tree->printPreOrder(tree->root);

	cout << endl << "In Order: ";
	tree->printInOrder(tree->root);

	cout << endl << "Post Order: ";
	tree->printPostOrder(tree->root);

	cout << endl << "Level Order: ";
	tree->printLevelOrder(tree->root);

	NaryTree* tree2 = new NaryTree(1);
	children = { 3, 2, 4 };
	tree2->root->addChildren(children);
	tree2->root->children[0].addChild(5);
	tree2->root->children[0].addChild(6);

	cout << endl << endl << "Pre Order: ";
	tree2->printPreOrder(tree2->root);

	cout << endl << "In Order: ";
	tree2->printInOrder(tree2->root);

	cout << endl << "Post Order: ";
	tree2->printPostOrder(tree2->root);

	cout << endl << "Level Order: ";
	tree2->printLevelOrder(tree2->root);
	
	return 0;
}
