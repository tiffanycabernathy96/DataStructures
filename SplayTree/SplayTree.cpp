// Tiffany Abernathy - Splay Tree Implementation

#include "SplayTree.h"
#include <iostream>
#include <queue>
using namespace std;

TreeNode::TreeNode(int iData) {
    data = iData;
    left = nullptr;
    right = nullptr;
}

void SplayTree::insert(int iData) {

}

void SplayTree::remove(int iData) {

}

//DFS Traversals
void SplayTree::printPreOrder(TreeNode* iNode) {
    //Root - Left - Right
    if (iNode) {
        cout << iNode->data << " ";
        printPreOrder(iNode->left);
        printPreOrder(iNode->right);
    }
}

void SplayTree::printInOrder(TreeNode* iNode) {
    //Left - Root - Right
    if (iNode) {
        printInOrder(iNode->left);
        cout << iNode->data << " ";
        printInOrder(iNode->right);
    }
}

void SplayTree::printPostOrder(TreeNode* iNode) {
    //Left - Right - Root
    if (iNode) {
        printPostOrder(iNode->left);
        printPostOrder(iNode->right);
        cout << iNode->data << " ";
    }
}

//BFS Traversal
void SplayTree::printLevelOrder(TreeNode* iNode) {

}

TreeNode* SplayTree::searchTree(int iData) {
    TreeNode* node = nullptr;
    return node;
}

void SplayTree::printTree() {

}

int main()
{
    std::cout << "Coming Soon" << endl;
}
