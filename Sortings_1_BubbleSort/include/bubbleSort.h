/* Implements the bubble sort algo for sorting */
/* uses template for working with different types of data in program */
/* load_input loads the input from the filename given to it as argument */
/* data type is given to the program as a commandline parameters */

/* worst case time complexity = O(n^2) */

#ifndef _BubbleSort_H_
#define _BubbleSort_H_

// declare the class structure
// works for the dataType T
template<class T>
class BubbleSort
{
	private:
		T *arr;			/* pointer of T dataType, memory is allocated to it at run time */
		int num_vals;		/* number of values to sort */

	public:
		BubbleSort();				/* default constructor, initializes the arr, num_vals variables */
		~BubbleSort();				/* default destructor, frees the memory allocated to arr */
		void load_input(char fileName[]);	/* loads the input from the file */
		void print();				/* prints the content of the arr */
		void sort_inc();			/* sorts the data in increasing order */
		void sort_dec();			/* sorts the data in decreasing order */
		void sort_inc_sm_out();			/* sorts in increasing order, but smallest is pushed first */
};

#endif
