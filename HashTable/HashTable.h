#pragma once
struct HashTableItem {
	int key;
	int value;
	HashTableItem* next;
	HashTableItem(int key, int value);
};
class HashTable {
private:
	HashTableItem** hashTable;
public:
	HashTable();
	~HashTable();

	int hashFunction(int key);
	void insert(int key, int value);
	int search(int key);
	void remove(int key);
	void print();
};