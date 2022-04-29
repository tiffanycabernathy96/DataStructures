// Tiffany Abernathy - Red-Black Tree Implementation 
// Implementation of BFS and DFS Traversals

#include "RedBlackTree.h"
#include <iostream>
#include <queue>
using namespace std;

TreeNode::TreeNode(int iData=NULL, bool iColor=false) {
    //All parameters are optional to make empty iNodes easy to create. Defaults to false - black. 
    this->data = iData;
    this->color = iColor; 
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

//Private Functions
void RedBlackTree::deleteTree(TreeNode* iNode) {
    if (iNode != NIL) {
        deleteTree(iNode->left);
        deleteTree(iNode->right);
        delete iNode;
    }
}

void RedBlackTree::insertRebalance(TreeNode* iNode) {
    TreeNode* temp;
    while (iNode->parent->color) {
        if (iNode->parent == iNode->parent->parent->right) {
            temp = iNode->parent->parent->left;
            if (temp->color) {
                temp->color = false;
                iNode->parent->color = false;
                iNode->parent->parent->color = true;
                iNode = iNode->parent->parent;
            }
            else {
                if (iNode == iNode->parent->left) {
                    iNode = iNode->parent;
                    rightRotate(iNode);
                }
                iNode->parent->color = false;
                iNode->parent->parent->color = true;
                leftRotate(iNode->parent->parent);
            }
        }
        else {
            temp = iNode->parent->parent->right;
            if (temp->color) {
                temp->color = false;
                iNode->parent->color = false;
                iNode->parent->parent->color = true;
                iNode = iNode->parent->parent;
            }
            else {
                if (iNode == iNode->parent->right) {
                    iNode = iNode->parent;
                    leftRotate(iNode);
                }
                iNode->parent->color = false;
                iNode->parent->parent->color = true;
                rightRotate(iNode->parent->parent);
            }
        }
        if (iNode == this->root)
            break;
    }
    this->root->color = false;
}

void RedBlackTree::deleteRebalance(TreeNode* iNode) {
    TreeNode* temp;
    while (iNode != this->root && !iNode->color) {
        if (iNode == iNode->parent->left) {
            temp = iNode->parent->right;
            if (temp->color) {
                temp->color = false;
                iNode->parent->color = true;
                leftRotate(iNode->parent);
                temp = iNode->parent->right;
            }

            if (!temp->left->color && !temp->right->color) {
                temp->color = true;
                iNode = iNode->parent;
            }
            else {
                if (!temp->right->color) {
                    temp->left->color = false;
                    temp->color = true;
                    rightRotate(temp);
                    temp = iNode->parent->right;
                }
                temp->color = iNode->parent->color;
                iNode->parent->color = false;
                temp->right->color = false;
                leftRotate(iNode->parent);
                iNode = this->root;
            }
        }
        else {
            temp = iNode->parent->left;
            if (temp->color) {
                temp->color = false;
                iNode->parent->color = true;
                rightRotate(iNode->parent);
                temp = iNode->parent->left;
            }

            if (!temp->left->color && !temp->right->color) {
                temp->color = true;
                iNode = iNode->parent;
            }
            else {
                if (!temp->left->color) {
                    temp->right->color = false;
                    temp->color = true;
                    leftRotate(temp);
                    temp = iNode->parent->left;
                }

                temp->color = iNode->parent->color;
                iNode->parent->color = false;
                temp->left->color = false;
                rightRotate(iNode->parent);
                iNode = this->root;
            }
        }
    }
    iNode->color = false;
}

void RedBlackTree::replace(TreeNode* iOldN, TreeNode* iNewN) {
    if (!iOldN->parent)
        root = iNewN;
    else if (iOldN == iOldN->parent->left)
        iOldN->parent->left = iNewN;
    else
        iOldN->parent->right = iNewN;

    iNewN->parent = iOldN->parent;
}

void RedBlackTree::leftRotate(TreeNode* iNode) {
    //Take the right child of iNode
    TreeNode* riNode = iNode->right;
    //Set the right child of iNode to the left child of riNode
    iNode->right = riNode->left;

    //If riNodes left child is not null, set it's parent to iNode
    if (riNode->left != NIL)
        riNode->left->parent = iNode;
    //riNode is now in iNodes old spot so set riNode to iNode's parent. 
    riNode->parent = iNode->parent;
    //If iNode was the root i.e. iNode->parent is null then set the root to riNode.
    if (!iNode->parent)
        this->root = riNode;
    //If iNode is his parent's left child, set iNode's parent's left child to riNode
    else if (iNode == iNode->parent->left)
        iNode->parent->left = riNode;
    //Otherwise set parent's right child riNode. 
    else
        iNode->parent->right = riNode;

    //Set riNode's left to iNode
    riNode->left = iNode;
    //Set iNode's parent to riNode
    iNode->parent = riNode;
}

void RedBlackTree::rightRotate(TreeNode* iNode) {
    //Take the left child of the iNode
    TreeNode* lNode = iNode->left;
    //Set the left child of iNode to the right child of liNode
    iNode->left = lNode->right;

    //liNode's right child is not null, set it's parent to iNode
    if (lNode->right != NIL)
        lNode->right->parent = iNode;
    //liNode is now in iNodes old spot so set liNode to iNode's parent.
    lNode->parent = iNode->parent;
    //If iNode was the root i.e. iNode->parent is null then set the root to liNode.
    if (!iNode->parent)
        this->root = lNode;
    //If iNode is the right child of his parent, set the parent's right child to liNode 
    else if (iNode == iNode->parent->right)
        iNode->parent->right = lNode;
    //Otherwise set the paren't left child to liNode
    else
        iNode->parent->left = lNode;

    //Set liNode's right to iNode
    lNode->right = iNode;
    //Set iNode's parent to liNode
    iNode->parent = lNode;
}

TreeNode* RedBlackTree::searchTreeR(TreeNode* iNode, int iData) {
    if(iNode == NIL || iData == iNode->data)
        return iNode;
    if (iData < iNode->data)
        return searchTreeR(iNode->left, iData);
    return searchTreeR(iNode->right, iData);
}

void RedBlackTree::printR(TreeNode* iNode, string iIndent, bool iLast) {
    if (iNode != NIL) {
        cout << iIndent;
        if (iLast) {
            cout << "R----";
            iIndent += "   ";
        }
        else {
            cout << "L----";
            iIndent += "|  ";
        }
        cout << "Data: " << iNode->data << " - Color: " << (iNode->color ? "Red" : "False") << endl;
        printR(iNode->left, iIndent, false);
        printR(iNode->right, iIndent, true);
    }
}


//Public Functions
RedBlackTree::RedBlackTree() {
    NIL = new TreeNode();
    root = NIL;
}

RedBlackTree::~RedBlackTree() {
    deleteTree(root);
}

TreeNode* RedBlackTree::getRoot() {
    return root;
}

TreeNode* RedBlackTree::minimum(TreeNode* iNode) {
    TreeNode* temp = iNode;
    while (temp->left != NIL) {
        temp = temp->left;
    }
    return temp;
}

TreeNode* RedBlackTree::maximum(TreeNode* iNode) {
    TreeNode* temp = iNode;
    while (temp->right != NIL) {
        temp = temp->right;
    }
    return temp;
}

void RedBlackTree::insert(int iData) {
    //Create the new iNode with the data and it is red so true
    TreeNode* newNode = new TreeNode(iData, true);
    newNode->left = NIL;
    newNode->right = NIL;
    //Place the new iNode in the tree where it should be based on value
    TreeNode* parentNode = nullptr;
    TreeNode* temp = this->root;

    while (temp != NIL) {
        parentNode = temp;
        if (iData < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    //Set the newiNode's parent.
    newNode->parent = parentNode;
    //This is the first iNode so it becomes the root
    if (!parentNode) {
        this->root = newNode;
        //The Root must be black
        newNode->color = false;
        return;
    }
    //if data is less than the parentiNode's data then make it the left child
    else if (iData < parentNode->data)
        parentNode->left = newNode;
    //Otherwise parentiNode's right is newiNode
    else
        parentNode->right = newNode;

    //If this is the first child of the root then red-black tree rules are held up.
    if (!newNode->parent->parent)
        return;

    //Otherwise need to fix the tree
    insertRebalance(newNode);
}

void RedBlackTree::remove(int iData) {
    TreeNode* removedN = NIL, *temp1, *temp2;

    //Find the iNode in the tree
    removedN = searchTreeR(this->root, iData);

    //Confirm iNode was found
    if (!removedN) {
        cout << "iNode Not Found" << endl;
        return;
    }

    //Start process of removing/reconnecting iNodes
    temp1 = removedN;
    bool temp1Color = temp1->color;

    //There is only a right child or no children
    if (removedN->left == NIL) {
        temp2 = removedN->right;
        replace(removedN, removedN->right);
    }
    //There is only a left child
    else if (removedN->right == NIL) {
        temp2 = removedN->left;
        replace(removedN, removedN->left);
    }
    //There is a right and left child
    else {
        temp1 = maximum(removedN->left);
        temp1Color = temp1->color;
        temp2 = temp1->right;
        if (temp1->parent == removedN)
            temp2->parent = temp1;
        else {
            replace(temp1, temp1->right);
            temp1->right = removedN->right;
            temp1->right->parent = temp1;
        }
        replace(removedN, temp1);
        temp1->left = removedN->left;
        temp1->left->parent = temp1;
        temp1->color = removedN->color;
    }

    //Can safely delete the iNode now
    delete removedN;
    //Fix the tree is needed
    if (!temp1Color)
        deleteRebalance(temp2);
}

//DFS Traversals
void RedBlackTree::printPreOrder(TreeNode* iNode) {
    //Root - Left - Right
    if (iNode != NIL) {
        cout << iNode->data << " ";
        printPreOrder(iNode->left);
        printPreOrder(iNode->right);
    }
}

void RedBlackTree::printInOrder(TreeNode* iNode) {
    //Left - Root - Right
    if (iNode != NIL) {
        printInOrder(iNode->left);
        cout << iNode->data << " ";
        printInOrder(iNode->right);
    }
}

void RedBlackTree::printPostOrder(TreeNode* iNode) {
    //Left - Right - Root
    if (iNode != NIL) {
        printPostOrder(iNode->left);
        printPostOrder(iNode->right);
        cout << iNode->data << " ";
    }
}

//BFS Traversal
void RedBlackTree::printLevelOrder(TreeNode* iNode) {
    if (!iNode)
        return;
    queue<TreeNode*> q;
    q.push(iNode);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left != NIL) {
            q.push(temp->left);
        }
        if (temp->right != NIL) {
            q.push(temp->right);
        }
    }
}

TreeNode* RedBlackTree::searchTree(int iData) {
    return searchTreeR(this->root, iData);
}

void RedBlackTree::printTree() {
    if (root) {
        printR(root, "", true);
    }
}

int main()
{
    RedBlackTree tree;
    
    cout << "Inserting 55" << endl;
    tree.insert(55);
    tree.printTree();

    cout << "Inserting 60, 2 and 10" << endl;
    tree.insert(60);
    tree.insert(2);
    tree.insert(10);
    tree.printTree();

    cout << "Removing 55" << endl;
    tree.remove(55);
    tree.printTree();

    cout << "Inserting 62, 63, 80, 1" << endl;
    tree.insert(62);
    tree.insert(63);
    tree.insert(80);
    tree.insert(1);
    tree.printTree();

    cout << "Level Order: ";
    tree.printLevelOrder(tree.getRoot());
    cout << endl;
    cout << "In Order: ";
    tree.printInOrder(tree.getRoot());
    cout << endl;
    cout << "Pre Order: ";
    tree.printPreOrder(tree.getRoot());
    cout << endl;
    cout << "Post Order: ";
    tree.printPostOrder(tree.getRoot());
    cout << endl;
}
