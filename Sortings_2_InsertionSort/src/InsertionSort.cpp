/* defining the member functions of the class InsertionSort */
/* except for the sorting methods all other methods remains same */
/* drawbacks --> ##1 traversing the same file twice */

#include "../include/InsertionSort.h"
#include <iostream>
#include <fstream>
using namespace std;

// 1
/* default constructor, initializes the arr, num_vals variables */
template<class T>
InsertionSort<T>::InsertionSort()
{
	arr = NULL;		/* pointer to the array structure */
	num_vals = 0;		/* number of values in the array */
}

// 2
/* default destructor, frees the memory allocated to arr */
template<class T>
InsertionSort<T>::~InsertionSort()
{
	/* delete the arr if it is not NULL */
	if(arr)
	{
		delete[] arr;
	}
}

// 3
/* file will only contain the data, not the datatype as string */
/* datatype for the program will be given via commandline */
/* loads the input from the file stream */
template<class T>
void InsertionSort<T>::load_input(char fileName[])
{
	/* will be traversing the file twice */
	/* 1--> for noting the number of elements in the file */
	/* 2--> for taking out the input */

	/* opening the file for reading */
	ifstream fp;
	fp.open(fileName);

	/* checking the stream for errors */
	if(!fp)
	{
		cout << "Error Occurred in opening the file\n";
		return ;
	}

	T tmp;

	/* counts the number of elements */
	int count = 0;
	// till the end of file is reached
	while(fp.eof() == 0)
	{
		fp >> tmp;	/* take the input to the tmp */

		/* if end of file is hit */
		if(fp.eof() == 1)
		break;

		count++;	/* increase the count */
	}

	// number of elements
	num_vals = count;

	// remove the bag state of the file
	fp.clear();

	// move file pointer to the beginning of the file
	fp.seekg(0,ios::beg);

	//allocate space for count number of integers
	arr = new T[count];

	int i = 0;
	// read the elemtents
	while(fp.eof() == 0)
	{
		fp >> arr[i];	/* take the input to the tmp */
		i++;	/* increase the count */

		/* if end of file is hit */
		if(fp.eof() == 1)
		break;
	}

	fp.close();
}

// 4
/* prints the content of the arr */
template<class T>
void InsertionSort<T>::print()
{
	// print the list
	for(int i =0;i<num_vals;i++)
	{
		cout << arr[i] << "->";
	}
}

// 5
/* sorts the data in increasing order */
template<class T>
void InsertionSort<T>::sort_inc()
{
	// sort the data in increasing order
	int i,j;

	// in each ith iteration place the ith element in array --> 0 to i-1, in sorted order
	for(i=1;i<num_vals;i++)
	{
		// store the key
		T key = arr[i];

		// start at i-1, search for the position x where a[x-1] is smaller than key
		for(j=i-1;j>=0 && arr[j]>key;j--)
		{
			// move a[j] one step ahead in the array
			arr[j+1] = arr[j];
		}

		// place the key at j
		arr[++j] = key;
	}
}

// 6
/* sorts the data in decreasing order */
template<class T>
void InsertionSort<T>::sort_dec()
{
	// sort the data in decreasing order
	int i,j;

	// in each ith iteration place the ith element in array --> 0 to i-1, in sorted order
	for(i=1;i<num_vals;i++)
	{
		// store the key
		T key = arr[i];

		// start at i-1, search for the position x where a[x-1] is larger than key
		for(j=i-1;j>=0 && arr[j]<key;j--)
		{
			// move a[j] one step ahead in the array
			arr[j+1] = arr[j];
		}

		// place the key at j
		arr[++j] = key;
	}

}
