// defining the Stack class member functions
// include the header file for the Stack declaration

#include "../include/Stack.h"
#include <iostream>
#include <assert.h>
using namespace std;

// 1
// initialise the head node
Stack::Stack()
{
	// allocate space for the head node and point it's next to NULL
	head = new(tnode);
	head->next = NULL;
}

// 2
// free the space allocated
Stack::~Stack()
{
	// free the allocated space
	tnode *tmp;		// hold the address of the node to be deleted
	tnode *cur;		// to increment the list at each iteration

	cur = head;
	while(cur != NULL)
	{
		tmp = cur;		// keep cur's address, to delete
		cur = cur->next;	// increment the cur pointer
		delete tmp;		// delete the tmp
	}
}

// 3
// push x onto the stack
void Stack::push(int x)
{
	// push means insert at top
	// assume top to be head->next
	tnode *nnode = new(tnode);	// allocate the space for the new node

	// fill the nnode's fields
	nnode->next = head->next;	// let head's next be the next of nnode
	nnode->info = x;		// put x in the info field of the nnode

	// change the head's next
	head->next = nnode;
}

// 4
// pop one element from the stack
void Stack::pop()
{
	// stack is empty
	if(isEmpty() == 1)
	{
		cout << "Stack Underflown\n";
		return;
	}

	else
	{
		tnode *tmp = head->next; 	// this node should not be NULL
		assert(tmp != NULL);		// check, this node should not be NULL
		head->next = tmp->next;		// manipulate the pointer
		delete tmp;			// delete the node
	}
}

// 5
// returns the topElement
int Stack::topEle()
{
	// if stack is empty
	if(isEmpty() == 1)
	{
		cout << "Stack Underflown\n";
		return -1;
	}

	else
	{
		return head->next->info;	// info field of head's next
	}
}

// 6
// returns TRUE if empty, otherwise false
bool Stack::isEmpty()
{
	if(head->next == NULL)
	return 1;	// TRUE

	else return 0;	// FALSE
}
