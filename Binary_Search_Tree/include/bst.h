/***********************************************************************************
*	Name:		Binary Search Tree
*	Author:		Anil Kag
*	Purpose:	Declares the class interface for Binary Search Tree
*	
***********************************************************************************/

#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// defining the node structure of dataType T
template <class T>
struct node
{
	T info;			// info field of the node
	struct node *lChild;	// left child of the node
	struct node *rChild;	// right child of the node
};

// may be this program will require to implement the specialize insert() function for string class, about the comparison operator

// defining the class structure of the Binary Search Tree Class
template <class T>
class BST
{
	private:
		struct node<T> *root;					// root of the tree
		void preOrderP(struct node<T> *tnode);			// private member for assiting public preOrder() function
		void inOrderP(struct node<T> *tnode);			// -,,- inOrder()
		void postOrderP(struct node<T> *tnode);			// -,,- postOder()
		void remove(struct node<T> *tnode);			// remove the node and it's successors, assists destructor
		int num_children(struct node<T> *tnode);		// returns the number fo children a node has

	public:
		BST();							// default constructor for the class
		~BST();							// default destructor to free up any space allocated
		int createFromFile(const char *fileName);		// make tree, taking input from file
		void insert(T val);					// insert a node with info as val in the tree
		void delete_Node(T val);				// delete a node with the info as val if it exists
		bool search(T val);					// search the tree for the existence of the node with info as val
		void delete_Tree();					// delete the whole tree
		void preOrder();					// traverse the tree in preOrder
		void inOrder();						// -,,- in InOrder
		void postOrder();					// -,,- in postOrder
};

#endif
