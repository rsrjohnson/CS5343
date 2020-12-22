#pragma once
#include<algorithm>
#include "Lecture10QuickSort.h"

using namespace std;

struct AVLNode {
	int val;
	AVLNode* left;
	AVLNode* right;
	AVLNode* parent;
	int ht;
};


AVLNode* insertBST(AVLNode* &root, AVLNode *n) {
	if (n->val < root->val)
	{
		if (root->left == NULL)
		{
			root->left = n;
			root->left->parent = root;			
		}
		else return insertBST(root->left, n);
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = n;
			root->right->parent = root;
		}
		else return insertBST(root->right, n);
	}
	//root->ht =max(root->left->ht,root->right->ht)+1;
	return n;
}

int height(AVLNode* root)
{
	if (root == NULL)
		return -1;

	return 1 + max(height(root->left), height(root->right));
}


int getleftht(AVLNode* root)
{
	return height(root->left);
}
int getrightht(AVLNode* root)
{
	return height(root->right);
}

void balanceleftStline(AVLNode* &root,AVLNode* n1, AVLNode* n2, AVLNode* n3) {
	AVLNode* par = n1->parent;
	if (par != NULL)
		par->left = n2;	
	n1->left = n2->right;
	n1->parent = n2;
	if(n2->right!=NULL)
		n2->right->parent = n1;
	n2->parent = par;
	if(par==NULL){root=n2;}	
	n2->right = n1;	
}

void balancerightStline(AVLNode* &root,AVLNode* n1, AVLNode* n2, AVLNode* n3)
{
	AVLNode* par = n1->parent;
	if (par != NULL)
		par->right = n2;
	n1->right = n2->left;
	n1->parent = n2;
	if(n2->left!=NULL)
		n2->left->parent = n1;
	n2->parent = par;
	if(par==NULL){root=n2;}	
	n2->left = n1;
}

void balancezigzagleft(AVLNode*& root, AVLNode* n1, AVLNode* n2, AVLNode* n3)
{
	n1->left = n3;
	n3->parent = n1;
	n2->right = n3->left;
	if (n3->left != NULL)
		n3->left->parent = n2;
	n3->left = n2;
	n2->parent = n3;

	balanceleftStline(root, n1, n3, n2);
}



void balancezigzagright(AVLNode*& root,AVLNode* n1, AVLNode* n2, AVLNode* n3)
{
	n1->right = n3;
	n3->parent = n1;
	n2->left = n3->right;
	if(n3->right!=NULL)
		n3->right->parent = n2;
	n3->right = n2;
	n2->parent = n3;

	balancerightStline(root,n1, n3, n2);
}



void avlBalance(AVLNode* &root,AVLNode* n1, int ltht, int rtht) {
	
	AVLNode* n2 = NULL; 
	AVLNode* n3 = NULL;
	if (ltht > rtht) {
		n2 = n1->left;
	}
	else {
		n2 = n1->right;
	}
	int ltht3 = getleftht(n2);
	int rtht3 = getrightht(n2);
	if (ltht3 > rtht3) {
		n3 = n2->left;
	}
	else {
		n3 = n2->right;
	}

	if (n3 == n2->left && n2 == n1->left) {
		balanceleftStline(root,n1, n2, n3);
	}
	if (n3 == n2->right && n2 == n1->right) {
		balancerightStline(root,n1, n2, n3);
	}
	if (n3 == n2->left && n2 == n1->right) {
		balancezigzagright(root,n1, n2, n3);
	}
	if (n3 == n2->right && n2 == n1->left) {
		balancezigzagleft(root,n1, n2, n3);
	}
	n1->ht = height(n1);
	n2->ht = height(n2);
	n3->ht = height(n3);

}


void insertAVL(AVLNode* &root, AVLNode* n) {
	n = insertBST(root, n);
	bool flag = false;
	AVLNode* par = n->parent;

	int leftht, rightht;

	while (flag == false && par!=NULL) {

		if (par->left == NULL)
			leftht = 0;
		else
			leftht = par->left->ht + 1;
		if (par->right == NULL)
			rightht = 0;
		else
			rightht = par->right->ht + 1;

		par->ht = max(leftht, rightht);

		if (abs(leftht - rightht) == 2) {
			avlBalance(root,par, leftht, rightht);
			flag = true;
		}		
		par = par->parent;
		
	}

}




//Bubble Sort
void bubblesort(int* a, int len) {
	int i, tmp;
	bool swapped = true;

	while (swapped == true) {
		swapped = false;

		for (i = 0; i < len - 1; i++) {//starting int j=0 and doing len - j - 1, j++
			if (a[i] < a[i + 1]) {//>for descending
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				swapped = true;
			}
		}
	}
}

struct link {

	int data;
	link* next;

};


class linklist
{
public:
	link* first;
};

void bubblesortli(linklist *li) {
	link* current;
	link* current2;
	int tmp;
	
	bool swap = true;
	while (swap == true) {
		swap = false;
		current =li->first;
		current2 = current->next;
		while (current2 != NULL) {
			if (current->data < current2->data) {//> for descending
				tmp = current->data;
				current->data = current2->data;
				current2->data = tmp;
				swap = true;
			}
			//cout << "st3" << current2->data << endl;
			//cout << "min" << min->data << endl;
		current = current2;
		current2 = current2->next;
		}
		//current = current->next;
	}
}

void merge(vector<int>& A, int left, int mid, int right)
{
	vector<int> tmp(right - left + 1, 0);
	int i, j, k;
	i = left;  j = mid + 1;
	for (k = 0; k < right - left + 1; k++)
	{
		if (i == mid + 1) 
		{
			tmp[k] = A[j];
			j++; 
			continue; 
		}
		if (j == right + 1) 
		{
			tmp[k] = A[i];
			i++; 
			continue;
		}
		if (A[i] < A[j])//> for descending
		{ 
			tmp[k] = A[i];
			i++;
		}
		else 
		{ 
			tmp[k] = A[j];
			j++;
		}
	}
	// copy tmp back to A[] at left to right index 
	//copy(begin(tmp), end(tmp), begin(A)+left);
	copy(tmp.begin(), tmp.end(), A.begin()+left);
	printArray(A, A.size());
	}




void mergesort(vector<int>&A, int l, int r)
{
	if (r <= l)
		return;
	int mid = (l + r) / 2;
	mergesort(A, l, mid);	
	mergesort(A, mid + 1, r);	
	merge(A, l, mid, r);	
}



