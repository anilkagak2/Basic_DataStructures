/***********************************************************************************
*	Name:		Binary Search Tree
*	Author:		Anil Kag
*	Purpose:	Main Routine of this menu driven Program
*	
*
*	NOT TESTED THOROUGHLY, IF ANY BUG IS FOUND PLEASE REPORT IT TO ME
*	
***********************************************************************************/

#include <iostream>
#include <cstdlib>
#include "bst.cpp"			// need to know the different specialization of template functions
					// not possible with bst.h header(without the explicit specialization of the templates)

using namespace std;

int showOptions()
{
	int choice;
	// MENU of the program
	cout << "Binary Search Tree\n"
		<< "Menu\n";

	cout << "Choose one of the following\n";
	cout << "\t1)Create Tree(from a file)\n";
	cout << "\t2)Insert a node\n";
	cout << "\t3)Delete a node\n";
	cout << "\t4)Search a node\n";
	cout << "\t5)Delete the whole tree\n";
	cout << "\t6)Print the tree\n";
	cout << "\t7)Exit\n";

	cin >> choice;			// take the choice

	cin.clear();
	// TRY ENTERING A STRING
	if(choice <1 || choice >7)
	{
		cout << "System cannot Handle this string :P :P\n";
		cout << "Exiting gracefully\n :P";
		exit(1);
	}

	return choice;
}

int chooseDataType()
{
	int i;
	cout << "Select from the following\n";
	cout << "\t1)int\n";
	cout << "\t2)char\n";

	cin >> i;

	if(i<1 || i>2)
	return -1;

	else return i;
}

int chooseOrder()
{
	int i;
	cout << "Select from the following\n";
	cout << "\t1)Inorder\n";
	cout << "\t2)Preorder\n";
	cout << "\t3)Postorder\n";

	cin >> i;

	if(i<1 || i>3)
	return -1;

	else return i;
}

int main(int argc, char *argv[])
{
	int choice = 1;			// which option
	int dataType = 1;		// which dataType for the BST
	int whichOrder = 1;		// which order is to be used in the Print

	BST<int> bst_i;			// BST for int
	BST<char> bst_c;		// BST for char

	while(1)
	{
		choice = showOptions();		// show the options
		switch(choice)
		{
			// CREATE from FILE
			case 1:
				dataType = chooseDataType();

				// int 
				if(dataType == 1)
				{
					string file;

					cout << "Input file Name\n";
					cin >> file;

					bst_i.createFromFile(file.c_str());
				}

				// char
				else if(dataType == 2)
				{
					string file;

					cout << "Input file Name\n";
					cin >> file;

					bst_c.createFromFile(file.c_str());
				}
				
				else
				{
					cout << "wrong selection\n";
				}

				break;

			// INSERT a node
			case 2:
				if(dataType == 1)
				{
					int tmp;
					cout << "Enter an integer\n";
					cin >> tmp;

					bst_i.insert(tmp);
				}

				else if(dataType == 2)
				{
					char tmp;
					cout << "Enter a character\n";
					cin >> tmp;

					bst_c.insert(tmp);
				}
				else {}

				break;

			// DELETE a node
			case 3:
				break;

			// SEARCH a node
			case 4:
				cout << "Enter the value to be searched\n";
				if(dataType == 1)
				{
					int tmp;
					cin >> tmp;

					bst_i.search(tmp);
				}

				else if(dataType == 2)
				{
					char tmp;
					cin >> tmp;

					bst_c.search(tmp);
				}

				break;

			// DELETE Tree
			case 5:
				if(dataType == 1)
				bst_i.delete_Tree();

				else if(dataType == 2)
				bst_c.delete_Tree();

				else
				{
				}

				break;
			case 6:
				whichOrder = chooseOrder();

				if(dataType == 1)
				{
					if(whichOrder == 1)
					bst_i.inOrder();

					else if(whichOrder == 2)
					bst_i.preOrder();

					else if(whichOrder == 3)
					bst_i.postOrder();


					else
					{
						cout << "wrong selection\n";
					}
				}

				else if(dataType == 2)
				{
					if(whichOrder == 1)
					bst_c.inOrder();

					else if(whichOrder == 2)
					bst_c.preOrder();

					else if(whichOrder == 3)
					bst_c.postOrder();


					else
					{
						cout << "wrong selection\n";
					}
				}

				else
				{
					cout << "wrong selection\n";
				}

				break;

			// EXIT
			case 7:
				exit(0);
				break;

			// INCORRECT option
			default:
				cout << "Choice is incorrect\n";
		}
	}

	return 0;
}
