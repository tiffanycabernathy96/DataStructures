// Tiffany Abernathy - Trie Tree Implementation
// https://www.dcode.fr/boggle-solver-4x4 Used to Create Boggle Board and Generate Word List

#include "TrieTree.h"
#include <fstream>
#include <iostream>
using namespace std;

TreeNode::TreeNode() {
    isEnd = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        children[i] = NULL;
}

//Private Functions
void TrieTree::deleteTreeR(TreeNode* node) {
    if (node != NULL) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            deleteTreeR(node->children[i]);
        }
        delete node;
    }
}
void TrieTree::printR(TreeNode* node, char str[], int level) {
    if (node->isEnd){
        str[level] = '\0';
        cout << str << endl;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++){
        if (node->children[i]){
            str[level] = i + 'a';
            printR(node->children[i], str, level + 1);
        }
    }
}

//Public Functions
TrieTree::TrieTree() {
    root = new TreeNode();
}

TrieTree::~TrieTree() {
    deleteTreeR(root);
}

void TrieTree::insert(string key) {
    TreeNode* temp = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!temp->children[index])
            temp->children[index] = new TreeNode();
        temp = temp->children[index];
    }
    temp->isEnd = true;
}
/*TreeNode* TrieTree::remove(TreeNode* node, string key, int depth) {

}*/

bool TrieTree::search(string key) {
    TreeNode* temp = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!temp->children[index])
            return false;
        temp = temp->children[index];
    }
    return(temp != NULL && temp->isEnd);
}
\
void TrieTree::print() {
    char arr[16];
    printR(root, arr, 0);
}

void readFile(const char* filename, vector<string>* lines)
{
    lines->clear();
    ifstream file(filename);
    string s;
    while (getline(file, s))
        lines->push_back(s);
}
void printGrid() {
    cout << "| S | U | G | H |" << endl;
    cout << "| U | G | Y | E |" << endl;
    cout << "| B | S | T | Y |" << endl;
    cout << "| A | W | I | X |" << endl;
}
bool confirmLetters(string key) {
    for (char c : key) {
        ////65 to 90 or 97 to 122
        if (c < 65 || (c > 90 && c < 97) || c > 122) {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << "Can You Find all of the Words in the Below Grid?" << endl;
    printGrid();

    vector<string> keys;
    readFile("words.txt", &keys);
    vector<bool> found = vector<bool>(keys.size(), false);
    int totalWords = keys.size();

    TrieTree tree;
    for (int i = 0; i < keys.size(); i++) {
        tree.insert(keys[i]);
    }
    int choice = 1;
    while (choice != 3) {
        cout << "Choose What you Would Like to Do by Typing in the Number: " << endl;
        cout << "1 - Enter a Word" << endl;
        cout << "2 - Reprint Grid" << endl;
        cout << "3 - Exit" << endl;
        cin >> choice;
        while (choice < 1 || choice > 3) {
            cout << endl << "Please Enter a Valid Option 1, 2 or 3." << endl;
            cin >> choice;
        }
        string word;
        if (choice == 1) {
            cout << "Please Enter a Word. All Words are Between 3 and 16 letters" << endl;
            cin >> word; 
            while (word.empty() || word.size() < 3 || word.size() > 16 || !confirmLetters(word)) {
                cout << endl << "Please Enter a Valid Word Between the Size of 3 and 16 Letters" << endl;
                cin >> word;
            }
         
            for (char& c : word) {
                c = tolower(c);
            }
            if (tree.search(word)) {
                auto it = find(keys.begin(), keys.end(), word);
                int index = -1;
                if (it != keys.end())
                    index = it - keys.begin();
                if (index != -1) {
                    if (found[index]) {
                        cout << "Word Already Found" << endl;
                    }
                    else {
                        found[index] = true;
                        totalWords--;
                        cout << "Congrats! " << word << " Exists!" << endl;
                        if (totalWords == 0) {
                            cout << "Congrats! You Found all the Words!" << endl;
                            choice == 2;
                        }
                        else
                            cout << "There is " << totalWords << " Words Left to Find" << endl;
                    }
                }
            }
            else {
                cout << "Word Does not Exist in the Grid" << endl;
            }
        }
        else if (choice == 2) {
            printGrid();
        }
    }
}
