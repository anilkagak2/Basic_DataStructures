// defining the functions declared in the queue class

// inserting at head->next and deleting from the last

#include "../include/sll.h"
#include "../include/queue.h"
#include <iostream>
using namespace std;

// 1
// enqueue the integer x in the queue
void Queue::enqueue(int x)
{
	tnode *nnode = new(tnode);	// allocate the space
	nnode->info = x;		// fill the field info
	nnode->next = head->next;	// make head's next as next of nnode
	head->next = nnode;		// make nnode as next to head
}

// 2
// dequeue one element from the queue
void Queue::dequeue()
{
	// travel till the last and delete the last node
	tnode *cur = head->next, *prev = head;

	// queue has atleast one node after head
	if(this->isEmpty() == 0)
	{
		while(cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}

		// now cur is at last
		delete cur;		// delete the cur
		prev->next = NULL;	// change the next of prev
	}

	else
	{
		// queue is empty
		cout << "Queue is Empty...\n";
	}
}

// 3
// returns the front element
int Queue::frontEle()
{
	tnode *cur = head->next;

	if(this->isEmpty() == 0)
	{
		while(cur->next != NULL)
		cur = cur->next;

		// now cur is at the last
		return cur->info;
	}

	else
	{
		// queue is empty
		cout << "Queue is Empty...\n";
		return -1;
	}
}

// 4
// returns 1 if empty, otherwise 0
bool Queue::isEmpty()
{
	return SLL::isEmpty();
}
