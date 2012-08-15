// uses the queue class implemented via inheriting the singly linked list class

#include <iostream>
#include "../include/queue.h"
#include "../include/sll.h"
using namespace std;

int main()
{
	Queue q;

	q.enqueue(4);
	q.enqueue(3);
	cout << q.frontEle() << endl;
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(1);

	q.dequeue();
	q.dequeue();
	cout << q.frontEle() << endl;
	q.dequeue();
	q.dequeue();
	cout << q.isEmpty() << endl;
	q.dequeue();

	cout << q.isEmpty() << endl;
	return 0;
}
