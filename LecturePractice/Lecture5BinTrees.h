#pragma once

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

void inorder(TreeNode* root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

void preorder(TreeNode* root)
{
	if (root == NULL)
		return;
	cout << root->val << " ";

	preorder(root->left);
	preorder(root->right);
}

void postorder(TreeNode* root)
{
	if (root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";

}

void levelOrder(TreeNode* root) {

	queue <TreeNode *> q;
	q.push(root);

	TreeNode* temp = NULL;
	while (!q.empty())
	{
		temp = q.front();
		cout << temp->val << " ";
		q.pop();
		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
	}
}

//BFS
void levelOrderv(TreeNode* root) {
	queue<TreeNode*>q;
	TreeNode* c = NULL;

	q.push(root);
	while (!q.empty())
	{
		
		c = q.front();
		cout<<c->val<<" ";
		q.pop();

		if (c->left != NULL)
			q.push(c->left);
		if (c->right != NULL)
			q.push(c->right);
	}

	return;

}



int countNodes(TreeNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + countNodes(root->left) + countNodes(root->right);

}

int countvalv(TreeNode* root, int v)
{
	if (root == NULL)
		return 0;

	if (root->val == v)
		return 1 + countvalv(root->left, v) + countvalv(root->right, v);

	return countvalv(root->left, v) + countvalv(root->right, v);
}

int leaves(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return leaves(root->left) + leaves(root->right);
}

//Tree not empty
int large(TreeNode* root)
{
	if (root->left == NULL && root->right == NULL)
		return root->val;

	if (root->left == NULL)
		return max(root->val, large(root->right));

	if (root->right == NULL)
		return max(root->val, large(root->left));	

	return max(root->val, max(large(root->left), large(root->right)));
	
}


TreeNode* sibling(TreeNode* tmp, TreeNode* n)
{
	if (tmp == NULL || tmp==n)
		return NULL;

	if (tmp->left != NULL)
	{
		if (tmp->left == n)
			return tmp->right;
	}

	if (tmp->right != NULL)
	{
		if (tmp->right == n)
			return tmp->left;
	}

	
	TreeNode* lt = sibling(tmp->left, n);

	if (lt == NULL)
	{		
		return sibling(tmp->right, n);
	}

	return lt;
		
}

TreeNode* parent(TreeNode* tmp, TreeNode* n)
{
	if (tmp == NULL || tmp == n)
		return NULL;
	
	if (tmp->left == n || tmp->right == n)
		return tmp;	

	TreeNode* p = parent(tmp->left, n);

	if (p == NULL)
		return parent(tmp->right, n);

	return p;
}


int height(TreeNode* root)
{
	if (root == NULL)
		return -1;

	return 1 + max(height(root->left), height(root->right));
}

int heightn(TreeNode* root, TreeNode* n)//not depending of an extra function
{
	if (root == NULL)
		return -1;

	if (root == n)
		return 1 + max(height(n->left), height(n->right));

	return max(heightn(root->left, n), heightn(root->right, n));

}

//Traverse until n
TreeNode* findNode(TreeNode* tmp, TreeNode* n)
{
	if (tmp == NULL)
		return NULL;

	if (tmp == n)
		return tmp;

	TreeNode* lt = findNode(tmp->left, n);

	if(lt==NULL)
		return findNode(tmp->right, n);

	return lt;
}


void mirror(TreeNode* root)
{
	if (root == NULL)
		return;

	TreeNode* temp= root->left;
	root->left = root->right;
	root->right = temp;

	mirror(root->left);
	mirror(root->right);
}


void insertBintree(TreeNode* root, int v) {
	if (v < root->val)
	{
		if (root->left == NULL)
		{
			root->left = new TreeNode(v);
			
			return;
		}
		insertBintree(root->left, v);
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = new TreeNode(v);			
			return;
		}
		insertBintree(root->right, v);
	}
}

int countLeftExternal(TreeNode* root)
{
	if (root == 0)
		return 0;
	if (root->left != NULL)
	{
		if (root->left->left == NULL && root->left->right == NULL)
			return 1;
	}

	return countLeftExternal(root->left) + countLeftExternal(root->right);
}