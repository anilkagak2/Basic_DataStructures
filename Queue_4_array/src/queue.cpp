/* Defining the member functions of the class Queue */

/* Queue here is Circular Queue */

/* In this implementation,
	Dequeue() --> simply increment the front index
	Enqueue() --> simply add at the rear end
	t(Dequeue()) = O(1)
	t(Enqueue()) = O(1)
	BUT, in this implementation, one space is left vacant to distinguish the FULL & EMPTY conditions
	Here, front index points to one location before the actual front of the queue...
	resulting in constant time enqueue(), dequeue() operations
 */
 
/* include the necessary header files */
#include "../include/queue.h"
#include <iostream>
using namespace std;

/* definitions */
/* LEAVE ONE PLACE VACANT AT INDEX 0 */

// 1
/* Default constructor */
Queue::Queue()
{
	/* initialize the front and rear variables */
	/* when first element will be enqueued, rear will increment by one and then the element will be placed there */
	front = rear = 0;
}

// 2
/* enqueues x into the queue */
void Queue::enqueue(int x)
{
	/* queue is not FULL */
	if(isFull() == 0)
	{
			/* increment the rear index circularly, and place the element */
			rear = (rear+1) % MAX_SIZE ;		/* if front is not at 0, then rear can go there */
			arr[rear] = x;				/* place the element */
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
	   // when front and rear both points at same place
	if(front == rear)
	return 1;	/* empty */

	return 0;	/* filled */
}

// 5
/* returns 1 if full, otherwise 0 */
bool Queue::isFull()
{
	/* when front is at rear+1(valid circularly too) , queue is FULL */
	if(front == (rear+1)%MAX_SIZE)
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
		/* here front may be more than rear index */
		/* case 1 */
		if(front < rear)
		{
			cout << "Front is smaller than Rear\n";
			for(int i= front;i<=rear;i++)
			{
				cout << arr[i] << "->";
			}
		}

		/* case 2 */
		else
		{
			cout << "Front is larger than Rear\n";
			/* Go till the last index in the array */
			for(int i= front;i<= MAX_SIZE-1;i++)
			{
				cout << arr[i] << "->";
			}

			/* start over from the index 0 till rear */
			for(int i= 0;i<= rear;i++)
			{
				cout << arr[i] << "->";
			}
		}
	}

	else
	cout << "Queue is EMpty\n";
}
