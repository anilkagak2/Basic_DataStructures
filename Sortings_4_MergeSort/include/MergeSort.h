/* Implements the Merge sort algo for sorting */
/* uses template for working with different types of data in program */
/* load_input loads the input from the filename given to it as argument */
/* data type is given to the program as a commandline parameters */

/* Divide and Conquer Approach for sorting is used */
/* recurrence relation, T(n) = 2T(n/2) + O(n) */

/* worst case time complexity = O(n*lg(n)) */

#ifndef _MergeSort_H_
#define _MergeSort_H_

// declare the class structure
// works for the dataType T
template<class T>
class MergeSort
{
	private:
		T *arr;							/* pointer of T dataType, memory is allocated to it at run time */
		int num_vals;						/* number of values to sort */
		void Merge_inc(T A[],int left,int mid,int right);	/* merges the two sorted arrays, left-->mid and mid+1-->right */
		void Merge_dec(T A[],int left,int mid,int right);	/* merges the two sorted arrays, left-->mid and mid+1-->right */
		void Merge_Sort(T A[],int left,int right,bool x);	/* recursive procedural call for sorting, x=0 means decreasing & x = 1 eans increasing */

	public:
		MergeSort();				/* default constructor, initializes the arr, num_vals variables */
		~MergeSort();				/* default destructor, frees the memory allocated to arr */
		void load_input(char fileName[]);	/* loads the input from the file */
		void print();				/* prints the content of the arr */
		void sort_inc();			/* sorts the data in increasing order */
		void sort_dec();			/* sorts the data in decreasing order */
};

#endif
