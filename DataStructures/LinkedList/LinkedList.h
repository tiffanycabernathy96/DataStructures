#pragma once
struct node
{
public:
	int data;
	node* next;
	node* prev;
};
class LinkedList
{
public:
	
	LinkedList();
	~LinkedList();

	void addHead(int);
	void addTail(int);
	void addAt(int, int);
	void deleteHead();
	void deleteTail();
	void deleteAt(int);

	int getCount();

	void display();

private:
	node* head;
	node* tail;
	int numElems;
};