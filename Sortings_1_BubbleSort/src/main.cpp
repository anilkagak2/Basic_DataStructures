/* use the bubble sort class */
/* datatype is given as commandline argument */
/* input is taken from  file specified by cmd arg */

#include <iostream>
#include <string>
#include "bubbleSort.cpp"
using namespace std;

int main(int argc,char* argv[])
{
	/* check for the correct number of inputs */
	if(argc != 3)
	{
		cout << "Error: Wrong number of arguments\n";
		cout << "Usage: ./bubbleSort datatype input_file\n";
		return 1;
	}

	/* take datatype string into a string object */
	string dType = argv[1];

	// if datatype is int
	if(dType == "int")
	{

		/* declare the object of its type */
		BubbleSort<int> bs;

		/* load the input array */
		bs.load_input(argv[2]);

		bs.print();		// print the array
		cout << endl;		
		bs.sort_inc();		// sort the array in increasing order
		cout << "increasing order :";
		bs.print();		// print the array
		cout << endl;
		bs.sort_dec();		// sort the array in decreasing order
		cout << "decreasing order :";
		bs.print();		// print the array
		cout << endl;
	}

	// if datatype is string
	else if(dType == "string")
	{

		/* declare the object of its type */
		BubbleSort<string> bs;

		/* load the input array */
		bs.load_input(argv[2]);

		bs.print();		// print the array
		cout << endl;		
		bs.sort_inc();		// sort the array in increasing order
		cout << "increasing order :";
		bs.print();		// print the array
		cout << endl;
		cout << "decreasing order :";
		bs.sort_dec();		// sort the array in decreasing order
		bs.print();		// print the array
		cout << endl;
	}

	// if datatype is char
	else if(dType == "char")
	{

		/* declare the object of its type */
		BubbleSort<char> bs;

		/* load the input array */
		bs.load_input(argv[2]);

		bs.print();		// print the array
		cout << endl;		
		bs.sort_inc();		// sort the array in increasing order
		cout << "increasing order :";
		bs.print();		// print the array
		cout << endl;
		bs.sort_dec();		// sort the array in decreasing order
		cout << "decreasing order :";
		bs.print();		// print the array
		cout << endl;
	}


	// if datatype is float
	else if(dType == "float")
	{

		/* declare the object of its type */
		BubbleSort<float> bs;

		/* load the input array */
		bs.load_input(argv[2]);

		bs.print();		// print the array
		cout << endl;		
		bs.sort_inc();		// sort the array in increasing order
		cout << "increasing order :";
		bs.print();		// print the array
		cout << endl;
		bs.sort_dec();		// sort the array in decreasing order
		cout << "decreasing order :";
		bs.print();		// print the array
		cout << endl;
	}

	else
	{
		cout << "Unknown datatype\n";
	}

	return 0;
}
