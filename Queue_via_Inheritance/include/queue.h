// declaring the interface for the queue class via inheriting the SLL class

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "../include/sll.h"

class Queue: protected SLL
{
	public:
		void enqueue(int x);		// enqueue the integer x in the queue
		void dequeue();			// dequeue one element from the queue
		int frontEle();			// returns the front element
		bool isEmpty();			// returns 1 if empty, otherwise 0
};

#endif
