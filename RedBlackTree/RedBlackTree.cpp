//Tiffany Abernathy - Red-Black Tree Implementation 
#include "RedBlackTree.h"
#include <iostream>
#include <queue>
using namespace std;

TreeNode::TreeNode(int data=NULL, bool color=false) {
    //All parameters are optional to make empty nodes easy to create. Defaults to false - black. 
    this->data = data;
    this->color = color; 
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}
//Private Functions
void RedBlackTree::deleteTree(TreeNode* node) {
    if (node != NIL) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}
void RedBlackTree::insertRebalance(TreeNode* node) {
    TreeNode* temp;
    while (node->parent->color) {
        if (node->parent == node->parent->parent->right) {
            temp = node->parent->parent->left;
            if (temp->color) {
                temp->color = false;
                node->parent->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = false;
                node->parent->parent->color = true;
                leftRotate(node->parent->parent);
            }
        }
        else {
            temp = node->parent->parent->right;
            if (temp->color) {
                temp->color = false;
                node->parent->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = false;
                node->parent->parent->color = true;
                rightRotate(node->parent->parent);
            }
        }
        if (node == this->root)
            break;
    }
    this->root->color = false;
}
void RedBlackTree::deleteRebalance(TreeNode* node) {
    TreeNode* temp;
    while (node != this->root && !node->color) {
        if (node == node->parent->left) {
            temp = node->parent->right;
            if (temp->color) {
                temp->color = false;
                node->parent->color = true;
                leftRotate(node->parent);
                temp = node->parent->right;
            }

            if (!temp->left->color && !temp->right->color) {
                temp->color = true;
                node = node->parent;
            }
            else {
                if (!temp->right->color) {
                    temp->left->color = false;
                    temp->color = true;
                    rightRotate(temp);
                    temp = node->parent->right;
                }
                temp->color = node->parent->color;
                node->parent->color = false;
                temp->right->color = false;
                leftRotate(node->parent);
                node = this->root;
            }
        }
        else {
            temp = node->parent->left;
            if (temp->color) {
                temp->color = false;
                node->parent->color = true;
                rightRotate(node->parent);
                temp = node->parent->left;
            }

            if (!temp->left->color && !temp->right->color) {
                temp->color = true;
                node = node->parent;
            }
            else {
                if (!temp->left->color) {
                    temp->right->color = false;
                    temp->color = true;
                    leftRotate(temp);
                    temp = node->parent->left;
                }

                temp->color = node->parent->color;
                node->parent->color = false;
                temp->left->color = false;
                rightRotate(node->parent);
                node = this->root;
            }
        }
    }
    node->color = false;
}
void RedBlackTree::replace(TreeNode* oldN, TreeNode* newN) {
    if (!oldN->parent)
        this->root = newN;
    else if (oldN == oldN->parent->left)
        oldN->parent->left = newN;
    else
        oldN->parent->right = newN;

    newN->parent = oldN->parent;
}
TreeNode* RedBlackTree::searchTreeR(TreeNode* node, int data) {
    if(node == NIL || data == node->data)
        return node;
    if (data < node->data)
        return searchTreeR(node->left, data);
    return searchTreeR(node->right, data);
}
void RedBlackTree::printR(TreeNode* node, string indent, bool last) {
    if (node != NIL) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        }
        else {
            cout << "L----";
            indent += "|  ";
        }
        cout << "Data: " << node->data << " - Color: " << (node->color ? "Red" : "False") << endl;
        printR(node->left, indent, false);
        printR(node->right, indent, true);
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
    return this->root;
}

TreeNode* RedBlackTree::minimum(TreeNode* node) {
    TreeNode* temp = node;
    while (temp->left != NIL) {
        temp = temp->left;
    }
    return temp;
}
TreeNode* RedBlackTree::maximum(TreeNode* node) {
    TreeNode* temp = node;
    while (temp->right != NIL) {
        temp = temp->right;
    }
    return temp;
}

