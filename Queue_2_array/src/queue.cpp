/* Defining the member functions of the class Queue */

/* In this implementation, while enqueuing rear will be incremented as usual
  But while dequeuing, all the elements after the front will be brought one place towards front
 i.e. Front will always be at index = 0, if there is any element
  and dequeue = O(n), n is the size of the array
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
		/* Shift the elements form front+1, one index towards front */
		for(int i=1;i<=rear;i++)
		arr[i-1] = arr[i];

		rear-- ;		/* Decrement the rear index */

		/* May be the case that both front and rear were 0, so decrement the front index */
		if(rear == -1)
		front = -1;
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
	   // initial empty condition 
	if((front== -1 && rear== -1))
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
		/* front always will be 0, in this if case, you may replace it with 0 */
		for(int i= front;i<=rear;i++)
		{
			cout << arr[i] << "->";
		}
	}

	else
	cout << "Queue is EMpty\n";
}
