#pragma once
#include<vector>


void  printArray(vector<int>v, int n)
{
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
}

/*
void QuickSort(vector<int>& v, int start, int end)
{
	int pivot, i, j;
	if (start < end)
	{
		pivot = start;
		i = start + 1;
		j = end;
		while (i <= j)
		{
			while (v[i] <= v[pivot] && i <= j)  i++;
			while (v[j] >= v[pivot] && i <= j) 	j--;
			if (i <= j)
				swap(v[i], v[j]);
			printArray(v, 11);
		}
		swap(v[pivot], v[j]);
		printArray(v, 11);
		QuickSort(v, start, j - 1); // sort first partition
		QuickSort(v, j + 1, end); // sort second partition 
	}
}
*/

void QuickSort(vector<int>& v, int l, int r)
{
	if (l < r)
	{

		int p = v[l];

		int pi = l;

		int LA = l + 1;
		int RA = r;
		while (LA < RA)
		{
			while (p <= v[RA] && LA < RA)//>= descending
			{
				RA--;
			}

			while (p >= v[LA] && LA < RA)//<= descending
			{
				LA++;
			}
			if (LA < RA)
				swap(v[LA], v[RA]);

			printArray(v, v.size());
		}

		if (p > v[LA])//< for descending
		{
			swap(v[pi], v[LA]);
			pi = LA;
		}
		else
		{
			swap(v[pi], v[LA - 1]);
			pi = LA - 1;
		}
		printArray(v, v.size());
		QuickSort(v, l, pi - 1);
		QuickSort(v, pi + 1, r);
	}
	return;
}



/*
void QuickSort(vector<int>& list, int left, int right)
{
	int pivot, leftArrow, rightArrow;
	leftArrow = left+1;
	rightArrow = right;
	pivot = list[left];
	while (rightArrow > leftArrow)
	{
		while (list[rightArrow] > pivot)
			--rightArrow;
		while (list[leftArrow] < pivot)
			++leftArrow;
		if (leftArrow <= rightArrow)
		{
			swap(list[leftArrow], list[rightArrow]);
			++leftArrow;
			--rightArrow;
		}
	}
	if (left < rightArrow)
		QuickSort(list, left, rightArrow);
	if (leftArrow < right)
		QuickSort(list, leftArrow, right);
}
*/

