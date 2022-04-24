#pragma once
#include <string>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TreeNode {
	bool isEnd;
	TreeNode* children[ALPHABET_SIZE];
	TreeNode();
};

class TrieTree {
	TreeNode* root;
	void deleteTreeR(TreeNode* node);
	void printR(TreeNode* node, char str[], int level);
public:
	TrieTree();
	~TrieTree();

	void insert(string key);
	//TreeNode* remove(TreeNode* node, string key, int depth);

	bool search(string key);

	void print();
};