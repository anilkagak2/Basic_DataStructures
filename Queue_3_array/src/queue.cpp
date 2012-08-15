/* Defining the member functions of the class Queue */

/* In this implementation, 
	Dequeue() --> simply increment the front index
	Enqueue() --> when the rear index reaches to MAX_SIZE-1, simply place the whole queue such that the new queue, starts from 0
	t(Dequeue()) = O(1)
	t(Enqueue()) = O(1)/O(n)
 */
 
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
		/* checking whether we need not move the entire queue or not */
		/* MAX_SIZE is the maximum index till which rear can go */
		if(rear == MAX_SIZE-1)
		{
			/* calculate the new rear index*/
			int newRear = rear - front;

			/* need to move */
			int i= front;		// place the front in i
			for(;i<=rear;i++)
			{
				arr[i-front] = arr[i];
			}

			/* change the front and rear indices */
			front = 0;
			rear = newRear;
			cout << "Performed a full queue MOVE\n";
			cout << "And placing " << x << " at index " << rear+1 << "\n";
			arr[++rear] = x;	/* place x in the space created */
		}

		else
		{
			/* no need to increment */
			arr[++rear] = x;	/* increment the rear variable, place x there */

			// increment the front also if it is the first enqueue
			if(rear == 0)
			front = 0;
		}
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
		front++;		/*increment the front index */
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
	if(rear == MAX_SIZE-1 && front==0)
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
		/* front always will be 0, in this if case, you may replace it with 0 */
		for(int i= front;i<=rear;i++)
		{
			cout << arr[i] << "->";
		}
	}

	else
	cout << "Queue is EMpty\n";
}
