//Student Name: Randy Suarez Rodes
//Course: CS 5343
//Assignment #1
//June 10, 2020

#include<iostream>

using namespace std;

// Single Node
struct Node {
	int val;
	Node* next;
};

// Single Linked List Structure
struct LinkedList {
	Node* head;
};

//Functions Declarations
void addNode(Node* refnode, int v); //Function that creates a new node with val v and links it to the given reference node
void traverse(LinkedList* l); //Function that traverse the linked list
void selectSort(LinkedList* l); //Function that sort the linked list using selection sort

int main()
{
	cout << "Randy Suarez Rodes" << endl;
	cout << "Assignment #1" << endl;
	cout << "06/10/2019" << endl;
	cout << "==============" << endl;
	cout << endl;



	int numbers[] = { 6,34,5,23,45,1,5,10,8,17,9,6,13,27,12,100,35 }; //Array of the values to be stored in the linked list

	Node* head = new Node();
	Node* current = head;
	head->val = numbers[0];
	
	int nlength = sizeof(numbers) / sizeof(numbers[0]);

	for (int i = 1; i <nlength; i++){ //Adding nodes to the linked list
		addNode(current, numbers[i]);
		current = current->next;
	}

	LinkedList* l = new LinkedList();
	l->head = head;

	cout << "Original Linked List" << endl;
	traverse(l); //Traversing the unsorted linked list
	cout << endl;

	selectSort(l); //Sorting the linked list using selection sort
	
	cout << "Sorted Linked List" << endl;
	traverse(l); //Traversing the sorted linked list

	return 0;
}

//Functions Definitions
void addNode(Node* refnode, int v){
	Node* nnode = new Node();
	nnode->val = v;
	refnode->next = nnode;
}

void traverse(LinkedList* l){
	Node* current = l->head;

	while (current != NULL){
		cout << current->val << " ";
		current = current->next;
	}
}

void selectSort(LinkedList* l) {
	Node* current = NULL; //Node to hold the current position
	Node* current_prev = NULL; //Node to hold the previous position
	Node* current2 = NULL; //Node to traverse searching for the minimums
	Node* min = NULL; //Node to hold the current minimum
	Node* min_prev = NULL; //Node to hold the previous node of the current minimun
	Node* tmp = NULL; //Temporal Node for swapping references

	current = l->head; //Getting the head of the list to start traversing
	
	while (current != NULL) {
		min = current; //Setting the minimum in the current node
		current2 = current; //Initializing the variable for the second traverse

		while (current2->next != NULL) { //We use the next pointer since we need to keep the reference of the node previous to a found minimum
			if (current2->next->val < min->val) { 
				min = current2->next; //Updating the minimum and its previous node
				min_prev = current2;
			}
			current2 = current2->next;
		}

		//Now we need to swap min and current
		tmp = min->next; //Storing the reference of the Node next to min to swap later

		if (current->next != min){ //Checking if min and current are next to each other, this case is handled different otherwise results in a pointer pointing to itself
			min->next = current->next; //Pointing the next pointer of min to the next pointer of current

			if (min != l->head) //Checking the case when min is the list head, since in this case min_prev is NULL
				min_prev->next = current;
		}
		else
			min->next = current; //Pointing min to current, because they are next to each other

		current->next = tmp; //Pointing the current node to the original next pointer of min saved in temp

		//Handling Special case when current is the list head, since in this case current_prev is NULL
		if (current == l->head)
			l->head = min; //If current is the head we have to update the linked list head
		else
			current_prev->next = min; //Pointing the previous node of current to min

		current_prev = min; //Saving min as the previous node for the next traverse step
		min_prev = min; //This will be the default previous to the minimum if the minimun does not change its position in the next traversed step 
		current = min->next; //Assigning the next node to continue traversing
	}
}