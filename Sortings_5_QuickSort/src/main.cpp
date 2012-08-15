/* use the Quick sort class */
/* datatype is given as commandline argument */
/* input is taken from  file specified by cmd arg */

#include <iostream>
#include <string>
#include "QuickSort.cpp"
using namespace std;

int main(int argc,char* argv[])
{
	/* check for the correct number of inputs */
	if(argc != 3)
	{
		cout << "Error: Wrong number of arguments\n";
		cout << "Usage: ./QuickSort datatype input_file\n";
		return 1;
	}

	/* take datatype string into a string object */
	string dType = argv[1];

	// if datatype is int
	if(dType == "int")
	{

		/* declare the object of its type */
		QuickSort<int> is;

		/* load the input array */
		is.load_input(argv[2]);

		is.print();		// print the array
		cout << endl;		
		is.sort_inc();		// sort the array in increasing order
		cout << "increasing order :";
		is.print();		// print the array
		cout << endl;
	}

	// if datatype is string
	else if(dType == "string")
	{

		/* declare the object of its type */
		QuickSort<string> is;

		/* load the input array */
		is.load_input(argv[2]);

		is.print();		// print the array
		cout << endl;		
		is.sort_inc();		// sort the array in increasing order
		cout << "increasing order :";
		is.print();		// print the array
		cout << endl;
	}

	// if datatype is char
	else if(dType == "char")
	{

		/* declare the object of its type */
		QuickSort<char> is;

		/* load the input array */
		is.load_input(argv[2]);

		is.print();		// print the array
		cout << endl;		
		is.sort_inc();		// sort the array in increasing order
		cout << "increasing order :";
		is.print();		// print the array
		cout << endl;
	}


	// if datatype is float
	else if(dType == "float")
	{

		/* declare the object of its type */
		QuickSort<float> is;

		/* load the input array */
		is.load_input(argv[2]);

		is.print();		// print the array
		cout << endl;		
		is.sort_inc();		// sort the array in increasing order
		cout << "increasing order :";
		is.print();		// print the array
		cout << endl;
	}

	else
	{
		cout << "Unknown datatype\n";
	}

	return 0;
}
