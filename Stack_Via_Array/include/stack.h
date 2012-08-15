// declares the class "stack", with it's member functions

#define STACK_SIZE 10

class Stack
{
	private:
		int st[STACK_SIZE];	//array used for stack implementation
		int top;		// keeps the top index of the stack

	public:
		Stack();		// default constructor
		void push(int x);	// pushes x onto stack
		int pop();		// pop's an element from the stack
		int topEle();		// returns top Element from the stack without popping
		bool isEmpty();		// returns TRUE if stack is Empty, otherwise false
		bool isFull();		// returns TRUE if stack is Full, otherwise false
};
