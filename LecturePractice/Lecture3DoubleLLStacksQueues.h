#pragma once

struct Dnode
{
	int val;
	Dnode* prev;
	Dnode* next;
};


void Rrevtrav(Dnode* tail)
{
	if (tail == NULL)
		return;
	cout << tail->val<<endl;
	return Rrevtrav(tail->prev);
}


void insertB(Dnode*head,Dnode* tail, Dnode* refnode, Dnode* nnode)
{
	if (refnode->prev==NULL)
	{
		nnode->next = refnode;
		refnode->prev = nnode;
		nnode->prev = NULL;
		head = nnode;		
	}
		
	nnode->next = refnode;
	nnode->prev = refnode->prev;
	refnode->prev->next = nnode;
	refnode->prev = nnode;
}

void insertA(Dnode* head, Dnode* tail, Dnode* refnode, Dnode* nnode)
{
	if (refnode->next == NULL)
	{
		refnode->next = nnode;
		nnode->prev = refnode;
		nnode->next = NULL;
		tail = nnode;
	}
	else {
		nnode->prev = refnode;
		nnode->next = refnode->next;
		refnode->next->prev = nnode;
		refnode->next = nnode;
	}
}


void delNode(Dnode*head,Dnode*tail,Dnode* refnode)
{
	if (refnode->prev == NULL && refnode->next == NULL)
	{
		head = NULL;
		tail = NULL;
	}


	else if (refnode->prev==NULL)
	{
		head = head->next;
		head->prev = NULL;
	}

	else if (refnode->next==NULL)
	{
		tail = tail->prev;
		tail->next = NULL;
	}

	else {

		refnode->prev->next = refnode->next;
		refnode->next->prev = refnode->prev;
	
	}


}


Dnode* midDoubleLinkedList(Dnode* head, Dnode* tail)
{
	if (head == tail)
		return head;
	return midDoubleLinkedList(head->next, tail->prev);
}


Node* RmidSingleLinkedList(Node* temp1,Node*temp2)
{
	if (temp2 == NULL)
	{
		return temp1;
	}

	return RmidSingleLinkedList(temp1->next, temp2->next->next);
}

bool RdetectCycle(Node* tmp1, Node* tmp2)
{
	if (tmp2 == NULL)
		return false;
	if (tmp1 == tmp2)
		return true;

	return RdetectCycle(tmp1->next, tmp2->next->next);
}

template <typename E>
class ArrayStack {
private:
	E* S; // array holding the stack
	int cap; // capacity
	int t; // index of top element
public:
	// constructor given capacity	
	ArrayStack(int c) {
		S=new E[c];
		cap=c;
		t=-1;
	}

	bool empty()
	{
		return  t < 0;
	}

	void pop() {
		if (empty())
			throw "Pop from empty stack";
		t--;
	}
	void push(const E& e) {
		if (size() == cap)
			throw "Push to full stack";
		S[++t] = e;
	}

	E top()
	{
		return S[t];
	}

	int size()
	{
		return t + 1;
	}

};


template <typename T>
struct GenSingleLinkedList
{
	// Any data type can be stored in this node 
	T data;
	GenSingleLinkedList* next;
};

template <typename T>
class LinkedListStack
{
private:
	int t;
	GenSingleLinkedList<T>* head;
	
public:
	LinkedListStack()
	{
		head = new GenSingleLinkedList<T>;
		t = 0;
	}

	bool empty()
	{
		return head == NULL;
	}

	void pop() {
		if (empty())
			throw "Pop from empty stack";
		head = head->next;
		t--;
	}
	void push(const T& e) {
		GenSingleLinkedList<T>* temp=new GenSingleLinkedList<T>;
		temp->data = e;
		temp->next = head;
		head = temp;
		t++;
	}

	T top()
	{
		return head->data;
	}

	int size()
	{
		return t;
	}
};



/*
template <typename E>
class Queue {
public:
	int size() const;
	bool empty() const;
	const E& front() const
		throw(QueueEmpty);
	void enqueue(const E& e);
	void dequeue()
		throw(QueueEmpty);
};


struct GenSingleLinkedList
{
	// Any data type can be stored in this node 
	void* data;

	GenSingleLinkedList* next;
};
*/