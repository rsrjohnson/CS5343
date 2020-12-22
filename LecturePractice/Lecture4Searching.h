#pragma once

int BinSearch(int A[], int n, int val)
{
	int l = 0;
	int r = n - 1;

		while (l < r)
		{
			int m = (l + r) / 2;

				if (A[m] > val)
				{
					r = m - 1;
				}
			if (A[m] < val)
			{
				l = m + 1;
			}

			if (A[m] == val)
				return m;
		}

	return -1;

}

int rBinSearch(int A[], int val, int l, int r) //call rBinSearch(v,val,0,n-1)
{
	if (l >= r)
		return -1;

	int m = (l + r) / 2;

	if (A[m] == val)
		return m;

	if (A[m] > val)
		return rBinSearch(A, val, l, m - 1);

	else
		return rBinSearch(A, val, m + 1, r);
}


void SelectionSort(int* a, int len)
{
	int i, j, smallindex, tmp;

	for (i = 0; i < len; i++) {
		smallindex = i;
		for (j = i + 1; j < len; j++) {
			if (a[j] < a[smallindex]) {
				smallindex = j;
			}
		}
		if (smallindex != i) {
			tmp = a[i];
			a[i] = a[smallindex];
			a[smallindex] = tmp;
		}
	}
}