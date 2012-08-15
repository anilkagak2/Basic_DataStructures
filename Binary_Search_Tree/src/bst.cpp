/***********************************************************************************
*	Name:		Binary Search Tree
*	Author:		Anil Kag
*	Purpose:	Defines the member functions of BST class
*	
***********************************************************************************/

#include "../include/bst.h"

// private member for assiting public preOrder() function
template <class T>
void BST<T>::preOrderP(struct node<T> *tnode)
{
	// if tnode is not NULL
	if(tnode)
	{
		cout << tnode->info << "  ";			// visit the node
		preOrderP(tnode->lChild);			// visit the left tree
		preOrderP(tnode->rChild);			// visit the right tree
	}
}

// inOrder()
template <class T>
void BST<T>::inOrderP(struct node<T> *tnode)
{
	// if tnode is not NULL
	if(tnode)
	{
		inOrderP(tnode->lChild);			// visit the left tree
		cout << tnode->info << "  ";			// visit the node
		inOrderP(tnode->rChild);			// visit the right tree
	}
}

// postOder()
template <class T>
void BST<T>::postOrderP(struct node<T> *tnode)
{
	// if tnode is not NULL
	if(tnode)
	{
		postOrderP(tnode->lChild);			// visit the left tree
		postOrderP(tnode->rChild);			// visit the right tree
		cout << tnode->info << "  ";			// visit the node
	}
}

// remove the node and it's successors, assists destructor
template <class T>
void BST<T>::remove(struct node<T> *tnode)
{
	// if the node is not NULL
	if(tnode)
	{
		remove(tnode->lChild);				// delete the left subtree
		remove(tnode->rChild);				// delete the right subtree
		delete tnode;					// delete this node
	}
}

// returns the number fo children a node has
template <class T>
int BST<T>::num_children(struct node<T> *tnode)
{
	int count = 0;
	if(tnode->lChild)					// does it has left child??
		count++;

	if(tnode->rChild)					// does it has right child??
		count++;

	return count;
}

// default constructor for the class
template <class T>
BST<T>::BST()
{
	// initialise the root with NULL
	root = NULL;
}

// default destructor to free up any space allocated
template <class T>
BST<T>::~BST()
{
	remove(root);						// delete the tree rooted at root i.e. Whole BST
}

// ##
// not implemented FULLY
// make tree, taking input from file
template <class T>
int BST<T>::createFromFile(const char *fileName)
{
	// open the file for reading
	ifstream in(fileName);

	if(!in)
	{
		cout << "Error in opening the file\n";
		return -1;
	}

	T val;				// temporary storage
	in >> val;

	while(!in.eof())
	{
		insert(val);		// insert the val in a node, in tree

		cin.clear();
		in >> val;		// take the next value
		if(in.eof())
			break;
	}
	return 0;
}

// insert a node with info as val in the tree
template <class T>
void BST<T>::insert(T val)
{
	// 1st node in the tree
	if(root == NULL)
	{
		// allocate space for root and initialise the values
		root = new(struct node<T>);
		root->info = val;
		root->lChild = NULL;
		root->rChild = NULL;
	}

	// insertion at other positions
	else
	{
		struct node<T> *nnode = new(struct node<T>);
		nnode->info = val;
		nnode->lChild = NULL;
		nnode->rChild = NULL;

		struct node<T> *cur = root,*par = root;
		while(cur != NULL)
		{
			par = cur;			// store the node as parent
			if(val < cur->info)
				cur = cur->lChild;	// move to the left side of the tree

			else
				cur = cur->rChild;	// move to the right side of the tree
		}

		// cur is NULL, par is at the parent of val's position
		if(val < par->info)
			par->lChild = nnode;		// nnode is the left child of the parent node

		else	par->rChild = nnode;		// nnode is the right child of the parent node
	}
}

// ##
// not implemented FULLY
// delete a node with the info as val if it exists
template <class T>
void BST<T>::delete_Node(T val)
{
	struct node<T> *cur = root,*par = NULL;

	while(cur != NULL)
	{
		if(val == cur->info)
			break;			// found

		else if(val < cur->info)
		{
			par = cur;
			cur = cur->lChild;	// may be available in the left subtree
		}

		else
		{
			par = cur;
			cur = cur->rChild;		// -,,- in right subtree
		}
	}

}


// search the tree for the existence of the node with info as val
template <class T>
bool BST<T>::search(T val)
{
	struct node<T> *cur = root;

	while(cur != NULL)
	{
		if(val == cur->info)
		{
			cout << "Found\n";
			return 1;		// found
		}

		else if(val < cur->info)
			cur = cur->lChild;	// may be available in the left subtree

		else cur = cur->rChild;		// -,,- in right subtree
	}

	cout << "Not Found\n";
	return 0;				// not found
}

// delete the whole tree
template <class T>
void BST<T>::delete_Tree()
{
	remove(root);						// same as default destructor, but with some exception
	root = NULL;						// initialise root with NULL for further usage
}

// traverse the tree in preOrder
template <class T>
void BST<T>::preOrder()
{
	// call the private preOrder function for recursive implementation
	preOrderP(root);
}

// InOrder
template <class T>
void BST<T>::inOrder()
{
	// call the private inOrder function for recursive implementation
	inOrderP(root);
}

// postOrder
template <class T>
void BST<T>::postOrder()
{
	// call the private postOrder function for recursive implementation
	postOrderP(root);
}
