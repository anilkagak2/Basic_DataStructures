// defines the functions declared in stack.h

// assume the linked list's head->next node to be the top of the stack(while pushing), insert(0,x);
// and while popping out via delete_node();

#include <iostream>
#include "../include/stack.h"
#include "../include/sll.h"

// 1
// pushes x onto stack
void Stack::push(int x)
{
	insert(0,x);
}

// 2
// poppes an element out of stack
void Stack::pop()
{
	delete_node();
}

// 3
// returns the top element of the stack
int Stack::topEle()
{
	if(head->next)
	{
		return head->next->info;
	}

	else
	{
		std::cout << "Stack empty\n";
		return -1;
	}
}

// 4
// returns 1 if empty, else 0
bool Stack::isEmpty()
{
	return SLL::isEmpty();
}
