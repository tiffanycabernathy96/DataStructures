//Tiffany Abernathy - AVL Tree Implementation
//Implementation of BFS and DFS Traversals

#include "AVLTree.h"
#include <queue>
using namespace std;

TreeNode::TreeNode(int iData = NULL) {
    //All parameters are optional to make empty iNodes easy to create. Defaults to false - black. 
    data = iData;
    height = 1;
    left = nullptr;
    right = nullptr;
}

//Private Functions
int AVLTree::height(TreeNode* iNode) {
    if (!iNode)
        return 0;
    return iNode->height;
}

int AVLTree::max(TreeNode* iNode) {
    int lHeight = height(iNode->left);
    int rHeight = height(iNode->right);
    return (lHeight > rHeight) ? lHeight : rHeight;
}

int AVLTree::calcBalanceFactor(TreeNode* iNode) {
    if (!iNode)
        return 0;
    return height(iNode->left) - height(iNode->right);
}

TreeNode* AVLTree::insertR(TreeNode* iNode, int iData) {
    //Find where the new node needs to go
    if (!iNode)
        return new TreeNode(iData);
    if (iNode->data > iData)
        iNode->left = insertR(iNode->left, iData);
    else if (iNode->data < iData)
        iNode->right = insertR(iNode->right, iData);
    else
        return iNode;

    //Balance the Tree
    iNode->height = (1 + max(iNode));
    int balanceFactor = calcBalanceFactor(iNode);
    if (balanceFactor > 1) {
        if (iNode->left->data > iData)
            return rightRotate(iNode);
        else if (iNode->left->data < iData) {
            iNode->left = leftRotate(iNode->left);
            return rightRotate(iNode);
        }
    }
    if (balanceFactor < -1) {
        if (iNode->right->data > iData) {
            iNode->right = rightRotate(iNode->right);
            return leftRotate(iNode);
        }
        else if (iNode->right->data < iData)
            return leftRotate(iNode);
    }
    return iNode;
}

TreeNode* AVLTree::removeR(TreeNode* iNode, int iData) {
    //Find the node that needs to be deleted
    if (!iNode)
        return iNode;
    if (iNode->data > iData)
        iNode->left = removeR(iNode->left, iData);
    else if (iNode->data < iData)
        iNode->right = removeR(iNode->right, iData);
    else {
        if ((!iNode->left) || (!iNode->right)) {
            TreeNode* temp = iNode->left ? iNode->left : iNode->right;
            if (!temp) {
                temp = iNode;
                iNode = nullptr;
            }
            else 
                *iNode = *temp;
        }
        else {
            //Get the Highest Value of the Left Subtree
            TreeNode* temp = iNode->left;
            while (temp->right)
                temp = temp->right;
            iNode->data = temp->data;
            iNode->left = removeR(iNode->left, temp->data);
        }
    }

    if (!iNode)
        return iNode;

    //Balance the Tree
    iNode->height = (1 + max(iNode));
    int balanceFactor = calcBalanceFactor(iNode);
    if (balanceFactor > 1) {
        if (calcBalanceFactor(iNode->left) >= 0)
            return rightRotate(iNode);
        else {
            iNode->left = leftRotate(iNode->left);
            return rightRotate(iNode);
        }
    }
    if (balanceFactor < -1) {
        if (calcBalanceFactor(iNode->right) <= 0)
            return leftRotate(iNode);
        else {
            iNode->right = rightRotate(iNode->right);
            return leftRotate(iNode);
        }
    }
    return iNode;
}

void AVLTree::deleteTree(TreeNode* iNode) {
    if (iNode) {
        deleteTree(iNode->left);
        deleteTree(iNode->right);
        delete iNode;
    }
}

TreeNode* AVLTree::leftRotate(TreeNode* iNode) {
    //Take the right child of iNode
    TreeNode* rNode = iNode->right;
    //Take the left child of iNode's right child.
    TreeNode* gNode = rNode->left;

    //Rotate the Nodes
    rNode->left = iNode;
    iNode->right = gNode;

    //Reset the Heights
    iNode->height = (1 + max(iNode));
    rNode->height = (1 + max(rNode));

    return rNode;
}

