
#include "Heap.h"
#include <iostream>
#include <vector>
using namespace std;

void Heap::swap(int* iData1, int* iData2)
{
    int temp = *iData2;
    *iData2 = *iData1;
    *iData1 = temp;
}

void Heap::heapify(int iData)
{
    if (min) {
        int size = heap.size();
        int smallest = iData;
        int l = 2 * iData + 1;
        int r = 2 * iData + 2;
        if (l < size && heap[l] < heap[smallest])
            smallest = l;
        if (r < size && heap[r] < heap[smallest])
            smallest = r;
        if (smallest != iData) {
            swap(&heap[iData], &heap[smallest]);
            heapify(smallest);
        }
    }
    else {
        int size = heap.size();
        int largest = iData;
        int l = 2 * iData + 1;
        int r = 2 * iData + 2;
        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != iData)
        {
            swap(&heap[iData], &heap[largest]);
            heapify(largest);
        }
    }
}

void Heap::printR(int index, string iIndent, bool iLast) {
    if (index >= 0 && index < heap.size()) {
        cout << iIndent;
        if (iLast) {
            cout << "R----";
            iIndent += "   ";
        }
        else {
            cout << "L----";
            iIndent += "|  ";
        }
        cout << "Data: " << heap[index] << endl;
        printR(2 * index + 1, iIndent, false);
        printR(2 * index + 2, iIndent, true);
    }
}

//Public Functions
Heap::Heap(bool iIsMinHeap = false) {
    heap = vector<int>();
    min = iIsMinHeap;
}

void Heap::insert(int iData)
{
    int size = heap.size();
    if (size == 0)
        heap.push_back(iData);
    else
    {
        heap.push_back(iData);
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(i);
    }
}

void Heap::remove(int iData)
{
    int size = heap.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (iData == heap[i])
            break;
    }
    swap(&heap[i], &heap[size - 1]);

    heap.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(i);
}

void Heap::printTreeArray()
{
    for (int i = 0; i < heap.size(); ++i)
        cout << heap[i] << " ";
    cout << endl;
}

void Heap::printTree() {
    printR(0, "", true);
}

int main()
{
    Heap heapTree(false);
    
    heapTree.insert(31);
    heapTree.insert(30);
    heapTree.insert(29);
    heapTree.insert(28);
    heapTree.insert(27);
    heapTree.insert(26);
    heapTree.insert(25);
    heapTree.insert(24);
    heapTree.insert(23);
    heapTree.insert(22);
    heapTree.insert(21);
    heapTree.insert(20);
    heapTree.insert(19);
    heapTree.insert(18);
    heapTree.insert(17);
    heapTree.insert(16);
    heapTree.insert(15);
    heapTree.insert(14);
    heapTree.insert(13);
    heapTree.insert(12);
    heapTree.insert(11);
    heapTree.insert(10);
    heapTree.insert(9);
    heapTree.insert(8);
    heapTree.insert(7);
    heapTree.insert(6);
    heapTree.insert(5);
    heapTree.insert(4);
    heapTree.insert(3);
    heapTree.insert(2);
    heapTree.insert(1);

    cout << "Max-Heap array: " << endl;
    heapTree.printTree();

    heapTree.remove(31);

    cout << "After deleting Largest Element: " << endl;

    heapTree.printTree();

    cout << endl;
   
    Heap heapTree2(true);

    heapTree2.insert(31);
    heapTree2.insert(30);
    heapTree2.insert(29);
    heapTree2.insert(28);
    heapTree2.insert(27);
    heapTree2.insert(26);
    heapTree2.insert(25);
    heapTree2.insert(24);
    heapTree2.insert(23);
    heapTree2.insert(22);
    heapTree2.insert(21);
    heapTree2.insert(20);
    heapTree2.insert(19);
    heapTree2.insert(18);
    heapTree2.insert(17);
    heapTree2.insert(16);
    heapTree2.insert(15);
    heapTree2.insert(14);
    heapTree2.insert(13);
    heapTree2.insert(12);
    heapTree2.insert(11);
    heapTree2.insert(10);
    heapTree2.insert(9);
    heapTree2.insert(8);
    heapTree2.insert(7);
    heapTree2.insert(6);
    heapTree2.insert(5);
    heapTree2.insert(4);
    heapTree2.insert(3);
    heapTree2.insert(2);
    heapTree2.insert(1);

    cout << "Min-Heap array: " << endl;
    heapTree2.printTree();

    heapTree2.remove(1);

    cout << "After deleting Smallest Element: " << endl;

    heapTree2.printTree();
}