void RedBlackTree::leftRotate(TreeNode* node) {
    //Take the right child of node
    TreeNode* rNode = node->right;
    //Set the right child of node to the left child of rNode
    node->right = rNode->left;

    //If rNodes left child is not null, set it's parent to node
    if (rNode->left != NIL)
        rNode->left->parent = node;
    //rNode is now in nodes old spot so set rNode to node's parent. 
    rNode->parent = node->parent;
    //If node was the root i.e. node->parent is null then set the root to rNode.
    if (!node->parent)
        this->root = rNode;
    //If node is his parent's left child, set node's parent's left child to rNode
    else if (node == node->parent->left)
        node->parent->left = rNode;
    //Otherwise set parent's right child rNode. 
    else
        node->parent->right = rNode;

    //Set rNode's left to node
    rNode->left = node;
    //Set node's parent to rNode
    node->parent = rNode;
}
void RedBlackTree::rightRotate(TreeNode* node) {
    //Take the left child of the node
    TreeNode* lNode = node->left;
    //Set the left child of node to the right child of lNode
    node->left = lNode->right;

    //lNode's right child is not null, set it's parent to node
    if (lNode->right != NIL)
        lNode->right->parent = node;
    //lNode is now in nodes old spot so set lNode to node's parent.
    lNode->parent = node->parent;
    //If node was the root i.e. node->parent is null then set the root to lNode.
    if (!node->parent)
        this->root = lNode;
    //If node is the right child of his parent, set the parent's right child to lNode 
    else if (node == node->parent->right)
        node->parent->right = lNode;
    //Otherwise set the paren't left child to lNode
    else
        node->parent->left = lNode;

    //Set lNode's right to node
    lNode->right = node;
    //Set node's parent to lNode
    node->parent = lNode;
}
void RedBlackTree::insert(int data) {
    //Create the new node with the data and it is red so true
    TreeNode* newNode = new TreeNode(data, true);
    newNode->left = NIL;
    newNode->right = NIL;
    //Place the new node in the tree where it should be based on value
    TreeNode* parentNode = nullptr;
    TreeNode* temp = this->root;

    while (temp != NIL) {
        parentNode = temp;
        if (data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    //Set the newNode's parent.
    newNode->parent = parentNode;
    //This is the first node so it becomes the root
    if (!parentNode) {
        this->root = newNode;
        //The Root must be black
        newNode->color = false;
        return;
    }
    //if data is less than the parentNode's data then make it the left child
    else if (data < parentNode->data)
        parentNode->left = newNode;
    //Otherwise parentNode's right is newNode
    else
        parentNode->right = newNode;

    //If this is the first child of the root then red-black tree rules are held up.
    if (!newNode->parent->parent)
        return;

    //Otherwise need to fix the tree
    insertRebalance(newNode);
}
void RedBlackTree::remove(int data) {
    TreeNode* removedN = NIL, *temp1, *temp2;

    //Find the node in the tree
    removedN = searchTreeR(this->root, data);

    //Confirm Node was found
    if (!removedN) {
        cout << "Node Not Found" << endl;
        return;
    }

    //Start process of removing/reconnecting nodes
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

    //Can safely delete the node now
    delete removedN;
    //Fix the tree is needed
    if (!temp1Color)
        deleteRebalance(temp2);
}

//DFS Traversals
void RedBlackTree::printPreOrder(TreeNode* node) {
    //Root - Left - Right
    if (node != NIL) {
        cout << node->data << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}
void RedBlackTree::printInOrder(TreeNode* node) {
    //Left - Root - Right
    if (node != NIL) {
        printInOrder(node->left);
        cout << node->data << " ";
        printInOrder(node->right);
    }
}
void RedBlackTree::printPostOrder(TreeNode* node) {
    //Left - Right - Root
    if (node != NIL) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->data << " ";
    }
}

//BFS Traversal
void RedBlackTree::printLevelOrder(TreeNode* node) {
    if (!node)
        return;
    queue<TreeNode*> q;
    q.push(node);
    while (q.empty() == false) {
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

TreeNode* RedBlackTree::searchTree(int data) {
    return searchTreeR(this->root, data);
}
void RedBlackTree::printTree() {
    if (this->root) {
        printR(this->root, "", true);
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
