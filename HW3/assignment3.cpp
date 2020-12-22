//Student Name: Randy Suarez Rodes
//Course: CS 5343
//Assignment #3
//June 30, 2020
//This program was written on c++, run on Visual Studio Community 2019 on Windows 10.

#include<iostream>

using namespace std;

//Declarations
void printArray(int A[], int n);
void percolateDown(int A[], int ind_par);
void FloydminHeap(int A[]);
void HeapSort(int A[]);

int main()
{
	int A[]={15, 30, 17, 24, 9, 11, 2, 1, 15, 14, 28, 35, 19, 100, 6, 13}; //array to handle the heap, note that the first index holds the size of the heap
																		   //make sure to modify the size accordingly to generate other sizes examples
	int n = sizeof(A) / sizeof(A[0]);

	cout << "Original Array" << endl;
	printArray(A, n);

	cout << "Array as MinHeap" << endl;
	FloydminHeap(A);//modifying the array into a heap structure
	printArray(A, n);

	cout << "Sorted Array" << endl;
	HeapSort(A);//sorting the array using HeapSort
	printArray(A, n);

	return 0;
}

//Definitions
void printArray(int A[], int n) //function to print out the array leaving out the first index, which holds the size of the heap
{
	for (int i = 1; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

void percolateDown(int A[], int ind_par) //function to create a heap in the subtree starts from the index of a given node
{
	//storing the possible children's indexes
	int lc = 2 * ind_par;
	int rc = 2 * ind_par + 1;

	int smallest_index = ind_par;

	//checking for the existance of the left child, otherwise we are in a leaf, the heap structure is garanteed for a leaf
	if (lc <= A[0])
	{
		if (A[ind_par] > A[lc]) //if the left child is less than the current minimum we update it
			smallest_index = lc; //saving the smallest child so far

		if (rc <= A[0]) //checking for the existance of the right child
		{
			if (A[smallest_index] > A[rc]) //if the right child is less than the current minimum we update it
				smallest_index = rc;

		}
		if (smallest_index != ind_par)//if we have changed the index, this means we have to swap the values in order to keep the heap structure
		{
			swap(A[ind_par], A[smallest_index]);
			percolateDown(A, smallest_index); //we continue to percolate down from the current smallest child
		}
	}
	return;
}

void FloydminHeap(int A[])//Floyd's algorithm to construct a minHeap
{
	int last_par = A[0] / 2; //saving the last parent

	while (last_par > 0)
	{
		percolateDown(A, last_par);// we percolate down from the current parent

		last_par--;//we repeat the process with the previous parent until we have checked all parents 
	}
	return;
}

void HeapSort(int A[])
{
	while (A[0] > 1)//we repeat the process until we have a heap of size 1, at that time the array will be sorted
	{
		swap(A[1], A[A[0]]);//in a minHeap we have the least value at the root, therefore we swap it with the current last value 
		A[0]--;//reducing the size of the heap
		percolateDown(A, 1);//percolate down from the root to restore the heap structure
	}
	return;
}