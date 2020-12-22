//Student Name: Randy Suarez Rodes
//Course: CS 5343
//Assignment #2
//June 21, 2020
//This program was written on c++, run on Visual Studio Community 2019 on Windows 10.


#include<iostream>

using namespace std;

//Tree Node structure
struct Node {
	int val;
	Node* parent; //We will keep track of each node's parent
	Node* left;
	Node* right;
	Node(int v) //Tree node constructor
	{
		val = v;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};

//Declarations
void inorder(Node* root);
void insert(Node* root, int v);
Node* delNodeV(Node* root, int v);
Node* getNode(Node* root, int v);
Node* getPredecessor(Node* n);
Node* getSuccesor(Node* n);

int main()
{
	//Array of values to build a BST
	int nodes[] = { 40, 60, 20, 80, 50, 10, 30, 15, 5, 35, 25, 45, 55, 70, 90, 32, 33, 48, 46 };

	int numberofnodes = sizeof(nodes) / sizeof(nodes[0]);

	Node* root = new Node(nodes[0]); //Defining the root of the BST

	for (int i = 1; i < numberofnodes; i++)
		insert(root, nodes[i]); //Inserting the rest of the nodes in the BST

	//Opearations performed in the BST
	cout << "Original inorder traversal of the BST" << endl;
	inorder(root);
	cout << endl;

	root = delNodeV(root, 40);
	cout << "Deleting " << 40 << endl;
	inorder(root);
	cout << endl;

	root = delNodeV(root, 20);
	cout << "Deleting " << 20 << endl;
	inorder(root);

	return 0;
}

//Definitions

//Inorder traversal
void inorder(Node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

//Inserting a new node with value v in the correct position of a BST
void insert(Node* root, int v) {
	if (v < root->val)
	{
		if (root->left == NULL)
		{
			root->left = new Node(v);
			root->left->parent = root;
			return;
		}
		insert(root->left, v);
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = new Node(v);
			root->right->parent = root;
			return;
		}
		insert(root->right, v);
	}
}

//Function to find a node with value v
Node* getNode(Node* root, int v)
{
	if (root == NULL || root->val == v) //If we reach a null node, the value is not in the tree, a null node is returned, otherwise we find the node with value v and return it
		return root;

	else if (v < root->val)
		return getNode(root->left, v); //Searching for the node to be deleted in the left subtree
	
	else
		return getNode(root->right, v); //Searching for the node to be deleted in the right subtree
}

//Function to find the predecessor of a node n in the BST
Node* getPredecessor(Node* n)
{
	Node* predecessor = n->left; //The predecessor has to be in the left subtree by definition
	while (predecessor->right != NULL) //The predecessor will be the rightmost node in the left subtree
		predecessor = predecessor->right;
	return predecessor;
}

//Function to find the sucessor of a node n in the BST
Node* getSuccesor(Node* n)
{
	Node* succesor = n->right; //The succesor has to be in the right subtree by definition
	while (succesor->left != NULL)//The succesor will be the leftmost node in the right subtree
		succesor = succesor->left;
	return succesor;
}

//Function to delete a node with value v in a BST
Node* delNodeV(Node* root, int v)
{
	Node* n = getNode(root, v);//Find the node to be deleted

	if (n != NULL) //If n is null, this means the value v is not in the tree there's nothing to be done	
	{
		if (n->left == NULL && n->right == NULL) //Checking if the node is leaf
		{
			if (n->parent != NULL)//Checking if we have a single node
			{
				//Since the node is a leaf we just have to unlink it from its parent
				if (n->parent->left == n) //Checking if the node is right or left child
					n->parent->left = NULL;
				else
					n->parent->right = NULL;
			}
			else //If the parent is NULL and n is a leaf, this means the tree only has one node, we end up with an empty tree
				root = NULL;
		}

		//The node is not a leaf, therefore it is garanteed that the predecessor or sucessor exists		
		else if (n->left != NULL) //Working with the Predecessor
		{
			Node* predecessor = getPredecessor(n); //Finding the predecessor

			if (predecessor->parent == n) //Checking if the predecessor is the node's left child
				n->left = predecessor->left;
			else //Otherwise the predecessor has to be a right child since it is the rightmost node in the left subtree of the node
				predecessor->parent->right = predecessor->left;
			
			n->val = predecessor->val; //Changing the node's value for the predecessor's value
			
			if (predecessor->left != NULL) //If the predecessor is not a leaf, we have to update its left child's parent
				predecessor->left->parent = predecessor->parent;
		}
		else //Working with the Successor
		{
			Node* succesor = getSuccesor(n); //Finding the sucessor

			if (succesor->parent == n) //Checking if the succesor is the node's right child
				n->right = succesor->right;
			else //Otherwise the succesor has to be a left child since it is the leftmost node in the right subtree of the node
				succesor->parent->left = succesor->right;

			n->val = succesor->val; //Changing the node's value for the succesor's value

			if (succesor->right != NULL) //If the succesor is not a leaf, we have to update its right child's parent
				succesor->right->parent = succesor->parent;
		}
	}
	return root;
}