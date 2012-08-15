/* defining the member functions of the class MergeSort */
/* except for the sorting methods all other methods remains same */
/* drawbacks --> ##1 traversing the same file twice */

#include "../include/MergeSort.h"
#include <iostream>
#include <fstream>
using namespace std;

// 1
/* default constructor, initializes the arr, num_vals variables */
template<class T>
MergeSort<T>::MergeSort()
{
	arr = NULL;		/* pointer to the array structure */
	num_vals = 0;		/* number of values in the array */
}

// 2
/* default destructor, frees the memory allocated to arr */
template<class T>
MergeSort<T>::~MergeSort()
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
void MergeSort<T>::load_input(char fileName[])
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
void MergeSort<T>::print()
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
void MergeSort<T>::sort_inc()
{
	/* call the private sorting member function */
	Merge_Sort(arr,0,num_vals,1);
}

// 6
/* sorts the data in decreasing order */
template<class T>
void MergeSort<T>::sort_dec()
{
	/* call the private sorting member function */
	Merge_Sort(arr,0,num_vals,0);
}

// 7
/* merges the two sorted arrays, left-->mid and mid+1-->right */
template<class T>
void MergeSort<T>::Merge_inc(T A[],int left,int mid,int right)
{
	/* check whether the arrays are in order or not */
	if(A[mid] < A[mid+1])
	{
		return ;			/* no need to merge them */
	}

	int len = right-left+1;			/* need the length for allocating a new array for merging these two */
	T *b = new(T[len]);			/* allocate the space for temporary storage */

	int i = left, j = mid+1, k = 0;		/* indices fortravelling through the array */

	// traverse both the arrays and compare the elements and place the smaller one into the array b[]
	// till one of the array is exhausted
	for(;i<=mid && j<=right;)
	{
		if(A[i] < A[j])
		{
			b[k++] = A[i++];	/* place A[i] at b[k], then increment both the indices */
		}

		else
		{
			b[k++] = A[j++];	/* place A[j] at b[k], then increment both the indices */
		}
	}

	/* check which one is exhausted */
	if(i<=mid)
	{
		/* append the rest of 1st array to b */
		while(i <= mid)
		{
			b[k++] = A[i++];
		}
	}

	else
	{
		/* append the rest of 2nd array to b */
		while(j <= right)
		{
			b[k++] = A[j++];
		}
	}

	// copy the array back to A and delete b
	for(i = left,k=0; i<=right;i++,k++)
	{
		A[i] = b[k];
	}

	delete[] b;
}

// 8
/* merges the two sorted arrays, left-->mid and mid+1-->right */
template<class T>
void MergeSort<T>::Merge_dec(T A[],int left,int mid,int right)
{
	/* check whether the arrays are in order or not */
	if(A[mid] > A[mid+1])
	{
		return ;			/* no need to merge them */
	}

	int len = right-left+1;			/* need the length for allocating a new array for merging these two */
	T *b = new(T[len]);			/* allocate the space for temporary storage */

	int i = left, j = mid+1, k = 0;		/* indices fortravelling through the array */

	// traverse both the arrays and compare the elements and place the larger one into the array b[]
	// till one of the array is exhausted
	for(;i<=mid && j<=right;)
	{
		if(A[i] > A[j])
		{
			b[k++] = A[i++];	/* place A[i] at b[k], then increment both the indices */
		}

		else
		{
			b[k++] = A[j++];	/* place A[j] at b[k], then increment both the indices */
		}
	}

	/* check which one is exhausted */
	if(i<=mid)
	{
		/* append the rest of 1st array to b */
		while(i <= mid)
		{
			b[k++] = A[i++];
		}
	}

	else
	{
		/* append the rest of 2nd array to b */
		while(j <= right)
		{
			b[k++] = A[j++];
		}
	}

	// copy the array back to A and delete b
	for(i = left,k=0; i<=right;i++,k++)
	{
		A[i] = b[k];
	}
	delete[] b;
}


// 9
/* recursive procedural call for sorting */
template<class T>
void MergeSort<T>::Merge_Sort(T A[],int left,int right,bool x)
{
	// if array size is greater than 1
	if(left < right)
	{
		int mid = (left+right)/2;		/* calculate the middle element */
		Merge_Sort(A,left,mid,x);		/* sort the first half of the array */
		Merge_Sort(A,mid+1,right,x);		/* sort the second half of the array */

		if(x)
		Merge_inc(A,left,mid,right);		/* merge the solutions of both the half */

		else  Merge_dec(A,left,mid,right);	/* merge the solutions of both the half, decreasing sort */
	}
}
