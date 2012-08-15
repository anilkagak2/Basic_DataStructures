/* Declaring the queue class, which uses an array */

#ifndef _QUEUE_H_
#define _QUEUE_H_

/* the maximum size of the array */
#define MAX_SIZE 10

/* declaration of the class */
class Queue
{
	private:
		int arr[MAX_SIZE];	/* array holding the queue */
		int front;		/* front of the queue */
		int rear;		/* rear of the queue */

	public:
		Queue();		/* Default constructor */
		void enqueue(int x);	/* enqueues x into the queue */
		void dequeue();		/* dequeues one element from the queue */
		bool isEmpty();		/* returns 1 if empty, otherwise 0 */
		bool isFull();		/* returns 1 if full, otherwise 0 */
		int frontEle();		/* returns the front element, if present */
		int rearEle();		/* returns the rear element, if present */
		void print();		/* prints the queue */
};

#endif
