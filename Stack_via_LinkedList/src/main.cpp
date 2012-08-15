// using the Stack class
// main.cpp of both the implementations are same
// with slight variation because of the different pop function

#include <iostream>
#include "../include/Stack.h"
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

	cout << s.topEle() << endl;
	s.pop();
	s.pop();
	cout << s.topEle() << endl;
	s.pop();
	cout << "is Stack empty " << s.isEmpty() << endl;
	s.pop();

	cout << "is Stack empty " << s.isEmpty() << endl;

	return 0;
}
