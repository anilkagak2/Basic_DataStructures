// using the stack class

#include <iostream>
#include "../include/stack.h"
using namespace std;

int main()
{
	// declaring an object of class Stack
	Stack s;

	// some random sequence of push and pop to check the stack implementation
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);

	cout << s.pop() << endl;
	s.pop();
	cout << s.topEle() << endl;
	s.pop();
	cout << "is Stack empty " << s.isEmpty() << endl;
	cout << "is Stack full " << s.isFull() << endl;
	s.pop();

	cout << "is Stack empty " << s.isEmpty() << endl;
	cout << "is Stack full " << s.isFull() << endl;

	return 0;
}
