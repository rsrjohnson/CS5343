#pragma once

#define NZ 12 

int arrayset[NZ];

void make_set(int x)
{
	for (int i = 0; i < NZ; i++)
		arrayset[i] = -1;
}



int find_set(int x)
{
	if (arrayset[x] < 0)
		return x;
	return find_set(arrayset[x]);
}

int find_set_pc(int x)
{
	if (arrayset[x] < 0)
		return x;
	arrayset[x] = find_set_pc(arrayset[x]);
	return arrayset[x];
}


void union_weight(int x, int y)
{
	int par_A = find_set(x);
	int par_B = find_set(y);

	int size_A = -1 * arrayset[par_A];
	int size_B = -1 * arrayset[par_B];

	if (size_A < size_B)
	{
		arrayset[par_B] -= size_A;
		arrayset[par_A] = par_B;
		
	}
	else
	{
		arrayset[par_A] -= size_B;
		arrayset[par_B] = par_A;		
	}
}


void union_height(int x, int y)
{
	int par_A = find_set(x);
	int par_B = find_set(y);

	int rank_A = -1 * arrayset[par_A];
	int rank_B = -1 * arrayset[par_B];

	if (rank_A < rank_B)
		arrayset[par_A] = par_B;
	else
	{
		arrayset[par_B] = par_A;
		if (rank_A == rank_B)
			arrayset[par_A]--;
	}
}


void union_weight_pc(int x, int y)
{
	int par_A = find_set_pc(x);
	int par_B = find_set_pc(y);

	int size_A = -1 * arrayset[par_A];
	int size_B = -1 * arrayset[par_B];

	if (size_A < size_B)
	{
		arrayset[par_B] -= size_A;
		arrayset[par_A] = par_B;

	}
	else
	{
		arrayset[par_A] -= size_B;
		arrayset[par_B] = par_A;
	}
}