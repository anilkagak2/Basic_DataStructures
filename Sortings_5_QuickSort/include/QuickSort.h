/* Implements the Quick sort algo for sorting */
/* uses template for working with different types of data in program */
/* load_input loads the input from the filename given to it as argument */
/* data type is given to the program as a commandline parameters */

/* Divide and Conquer Approach for sorting is used */
/* Dividing the array given into two arrays acc. to pivot choosen  among them */
/* one--> elements <= pivot and other elements >= pivot */
/* best case recurrence relation, T(n) = 2T(n/2) + O(n) */
/* worst case recurrence relation, T(n) = T(n-1) + T(1) + O(n) */

/* worst case time complexity = O(n^2) */
/* average case time complexity = O(n*lg(n)) */

/* for better performance, use Randomized_Quick_Sort, in which pivot is choosen randomly */

#ifndef _QuickSort_H_
#define _QuickSort_H_

// declare the class structure
// works for the dataType T
template<class T>
class QuickSort
{
	private:
		T *arr;							/* pointer of T dataType, memory is allocated to it at run time */
		int num_vals;						/* number of values to sort */
		int Partition1(T A[],int left,int right);		/* Partitions the array into two arrays, first approach */
		int Partition2(T A[],int left,int right);		/* Partitions the array into two arrays, second approach */
		void Quick_Sort(T A[],int left,int right);		/* recursive procedural call for sorting */

	public:
		QuickSort();				/* default constructor, initializes the arr, num_vals variables */
		~QuickSort();				/* default destructor, frees the memory allocated to arr */
		void load_input(char fileName[]);	/* loads the input from the file */
		void print();				/* prints the content of the arr */
		void sort_inc();			/* sorts the data in increasing order */
};

#endif
