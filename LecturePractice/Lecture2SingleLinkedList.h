#pragma once

struct Node
{
	int val;

	Node* next;
};

void Traverse(Node* temp)
{
	while (temp != NULL)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}
}

void rTraverse(Node* temp)
{
	if (temp == NULL)
		return;

	cout << temp->val << endl;
	rTraverse(temp->next);
}

void insertAfter(Node* head, Node* refnode,int v)
{
	Node* cur = head;

	while (cur != refnode)
	{
		cur = cur->next;
	}

	Node* insertNode=new Node;

	insertNode->val = v;
	insertNode->next = cur->next;//or insertNode->next=refnode;
	cur->next = insertNode;
}

void insertBefore(Node* head, Node* refnode, int v)
{
	Node* node2insert= new Node;
	
	node2insert->val = v;
	
	if (head == refnode)
		node2insert->next = head;
	else {
		Node* cur = head;
		while (cur->next != refnode)
		{
			cur = cur->next;
		}
		head->next = node2insert;
	}

}

void insertAtEnd(Node *head,int v)
{
	
	Node* nd = new Node;
	Node* cur = head;

	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	nd->val = v;
	nd->next = NULL;
	cur->next = nd;
	
}

void RinsertArEnd(Node* head, int v)
{
	if (head->next == NULL)
	{
		Node* nd = new Node;
		nd->val = v;
		nd->next = NULL;
		head->next = nd;
		return;
	}
	RinsertArEnd(head->next, v);
}


int countNumberNodes(Node* head)
{
	if (head == NULL)
		return 0;
	return 1 + countNumberNodes(head->next);
}

int numberOfNodesValV(Node* head, int v)
{
	if (head == NULL)
		return 0;
	if (head->val == v)
		return 1 + numberOfNodesValV(head->next, v);
	else
		return numberOfNodesValV(head->next, v);
}

int SumNodes(Node* head)
{
	if (head == NULL)
		return 0;
	return head->val + SumNodes(head->next);
}


//Not empty linked list
int largestNode(Node* head)
{
	if (head->next == NULL)
		return head->val;

	int temp = largestNode(head->next);

	if (head->val < temp)
		return temp;
	return head->val;
}



void deleteNode(Node* head, Node* refnode)
{
	if (head == NULL)
		return;
	if (head == refnode)
		head = head->next;
	else
	{
		Node* cur = head;

		while (cur->next == refnode)
		{
			cur = cur->next;
		}

		cur = cur->next->next; //or cur=refnode->next
	}

}


void RdeleteNode(Node* head, Node*refnode)
{
	if (head == refnode) {
		head = head->next;
	}
	else
	{
		if (head->next == refnode)
		{
			head->next = refnode->next;
		}

		RdeleteNode(head->next, refnode);
	}
}


void reversePrint(Node* head) {

	if (head == NULL)
		return;
	reversePrint(head->next);
	cout << head->val << endl;


}





class MyLinkedList {
public:
	
	Node* head;
	int count;
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = NULL;
		count = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		
		if (count-1< index)
			return -1;

		int i = 0;
		Node* temp = head;		

		while (i < index)
		{
			temp = temp->next;
			i++;
		}	

		return temp->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {

		if (head == NULL)
		{
			head = new Node();
			head->val = val;
			head->next = NULL;

		}
		else {
			Node* temp = new  Node();
			temp->val = val;

			temp->next = head;
			head = temp;
		}
		count++;

	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		Node* temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		Node* nnode = new  Node();
		nnode->val = val;
		nnode->next = NULL;
		temp->next = nnode;
		count++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		
		if (index == 0)
		{
			addAtHead(val);
			
		}
		if(index==count)
		{
			addAtTail(val);

		}
		else if (index < count)
		{
			Node* temp = head;
			int i = 0;
			while (i < index - 1)
			{
				temp = temp->next;
				i++;
			}
			Node* nnode = new  Node();

			nnode->val = val;
			nnode->next = temp->next;
			temp->next = nnode;
			count++;
		}

	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		
		if (count > index)
		{
			if (index == 0)
			{
				head = head->next;
			}
			else {
				Node* temp = head;
				int i = 0;
				while (i < index - 1)
				{
					temp = temp->next;
					i++;
				}
				temp->next = temp->next->next;
			}

			count--;
		}
		
	}
};