/* implementing stack using linked list, everything in one single class Stack(singly linked list) */
/* it could have been done easily using two classes viz.
1) SLL(IMPLEMENT SINGLY LINKED LIST)
2) Stack(USE THE SLL TO IMPLEMENT IT)
*/

// define structure for the nodes of linked list
struct node
{
	int info;		// information field of the node
	struct node *next;	// pointer to the next node in the list
};

// typedef the name
typedef struct node tnode;

// declaration of the class Stack
class Stack
{
	private:
		tnode *head;		// head node of the list (dummy node, just points to top of the stack, if any)

	public:
		Stack();		// initialise the head node
		~Stack();		// free the space allocated
		void push(int x);	// push x onto the stack
		void pop();		// pop one element from the stack
		int topEle();		// returns the topElement
		bool isEmpty();		// returns TRUE if empty, otherwise false
};
