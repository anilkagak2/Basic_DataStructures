/* Defining the member functions of the class Queue */

/* Queue here is Circular Queue */

/* In this implementation,
	Dequeue() --> simply increment the front index
	Enqueue() --> simply add at the rear end
	t(Dequeue()) = O(1)
	t(Enqueue()) = O(1)
	Here, i am keeping the track of the number of elements
	resulting in constant time enqueue(), dequeue() operations
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
	/* initialize the front and size variables */
	front = -1;
	size = 0;
}

// 2
/* enqueues x into the queue */
void Queue::enqueue(int x)
{
	/* queue is not FULL */
	if(isFull() == 0)
	{
		/* if this is the first enqueue() operation */
		if(front == -1)
		{
			/* making the front index 0 */
			arr[0] = x;
			front = 0;
			size++;
		}

		else
		{
			/* new rear will be at (front+size) % MAX_SIZE */
			int rear = (front + size) % MAX_SIZE;
			size++;			/* increase the size by 1 */
			arr[rear] = x;		/* place the element */
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
		front = (front+1)% MAX_SIZE;		/* if front were at MAX_SIZE-1, then after increment it should go to 0th index */
		size--;					/* decrease the size by 1 */
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
	/* if size = 0, then empty */
	if(size == 0)
	return 1;	/* empty */

	return 0;	/* filled */
}

// 5
/* returns 1 if full, otherwise 0 */
bool Queue::isFull()
{
	/* size equals MAX_SIZE ==> queue is FULL */
	if(size == MAX_SIZE)
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
		/* calculate the rear end */
		int rear = (front + size -1) % MAX_SIZE;
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
		/* j is the counter of the loop, i the index of the array currently */

		/* initialise the index pointing variable for the loop, i */
		int i= front;
		for(int j=0;j<size;j++)
		{
			cout << i <<" : " << arr[i] << "->";
			i++;

			if(i == MAX_SIZE)
			i = 0;
		}
		
	}

	else
	cout << "Queue is EMpty\n";
}
