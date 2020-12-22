#pragma once

void insertHeap(vector<int>&A, int val) 
{
	int indx = A[0];
	indx += 1;
	A[indx] = val;
	A[0] += 1;

	int par = indx / 2;

	while (A[par] > A[indx] && par != 0) //for min heap
	{
		swap(A[par], A[indx]);
		indx = par;
		par = indx / 2;
	}

	return;

}

void deleteHeap(vector<int> &A) 
{
	int indx = A[0];
	A[1] = A[indx];
	A[0] -= 1;


	int par = 1;
	int child1 = 2;//2*par
	int child2 = 3;//2*par + 1 

	while (true)
	{
		if (child1 > A[0] && child2 > A[0]) //for max heap
			return;

		if (A[par] > A[child1] && A[par] > A[child2])
			return;

		if (A[child1] < A[child2])
		{
			swap(A[par], A[child2]);
			par = child2;
		}
		else
		{
			swap(A[par], A[child1]);
			par = child1;
		}

		child1 = 2 * par;
		child2 = 2 * par + 1;
	}

}
/*
void percolateDown(vector<int>& A,int ind_par)
{
	int lc = 2 * ind_par;
	int rc = 2 * ind_par+1;
	int smallest_index=ind_par; //for maxHeap, largest_index for minHeap
	if (lc <= A[0])
	{
		if (A[ind_par] > A[lc])//< for maxHeap
			smallest_index = lc;
		if (rc <= A[0])//< for maxHeap
		{
			if(A[smallest_index] > A[rc])
				smallest_index=rc;

		}
		if (smallest_index != ind_par)
			swap(A[ind_par], A[smallest_index]);
		else
			return;

		percolateDown(A, smallest_index);
	}
	
	return;
}
*/


void percolateDown(vector<int>& A, int ind_par)
{
	int lc = 2 * ind_par;
	int rc = 2 * ind_par + 1;
	int greatest_index = ind_par; //for maxHeap, largest_index for minHeap
	if (lc <= A[0])
	{
		if (A[ind_par] < A[lc])//< for maxHeap
			greatest_index = lc;
		if (rc <= A[0])//< for maxHeap
		{
			if (A[greatest_index] < A[rc])
				greatest_index = rc;

		}
		if (greatest_index != ind_par)
			swap(A[ind_par], A[greatest_index]);
		else
			return;

		percolateDown(A, greatest_index);
	}

	return;
}



void FloydHeapify(vector<int>& A)//for minHeap in the percolate down
{
	int last_par = A[0] / 2;

	while (last_par > 0)
	{
		percolateDown(A, last_par);

		last_par--;
	}
}

void HeapSort(vector<int>& A)
{
	FloydHeapify(A);

	while (A[0] > 1)
	{
		swap(A[1], A[A[0]]);
		A[0]--;
		percolateDown(A, 1);
	}
	return;
}