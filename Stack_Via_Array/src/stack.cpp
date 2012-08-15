// defines the functions declared in ../include/stack.h

// include the header files
#include <iostream>
#include "../include/stack.h"
using namespace std;

// function 1
// default constructor
Stack::Stack()
{
	top = -1;	// initialise the variable top
}

// 2
// pushes x onto stack
void Stack::push(int x)
{
	// if stack is full
	if(isFull() == 1)
	{
		cout << "Stack Full\n";
		return;
	}

	else
	{
		st[++top] = x;	// top is initialised with -1
	}
}

// 3
// pop's an element from the stack
int Stack::pop()
{
	// if stack is empty
	if(isEmpty() == 1)
	{
		cout <<"Stack Underflown\n";
		return -1;	// assume the stack to be working for positive numbers.
	}

	else
	{
		return st[top--];		// decrement the stack's top pointer
	}
}

// 4
// returns top Element from the stack without popping
int Stack::topEle()
{
	if(isEmpty() == 1)
	{
		cout <<"Stack Empty\n";
		return -1;
	}

	else
	{
		return st[top];
	}
}

// 5
// returns 1 if stack is Empty, otherwise 0
bool Stack::isEmpty()
{
	if(top == -1)
	return 1;

	else return 0;
}

// 6
// returns 1 if stack is Full, otherwise 0
bool Stack::isFull()
{
	if(top == STACK_SIZE-1)
	return 1;

	else return 0;
}
