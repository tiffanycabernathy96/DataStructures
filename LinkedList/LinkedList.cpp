#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	numElems = 0;
}
LinkedList::~LinkedList()
{
	delete head;
	delete tail;
}

void LinkedList::addHead(int val)
{
	node* tempNode = new node;
	tempNode->data = val;
	if (head == NULL)
	{
		head = tempNode;
		tail = tempNode;
		head->next = NULL;
		head->prev = NULL;
		tail->next = NULL;
		tail->prev = NULL;
	}
	else
	{
		tempNode->next = head;
		head->prev = tempNode;
		head = tempNode;
	}
	numElems += 1;
}
void LinkedList::addTail(int val)
{
	node* tempNode = new node;
	tempNode->data = val;
	if (head == NULL)
	{
		head = tempNode;
		tail = tempNode;
		tempNode = NULL;
	}
	else
	{
		tempNode->prev = tail;
		tail->next = tempNode;
		tail = tempNode;
	}
	tail->next = NULL;
	numElems += 1;
}
void LinkedList::addAt(int pos, int val)
{
	if (head == NULL || pos == 0)
	{
		addHead(val);
		return;
	}

	node* tempNode = new node;
	node* prevNode = new node;
	node* currNode = new node;
	currNode = head;
	tempNode->data = val;
	for (int i = 1; i <= pos; i++)
	{
		if (currNode->next == NULL)
			break;
		prevNode = currNode;
		currNode = currNode->next;
	}

	tempNode->next = currNode;
	currNode->prev = tempNode;
	prevNode->next = tempNode;
	tempNode->prev = prevNode;
	numElems += 1;
}
void LinkedList::deleteHead()
{
	if (head->next != NULL)
	{
		node* temp = new node;
		temp = head;
		head = head->next;
		delete temp;
		numElems -= 1;
	}
}
void LinkedList::deleteTail()
{
	if (tail->prev != NULL)
	{
		node* temp = new node;
		temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
		numElems -= 1;
	}
}
void LinkedList::deleteAt(int pos)
{
	if (head != NULL && pos < numElems)
	{
		node* currNode = new node;
		node* prevNode = new node;
		currNode = head;
		for (int i = 1; i <= pos; i++)
		{
			if (currNode->next == NULL)
				break;
			prevNode = currNode;
			currNode = currNode->next;
		}
		prevNode->next = currNode->next;
		currNode->next->prev = prevNode;
		delete currNode;
		numElems -= 1;
	}

}
int LinkedList::getCount()
{
	return numElems;
}
void LinkedList::display()
{
	node* temp = new node;
	temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
	std::cout << std::endl;
}
int main()
{

}