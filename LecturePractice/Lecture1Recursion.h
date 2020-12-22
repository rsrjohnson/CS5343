#pragma once

/*
int RPrefixSum(vector<int> v,int i)
{
	if (v.size() == i)
		return s;
	return 

}
*/


vector<double>  prefixAverages2(vector<double>X, int n)
{
	vector<double> A(n,0);
	double	s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + X[i];
		A[i] = s / (i + 1);		
	}

	return A;
}
	


double RprefixAverages(vector<double>X, int n, vector<double> &A)
{
	if (n == 1)
	{
		A[0] = X[0];
		return A[0];
	}

	double t=(X[n - 1] + RprefixAverages(X, n - 1, A));
	A[n - 1] = t/n;
	return t;

}



int ArrayMax(int A[], int n)
{
	int m = A[0];

	for (int i = 0; i < n; i++)
	{
		if (m < A[i])
		{
			m = A[i];
		}
	}

	return m;
}

int RarrayMax(int A[], int n) {
	if (n == 1)
		return A[0];

	return max(A[n - 1], RarrayMax(A, n - 1));
}

int RLinearSum(int A[], int n)
{
	if (n == 1)
		return A[0];

	return A[n - 1] + RLinearSum(A, n - 1);
}


void RReverseArray(int A[], int i, int j)
{
	if (i == j)
		return;

	swap(A[i], A[j]);

	RReverseArray(A, i + 1, j - 1);
}


int power(int x,int n)
{
	if (n == 0)
	{
		return 1;
	}

	return x * power(x, n - 1);
}

int powerLogn(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	int y;
	if (n % 2 == 0)
	{
		y = power(x, n / 2);
		return y * y;
	}

	y = power(x, (n-1) / 2);	
	return x * y * y;

}

int RBinarySum(int A[], int i, float n) //i:start index, n:number of elements
{
	if (n == 1)
		return A[i];

	return RBinarySum(A, i, floor(n / 2)) + RBinarySum(A, i + floor(n / 2),ceil(n / 2));

}

int Fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return Fib(n - 1) + Fib(n - 2);
}

//Fibonacci Memoization
int term[1000];

int FibMEMO(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	if (term[n] != 0)
	{
		return term[n];
	}

	term[n] = FibMEMO(n - 1) + FibMEMO(n - 2);

	return term [n];
}

int RGCD(int b, int a)
{
	if (b < a)
		return RGCD(a, b);
	if (a == 0)
		return b;

	return RGCD(a, b % a);
}


void myFunction(int counter)
{
	cout << "hello " << counter << endl;
	if (counter >0) {
		myFunction(--counter);
		cout << counter << endl;
	}

	return;
}

//check
bool RIsPrime(int n, int i)
{
	if (n % i == 0)
	{
		return false;
	}

	if (i * i > n)
		return true;

	return RIsPrime(n, i + 1);
}

bool RPalindrome(string s,int n)
{
	if (n == 1 || n==0)
		return true;

	bool b = s[0] == s[n - 1];

	return b && RPalindrome(s.substr(1, n - 1), n - 2);
		
}

bool RPalindromeIndex(string s, int i, int n)//n is the size
{
	if (n == 1)
	{
		return true;
	}

	return s[i] == s[n - 1] && RPalindromeIndex(s, i + 1, n - 1);
}