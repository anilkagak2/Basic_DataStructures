// declares the interface for the singly linked list to be used in further inheritance

#ifndef _SINGLY_LINKED_LIST_
#define _SINGLY_LINKED_LIST_

// defining the structure of the node
struct node
{
	int info;		// info field
	struct node *next;	// pointer to next node in the list
};

// rename the struct node
typedef struct node tnode;

// declaring the SLL class
class SLL
{
	protected:
		tnode *head;		// head of the list,points to the first element in the list

	public:
		SLL();			// default contructor
		~SLL();			// frees the memory allocated by the program
		void insert(int pos, int x);	// inserts at pos if valid, else at the end
		void delete_node(int val);	// deletes the node with value val, if exists
		bool search(int x);		// searches for the existence of the node with this value
		bool isEmpty();		// returns 1 if empty else 0
		void print();			// prints the list
		void delete_node();		// by default delete the head->next
};

#endif
