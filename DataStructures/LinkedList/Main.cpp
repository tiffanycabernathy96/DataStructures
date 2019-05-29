#include "LinkedList.h"
#include <iostream>

int main()
{
	//Implementation if a Doubly Linked List
	LinkedList* llist = new LinkedList();
	//Starts with 0 Elements
	std::cout << "Number of Elements: " << llist->getCount() << std::endl;
	//Add a new node to begining with value of 1
	llist->addHead(1);
	//Show that it was added
	llist->display();
	std::cout << "Number of Elements: " << llist->getCount() << std::endl;
	//Add another 1 to the beginning
	llist->addHead(1);
	//Add 2 to the end
	llist->addTail(2);
	//Add another 2 between the two ones
	llist->addAt(1, 2);
	llist->display();
	//Delete the second 1
	llist->deleteAt(2);
	llist->display();
	//Delete the head i.e. 1
	llist->deleteHead();
	llist->display();
	//Delete the tail i.e. 2
	llist->deleteTail();
	llist->display();
	//Add 0 to the front
	llist->addHead(0);
	//add 3 to the back
	llist->addTail(3);
	llist->display();
	//Add 1 between the 0 and 2
	llist->addAt(1, 1);
	llist->display();
}