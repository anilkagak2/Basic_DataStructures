/* defining the member functions of the class BubbleSort */

/* drawbacks --> ##1 traversing the same file twice */

#include "../include/bubbleSort.h"
#include <iostream>
#include <fstream>
using namespace std;

// 1
/* default constructor, initializes the arr, num_vals variables */
template<class T>
BubbleSort<T>::BubbleSort()
{
	arr = NULL;		/* pointer to the array structure */
	num_vals = 0;		/* number of values in the array */
}

// 2
/* default destructor, frees the memory allocated to arr */
template<class T>
BubbleSort<T>::~BubbleSort()
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
void BubbleSort<T>::load_input(char fileName[])
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
void BubbleSort<T>::print()
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
void BubbleSort<T>::sort_inc()
{
	// sort the data in increasing order
	// push the largest data (comparison wise) to the last
	for(int outer=num_vals-1; outer>0;outer--)
	{
		// for each loop, through it's largest element to the last
		for(int inner=0;inner<outer;inner++)
		{
			// swap if the a[inner+1] is smaller than a[inner]
			if(arr[inner]>arr[inner+1])
			{
				T tmp = arr[inner];
				arr[inner] = arr[inner+1];
				arr[inner+1] = tmp;
			}
		}
	}
}

// 6
/* sorts the data in decreasing order */
template<class T>
void BubbleSort<T>::sort_inc_sm_out()
{
	// sort the data in decreasing order
	// push the smallest data (comparison wise) to the first
	for(int outer=0; outer<num_vals;outer++)
	{
		// for each loop, through it's smallest element to the first in it
		for(int inner=num_vals-1;inner>outer;inner--)
		{
			// swap if the a[inner+1] is smaller than a[inner]
			if(arr[inner]<arr[inner-1])
			{
				T tmp = arr[inner];
				arr[inner] = arr[inner-1];
				arr[inner-1] = tmp;
			}
		}
	}
}

// 7
/* sorts the data in decreasing order */
template<class T>
void BubbleSort<T>::sort_dec()
{
	// sort the data in decreasing order
	// push the smallest data (comparison wise) to the last
	for(int outer=num_vals-1; outer>0;outer--)
	{
		// for each loop, through it's smallest element to the last
		for(int inner=0;inner<outer;inner++)
		{
			// swap if the a[inner+1] is larger than a[inner]
			if(arr[inner]<arr[inner+1])
			{
				T tmp = arr[inner];
				arr[inner] = arr[inner+1];
				arr[inner+1] = tmp;
			}
		}
	}
}
