// defining the functions declared in ../include/sll.h

#include <iostream>
#include "../include/sll.h"

// 1
// default contructor
SLL::SLL()
{
	// allocating the memory for the dummy node head
	head = new(tnode);
	head->next = NULL;
}

// 2
// frees the memory allocated by the program
SLL::~SLL()
{
	tnode *tmp;

	while(head != NULL)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

// 3
// inserts at pos if valid, else at the end
// pos starts with 0
void SLL::insert(int pos, int x)
{
	tnode *cur = head->next,*prev=head;
	int index=0;

	// allocate the space for the new node
	tnode *nnode = new(tnode);
	nnode->info = x;

	// traverse till the pos, if it exists else till the last node
	while(cur != NULL && index != pos)
	{
		index++;		// increment the position counter
		prev = cur;	// place current in the previous
		cur = cur->next;	// increment the current pointer
	}

	// if the position do not exists
	if(cur == NULL)
	{
		// nnode will be the last node
		nnode->next = NULL;
		prev->next = nnode;
	}

	// if the position exists
	else
	{
		nnode->next = cur;
		prev->next = nnode;
	}
}

// 4
// deletes the node with value val, if exists
void SLL::delete_node(int val)
{
	tnode *cur = head->next,*prev = head;

	while(cur != NULL && cur->info != val)
	{
		prev = cur;
		cur = cur->next;
	}

	if(cur != NULL)
	{
		prev->next = cur->next;
		delete cur;
	}
}

// 5
// searches for the existence of the node with this value
bool SLL::search(int x)
{
	tnode *cur = head->next;

	while(cur != NULL)
	{
		// match found
		if(cur->info == x)
		return 1;

		cur = cur->next;
	}

	// not found
	return 0;
}

// 6
// returns 1 if empty else 0
bool SLL::isEmpty()
{
	return (head->next == 0);
}

// 7
// prints the list
void SLL::print()
{
	tnode *cur = head->next;

	while(cur != NULL)
	{
		std::cout << cur->info << " -> ";
		cur = cur->next;
	}
}

// 8
// by default delete the head->next
void SLL::delete_node()
{
	if(head->next)
	{
		tnode *tmp = head->next;
		head->next = tmp->next;
		delete tmp;
	}

	else
	{
		std::cout << "List Underflown\n";
	}
}
