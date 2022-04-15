//Tiffany Abernathy - Hash Table Implementation Using Arrays
//Collisions Handling - Chaining with a Single Linked List
#include "HashTable.h"
#include <iostream>
using namespace std;

//From what I read using a prime number not to close to a multiple of 2 decreases changes of collision when using mod by table size for hash function.
const int TABLESIZE = 211;

HashTableItem::HashTableItem(int key, int value) {
    this->key = key;
    this->value = value;
    this->next = NULL;
}

HashTable::HashTable() {
    hashTable = new HashTableItem * [TABLESIZE];
    for (int i = 0; i < TABLESIZE; i++) {
        hashTable[i] = NULL;
    }
}
HashTable::~HashTable() {
    for (int i = 0; i < TABLESIZE; i++) {
        if (hashTable[i] != NULL) {
            HashTableItem* temp = hashTable[i];
            if (temp->next == NULL) {
                delete hashTable[i];
            }
            else {
                while (temp->next != NULL) {
                    HashTableItem* temp2 = temp;
                    temp = temp->next;
                    delete temp2;
                }
            }
        }
        delete[] hashTable;
    }
}

int HashTable::hashFunction(int key) {
    return key % TABLESIZE;
}
void HashTable::insert(int key, int value) {
    int hashKey = hashFunction(key);
    if(hashTable[hashKey] == NULL)
        hashTable[hashKey] = new HashTableItem(key, value);
    else {
        HashTableItem* temp = hashTable[hashKey];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new HashTableItem(key, value);
    }
}
int HashTable::search(int key) {
    int hashKey = hashFunction(key);

    if (hashTable[hashKey] == NULL) {
        cout << "Error - Item does not exist" << endl;
        return -1;
    }
    else {
        HashTableItem* temp = hashTable[hashKey];
        while (temp != NULL) {
            if (temp->key == key) {
                cout << "Key: " << key << " Value: " << temp->value << endl;
                return temp->value;
            }
            temp = temp->next;
        }
        cout << "Error - Item does not exist" << endl;
        return -1;
    }
}
void HashTable::remove(int key) {
    int hashKey = hashFunction(key);
    if (hashTable[hashKey] == NULL) {
        cout << "Error - Item does not exist" << endl;
    }
    else {
        HashTableItem* current = hashTable[hashKey];
        HashTableItem* prev = NULL;
        while (current != NULL) {
            if (current->key == key) {
                cout << "Key: " << key << " Value: " << current->value << " Removed." << endl;
                if (prev != NULL)
                    prev->next = current->next;
                else
                    hashTable[hashKey] = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Error - Item does not exist" << endl;
    }
}
void HashTable::print() {
    for (int i = 0; i < TABLESIZE; i++) {
        HashTableItem* item = hashTable[i];
        while (item != NULL) {
            cout << "Key: " << item->key;
            cout << " Value: " << item->value << endl;
            item = item->next;
        }
    }
}

int main()
{
    HashTable* table = new HashTable();
    int keys[] =   { 1,  9,  4,   2, 5,  6 };
    int values[] = { 12, 25, 100, 5, 13, 2 };
    cout << "Adding Key Value Pairs" << endl;
    for (int i = 0; i < 6; i++) {
        table->insert(keys[i], values[i]);
    }
    table->print();
    cout << "Removing 9, 25" << endl;
    table->remove(9);
    table->print();
    cout << "Searching for 1" << endl;
    table->search(1);
}
