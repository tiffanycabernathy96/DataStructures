// Tiffany Abernathy - n-ary Tree Implementation

#include "NaryTree.h"
#include <iostream>
#include <queue>
using namespace std;

TreeNode::TreeNode(int iData) {
    data = iData;
}

void TreeNode::addChild(int iData) {
    children.push_back(TreeNode(iData));
}

NaryTree::NaryTree() {

}
NaryTree::~NaryTree() {
    delete root;
}

void NaryTree::insert(int iData) {

}

void NaryTree::remove(int iData) {

}

//DFS Traversals
void NaryTree::printPreOrder(TreeNode* iNode) {
    //Root - Left - Right
}

void NaryTree::printInOrder(TreeNode* iNode) {
    //Left - Root - Right
}

void NaryTree::printPostOrder(TreeNode* iNode) {
    //Left - Right - Root
}

//BFS Traversal
void NaryTree::printLevelOrder(TreeNode* iNode) {

}

TreeNode* NaryTree::searchTree(int iData) {
    TreeNode* node = nullptr;
    return node;
}

void NaryTree::printTree() {

}

int main()
{
    std::cout << "Coming Soon" << endl;
}
