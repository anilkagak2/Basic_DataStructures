/* defining the member functions of the class SelectionSort */
/* except for the sorting methods all other methods remains same */
/* drawbacks --> ##1 traversing the same file twice */

#include "../include/SelectionSort.h"
#include <iostream>
#include <fstream>
using namespace std;

// 1
/* default constructor, initializes the arr, num_vals variables */
template<class T>
SelectionSort<T>::SelectionSort()
{
	arr = NULL;		/* pointer to the array structure */
	num_vals = 0;		/* number of values in the array */
}

// 2
/* default destructor, frees the memory allocated to arr */
template<class T>
SelectionSort<T>::~SelectionSort()
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
void SelectionSort<T>::load_input(char fileName[])
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
void SelectionSort<T>::print()
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
void SelectionSort<T>::sort_inc()
{
	// sort the data in increasing order
	int i,j;

	// in each ith iteration place the ith smallest element in array at (i-1)th array index
	for(i=0;i<num_vals;i++)
	{
		// values of the min of the ith iteration
		T min_i = arr[i];
		int index = i;

		// start at i+1, search for the smallest element in the remaining i-->n-1 positions
		for(j=i+1;j<num_vals;j++)
		{
			// check whether the element at this position is less than the min_i or not
			if(arr[j] < min_i)
			{
				min_i = arr[j];		// store it into the min_i
				index = j;		// change the index to j
			}
		}

		// if i != index, then swap them
		if(i != index)
		{
			T tmp = arr[i];
			arr[i] = arr[index];
			arr[index] = tmp;
		}
	}
}

// 6
/* sorts the data in decreasing order */
template<class T>
void SelectionSort<T>::sort_dec()
{
	// sort the data in decreasing order
	int i,j;

	// in each ith iteration place the ith largest element in array at (i-1)th array index
	for(i=0;i<num_vals;i++)
	{
		// values of the max of the ith iteration
		T max_i = arr[i];
		int index = i;

		// start at i+1, search for the largest element in the remaining i-->n-1 positions
		for(j=i+1;j<num_vals;j++)
		{
			// check whether the element at this position is greater than the max_i or not
			if(arr[j] > max_i)
			{
				max_i = arr[j];		// store it into the min_i
				index = j;		// change the index to j
			}
		}

		// if i != index, then swap them
		if(i != index)
		{
			T tmp = arr[i];
			arr[i] = arr[index];
			arr[index] = tmp;
		}
	}
}
