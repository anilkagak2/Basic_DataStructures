/* defining the member functions of the class QuickSort */
/* except for the sorting methods all other methods remains same */
/* drawbacks --> ##1 traversing the same file twice */

#include "../include/QuickSort.h"
#include <iostream>
#include <fstream>
using namespace std;

// 1
/* default constructor, initializes the arr, num_vals variables */
template<class T>
QuickSort<T>::QuickSort()
{
	arr = NULL;		/* pointer to the array structure */
	num_vals = 0;		/* number of values in the array */
}

// 2
/* default destructor, frees the memory allocated to arr */
template<class T>
QuickSort<T>::~QuickSort()
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
void QuickSort<T>::load_input(char fileName[])
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
void QuickSort<T>::print()
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
void QuickSort<T>::sort_inc()
{
	/* call the private sorting member function */
	Quick_Sort(arr,0,num_vals);
}

// 6
/* Quicks the two sorted arrays, left-->mid and mid+1-->right */
template<class T>
int QuickSort<T>::Partition1(T a[],int left,int right)
{
	T x = a[left];		/* choose the pivot */
	int l = left+1, r = right;	

	// main partition routine
	while(l<r)
	{
		cout << l << " ";
		// till a[l] is lesser than x move l one step ahead
		while(l<=right && a[l]<x)
		l++;

		// till a[l] is greater than x move l one step behind
		while(r>left && a[r]>=x)
		r--;

		// exchange a[l],a[r]
		if( l < r)
		{
			T tmp = a[l];
			a[l] = a[r];
			a[r] = tmp;
		}
	}

	// exchange a[r], pivot
	//if(a[r] < x)
	{
		a[left] = a[r];
		a[r] = x;
	}

	// return pivot's position
	return r;
}

// 7
/* Quicks the two sorted arrays, left-->mid and mid+1-->right */
template<class T>
int QuickSort<T>::Partition2(T a[],int left,int right)
{
	T x = a[left];
	int i = left;
	int j = left+1;

	for(;j<=right;j++)
	{
		// exchange a[i],a[j]
		if(a[j]<x)
		{
			i++;
			T tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
	}

	a[left] = a[i];
	a[i] = x;

	return i;
}


// 8
/* recursive procedural call for sorting */
template<class T>
void QuickSort<T>::Quick_Sort(T A[],int left,int right)
{
	// if array size is greater than 1
	if(left < right)
	{
		/* pivot is placed at its final position in the sorted array */
		int q = Partition1(A,left,right);	/* partitions the array, returns the pivot's index */
		Quick_Sort(A,left,q-1);			/* sort the first half of the array */
		Quick_Sort(A,q+1,right);		/* sort the second half of the array */
	}
}
