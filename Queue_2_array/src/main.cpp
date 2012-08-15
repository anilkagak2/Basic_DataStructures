/* using the queue class, defined earlier */

#include <iostream>
#include "../include/queue.h"
using namespace std;

/* using the simple enqueue(), dequeue(), isEmpty(), isFull() routines */
int main()
{
	Queue q;
	q.enqueue(11);
	q.enqueue(31);
	q.enqueue(60);
	q.enqueue(7);

	q.print();
	cout << endl;

	q.enqueue(9);
	q.enqueue(42);
	q.print();
	cout << endl;

	q.enqueue(7);
	q.enqueue(4);
	q.dequeue();
	q.print();
	cout << endl;

	cout << q.isEmpty() << endl;
	cout << q.isFull() << endl;
	q.enqueue(2);
	q.enqueue(2);
	q.enqueue(2);
	q.dequeue();
	q.enqueue(3);
	q.enqueue(6);
	q.print();
	cout << endl;

	cout << q.isEmpty() << endl;
	cout << q.isFull() << endl;

	return 0;
}