TreeNode* AVLTree::rightRotate(TreeNode* iNode) {
    ////Take the left child of the iNode
    TreeNode* lNode = iNode->left;
    //Take the right child of iNode's left child.
    TreeNode* gNode = lNode->right;

    //Rotate the Nodes
    lNode->right = iNode;
    iNode->left = gNode;

    //Reset the Heights
    iNode->height = (1 + max(iNode));
    lNode->height = (1 + max(lNode));

    return lNode;
}

void AVLTree::printR(TreeNode* iNode, string iIndent, bool iLast) {
    if (iNode) {
        cout << iIndent;
        if (iLast) {
            cout << "R----";
            iIndent += "   ";
        }
        else {
            cout << "L----";
            iIndent += "|  ";
        }
        cout << "Data: " << iNode->data << endl;
        printR(iNode->left, iIndent, false);
        printR(iNode->right, iIndent, true);
    }
}

//Public Function
AVLTree::AVLTree() {
    root = nullptr;
}
AVLTree::~AVLTree() {
    deleteTree(root);
}

TreeNode* AVLTree::getRoot() {
    return root;
}

void AVLTree::insert(int iData) {
    root = insertR(root, iData);
}
void AVLTree::remove(int iData) {
    root = removeR(root, iData);
}

//DFS Traversals
void AVLTree::printPreOrder(TreeNode* iNode) {
    //Root - Left - Right
    if (iNode) {
        cout << iNode->data << " ";
        printPreOrder(iNode->left);
        printPreOrder(iNode->right);
    }
}
void AVLTree::printInOrder(TreeNode* iNode) {
    //Left - Root - Right
    if (iNode) {
        printInOrder(iNode->left);
        cout << iNode->data << " ";
        printInOrder(iNode->right);
    }
}
void AVLTree::printPostOrder(TreeNode* iNode) {
    //Left - Right - Root
    if (iNode) {
        printPostOrder(iNode->left);
        printPostOrder(iNode->right);
        cout << iNode->data << " ";
    }
}

//BFS Traversal
void AVLTree::printLevelOrder(TreeNode* iNode) {
    if (!iNode)
        return;
    queue<TreeNode*> q;
    q.push(iNode);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

TreeNode* AVLTree::searchTree(int iData) {
    TreeNode* temp = root;
    while (temp) {
        //Data is Less Than Temp so Continue Down Left Subtree
        if (temp->data > iData)
            temp = temp->left;
        //Data is Greater Than Temp so Continue Down Right Subtree
        else if (temp->data > iData)
            temp = temp->right;
        //Correct Node Found. Return It.
        else
            return temp;
    }
    //Node not found with inputted data. 
    return nullptr;
}

void AVLTree::printTree() {
    if (this->root) {
        printR(this->root, "", true);
    }
}

int main()
{
    AVLTree tree;
    cout << "Inserting 10, 20, 30, 40, 50, 25" << endl;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    tree.printTree();

    cout << endl << endl << "Printing Pre Order" << endl;
    tree.printPreOrder(tree.getRoot());
    //30 20 10 25 40 50

    cout << endl << "Printing In Order" << endl;
    tree.printInOrder(tree.getRoot());
    //10 20 25 30 40 50 

    cout << endl << "Printing Post Order" << endl;
    tree.printPostOrder(tree.getRoot());
    //10 25 20 50 40 30 

    cout << endl << "Printing Level Order" << endl;
    tree.printLevelOrder(tree.getRoot());
    //30 20 40 10 25 50 

    cout << endl << endl << "Deleting The Root 30" << endl;
    tree.remove(30);
    tree.printTree();

    cout << endl << "Deleting a Leaf 10" << endl;
    tree.remove(10);
    tree.printTree();

    cout << endl << "Deleting Node 40 that has 1 Child" << endl;
    tree.remove(40);
    tree.printTree();
}
