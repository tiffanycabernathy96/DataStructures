#pragma once

#include <iostream>
#include <vector>
using namespace std;
class Heap {
	vector<int> heap;
	bool min;
	
	void swap(int* iData1, int* iData2);
	void heapify(int iData);
	void printR(int index, string iIndent, bool iLast);
public:
	Heap(bool iIsMinHeap);
	void insert(int iData);
	void remove(int iData);
	void printTreeArray();
	void printTree();
};