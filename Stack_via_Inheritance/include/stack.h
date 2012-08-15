// declaring the stack class using the sll class and inheritance

#ifndef _STACK_H_
#define _STACK_H_

// include the sll.h file
#include "../include/sll.h"

// stack inherits SLL class as private
class Stack: protected SLL
{
	public:
		void push(int x);	// pushes x onto stack
		void pop();		// poppes an element out of stack
		int topEle();		// returns the top element of the stack
		bool isEmpty();		// returns 1 if empty, else 0
};

#endif
