// Tiffany Abernathy - Splay Tree Implementation
// Implementation of BFS and DFS Traversals

#include "SplayTree.h"
#include <queue>

TreeNode::TreeNode(int iData = NULL) {
    data = iData;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

//Private Functions
void SplayTree::deleteTree(TreeNode* iNode) {
    if (iNode) {
        deleteTree(iNode->left);
        deleteTree(iNode->right);
        delete iNode;
    }
}

void SplayTree::splay(TreeNode* iNode) {
    while (iNode->parent) {
        if (!iNode->parent->parent) {
            if (iNode == iNode->parent->left)
                rightRotate(iNode->parent);
            else
                leftRotate(iNode->parent);
        }
        else if (iNode == iNode->parent->left && iNode->parent == iNode->parent->parent->left) {
            rightRotate(iNode->parent->parent);
            rightRotate(iNode->parent);
        }
        else if (iNode == iNode->parent->right && iNode->parent == iNode->parent->parent->right) {
            leftRotate(iNode->parent->parent);
            leftRotate(iNode->parent);
        }
        else if (iNode == iNode->parent->right && iNode->parent == iNode->parent->parent->left) {
            leftRotate(iNode->parent);
            rightRotate(iNode->parent);
        }
        else {
            rightRotate(iNode->parent);
            leftRotate(iNode->parent);
        }
    }
}

TreeNode* SplayTree::join(TreeNode* iLeftTree, TreeNode* iRightTree) {
    if (!iLeftTree)
        return iRightTree;
    if (!iRightTree)
        return iLeftTree;

    TreeNode* temp = maximum(iLeftTree);
    splay(temp);
    temp->right = iRightTree;
    iRightTree->parent = temp;
    return temp;
}

void SplayTree::leftRotate(TreeNode* iNode) {
    //Take the right child of iNode
    TreeNode* rNode = iNode->right;
    //Set the right child of iNode to the left child of riNode
    iNode->right = rNode->left;

    //If riNodes left child is not null, set it's parent to iNode
    if (rNode->left)
        rNode->left->parent = iNode;
    //riNode is now in iNodes old spot so set riNode to iNode's parent. 
    rNode->parent = iNode->parent;
    //If iNode was the root i.e. iNode->parent is null then set the root to riNode.
    if (!iNode->parent)
        this->root = rNode;
    //If iNode is his parent's left child, set iNode's parent's left child to riNode
    else if (iNode == iNode->parent->left)
        iNode->parent->left = rNode;
    //Otherwise set parent's right child riNode. 
    else
        iNode->parent->right = rNode;

    //Set riNode's left to iNode
    rNode->left = iNode;
    //Set iNode's parent to riNode
    iNode->parent = rNode;
}

void SplayTree::rightRotate(TreeNode* iNode) {
    //Take the left child of the iNode
    TreeNode* lNode = iNode->left;
    //Set the left child of iNode to the right child of liNode
    iNode->left = lNode->right;

    //liNode's right child is not null, set it's parent to iNode
    if (lNode->right)
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

TreeNode* SplayTree::searchTreeR(TreeNode* iNode, int iData) {
    if (!iNode || iData == iNode->data)
        return iNode;
    if (iData < iNode->data)
        return searchTreeR(iNode->left, iData);
    return searchTreeR(iNode->right, iData);
}

void SplayTree::printR(TreeNode* iNode, string iIndent, bool iLast) {
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

//Public Functions
SplayTree::SplayTree() {
    root = nullptr;
}

SplayTree::~SplayTree() {
    deleteTree(root);
}

TreeNode* SplayTree::getRoot() {
    return root;
}

TreeNode* SplayTree::minimum(TreeNode* iNode) {
    while (iNode && iNode->left)
        iNode = iNode->left;
    return iNode;
}

TreeNode* SplayTree::maximum(TreeNode* iNode) {
    while (iNode && iNode->right)
        iNode = iNode->right;
    return iNode;
}

void SplayTree::insert(int iData) {
    TreeNode* newNode = new TreeNode(iData);
    TreeNode* parentNode = nullptr;
    TreeNode* temp = root;
    while (temp) {
        parentNode = temp;
        if (temp->data < iData)
            temp = temp->right;
        else
            temp = temp->left;
    }
    newNode->parent = parentNode;
    if (!parentNode) {
        root = newNode;
        return;
    }
    else if (iData < parentNode->data) 
        parentNode->left = newNode;
    else
        parentNode->right = newNode;

    splay(newNode);
}

void SplayTree::remove(int iData) {
    TreeNode* removedN = nullptr; 
    TreeNode* leftT = nullptr;
    TreeNode* rightT = nullptr;
    TreeNode* temp = root;
    while (temp) {
        if (temp->data == iData) {
            removedN = temp;
            break;
        }
        else if (temp->data < iData)
            temp = temp->right;
        else
            temp = temp->left;
    }
    if (!removedN) {
        cout << "Node Not Found in Tree" << endl;
        return;
    }
    
    splay(removedN);
    if (removedN->right) {
        rightT = removedN->right;
        rightT->parent = nullptr;
    }
    else
        rightT = nullptr;
    leftT = removedN;
    leftT->right = nullptr;
    removedN = nullptr;

    if (leftT->left)
        leftT->left->parent = nullptr;
    root = join(leftT->left, rightT);
    delete(leftT);
    leftT = nullptr;
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

TreeNode* SplayTree::searchTree(int iData) {
    TreeNode* node = searchTreeR(root, iData);
    if (node)
        splay(node);
    return node;
}

void SplayTree::printTree() {
    if (root)
        printR(root, "", true);
}

int main()
{
    SplayTree tree;
    cout << "Inserting 8, 15, 3, 9, 25, 2" << endl;
    tree.insert(8);
    tree.insert(15);
    tree.insert(3);
    tree.insert(9);
    tree.insert(25);
    tree.insert(2);

    tree.printTree();
    cout << "Deleting the Root Node: 2" << endl;
    tree.remove(2);
    tree.printTree();

    cout << "Deleting a Leaf Node: 8" << endl;
    tree.remove(8);
    tree.printTree();

    cout << "Inserting 2, 1" << endl;
    tree.insert(2);
    tree.insert(1);
    tree.printTree();

    cout << "Searching for 9" << endl;
    tree.searchTree(9);
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
