#pragma once
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int v)
	{
		val = v;
		left = NULL;
		right = NULL;
	}
};

void BFStrav(TreeNode* root)
{
	queue<TreeNode*> q;
	q.push(root);
	//vector <int>visited;
	TreeNode* temp = NULL;
	while (!q.empty())
	{
		temp = q.front();
		//visited_push.back(temp->val);
		cout << temp->val << " ";
		q.pop();
			if (temp->left != NULL)
				q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
	}
}


void rinsert(TreeNode* &root, int v)
{
	if (root == NULL)
	{
		root = new TreeNode(v);
		return;
	}		

	else if (v < root->val)
	{
		if (root->left == NULL)
		{
			root->left = new TreeNode(v);
			return;
		}
		rinsert(root->left, v);
	}
	else
	{
		if (root->right==NULL)
		{
			root->right= new TreeNode(v);
			return;
		}
		rinsert(root->right, v);
	}
}