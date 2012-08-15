/* Defining the member functions of the class Queue */

/* include the necessary header files */
#include "../include/queue.h"
#include <iostream>
using namespace std;

/* definitions */

// 1
/* Default constructor */
Queue::Queue()
{
	/* initialize the front and top variables */
	front = rear = -1;
}

// 2
/* enqueues x into the queue */
void Queue::enqueue(int x)
{
	/* queue is not FULL */
	if(isFull() == 0)
	{
		arr[++rear] = x;	/* increment the rear variable, place x there */

		// increment the front also if it is the first enqueue
		if(rear == 0)
		front = 0;
	}

	/* queue is FULL */
	else
	{
		cout << "Queue is Full\n";
	}
}

// 3
/* dequeues one element from the queue */
void Queue::dequeue()
{
	/* can perform dequeue op */
	if(isEmpty() == 0)
	{
		front++;	/* increment the front index */
	}

	/* Queue is Empty */
	else
	{
		cout << "Queue is Empty\n";
	}
}

// 4
/* returns 1 if empty, otherwise 0 */
bool Queue::isEmpty()
{
	   // initial empty condition or empty after reaching the end
	if((front== -1 && rear== -1) || (front == rear+1))
	return 1;	/* empty */

	return 0;	/* filled */
}

// 5
/* returns 1 if full, otherwise 0 */
bool Queue::isFull()
{
	if(rear == MAX_SIZE-1)
	return 1;		/* FULL */

	return 0;		/* not FULL */
}

// 6
/* returns the front element, if present */
int Queue::frontEle()
{
	if(isEmpty() == 0)
	{
		return arr[front];
	}

	/* Queue is Empty */
	else
	return -1;
}

// 7
/* returns the rear element, if present */
int Queue::rearEle()
{
	if(isEmpty() == 0)
	{
		return arr[rear];
	}

	/* Queue is Empty */
	else
	return -1;	
}

// 8
/* prints the queue */
void Queue::print()
{
	if(isEmpty() == 0)
	{
		/* printing the queue */
		for(int i= front;i<=rear;i++)
		{
			cout << arr[i] << "->";
		}
	}

	else
	cout << "Queue is EMpty\n";
}
