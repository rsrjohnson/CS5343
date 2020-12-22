#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;




#include "Lecture1Recursion.h"
#include "Lecture2SingleLinkedList.h"
#include "Lecture3DoubleLLStacksQueues.h"
#include "Lecture5BinTrees.h"
#include "Lecture7AVL_OtherSorts.h"
#include "Lecture8Heaps.h"
#include "Lecture10QuickSort.h"
//#include "Lecture11GraphTraversal.h"
#include "Lecture12GraphConnectivityTransitiveClosure.h"
# include "Lecture13SPT_DijkstraBellmanFord.h"
#include "Lecture14MST_KruskalPrimTopologicalOrder.h"
#include "Lecture15Hashing.h"


int main()
{	
	//Lecture 1
	int a[] = { 7,12,3,9,4};	
	/*

	vector<double> C = { 1,2,3 };

	vector<double> R = prefixAverages2(C, 3);
	vector<double>P(3,0);

	RprefixAverages(C, 3, P);

	cout << ArrayMax(a,5)<<endl;
	cout << RarrayMax(a, 5)<<endl;

	cout << RLinearSum(a, 5)<<endl;
	cout << RBinarySum(a, 0, 5) << endl;
	
	cout << power(2, 5)<<endl;
	cout << powerLogn(2, 5) << endl;
	cout << power(2, 6) << endl;
	cout << powerLogn(2, 6) << endl;

	cout << Fib(5) << endl;
	cout << FibMEMO(5) << endl;

	RReverseArray(a, 0, 4);

	cout << RPalindrome("teamaet", 7)<<endl;
	cout << RGCD(20, 12) << endl;
	
	
	cout << endl;
	*/



	/*
	cout << "Lecture 3" << endl;
	//Lecture 3

	ArrayStack<int> s(5);

	s.push(1);
	s.push(3);
	s.push(9);
	s.push(6);
	s.push(5);
	
	cout << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout<<s.size()<<endl;
	cout<<s.top()<<endl;
	
	LinkedListStack<int> sll;

	sll.push(1);
	sll.push(2);
	sll.push(3);

	cout << sll.size() << endl;
	cout << sll.top() << endl;
	sll.pop();
	cout << sll.size() << endl;
	cout << sll.top() << endl;
	*/
	//myFunction(5);
	
	//
	/*
	Node* nd =new Node;
	nd->val = 6;
	nd->next = NULL;
	insertAtEnd(nd, 4);
	RinsertArEnd(nd, 2);


	MyLinkedList* li = new MyLinkedList();


	//li->addAtHead(1);
	//li->addAtTail(3);
	//li->addAtIndex(1, 2);
	//li->get(1);
	//li->deleteAtIndex(1);
	//li->get(1);
	
	*/

	
	//Lecture 5

	vector<int> v = { 2,7,5,6,1,11,9,4 };
	TreeNode* rootB = new TreeNode(2);
	rootB->left = new TreeNode(7);
	rootB->right = new TreeNode(5);
	rootB->left->right = new TreeNode(6);
	rootB->left->right->left = new TreeNode(1);
	rootB->left->right->right = new TreeNode(11);
	rootB->right->right = new TreeNode(9);
	rootB->right->right->left = new TreeNode(4);

	cout << large(rootB) << " este" << endl;
	int aaa = countLeftExternal(rootB);
	levelOrderv(rootB);
	cout << endl;
	int t = heightn(rootB, rootB->right);
	/*
	int nodes[] = { 40, 60, 20, 80, 50, 10, 30, 15, 5, 35, 25, 45, 55, 70, 90, 32, 33, 48, 46 };

	int numberofnodes = sizeof(nodes) / sizeof(nodes[0]);

	TreeNode* rootbin = new TreeNode(nodes[0]); //Defining the root of the BST

	for (int i = 1; i < numberofnodes; i++)
		insertBintree(rootbin, nodes[i]); //Inserting the rest of the nodes in the BST
		*/

	AVLNode* root = new AVLNode();
	root->val = 1;

	int arr[] = { 2,3,4,5,6,7 };

	for (int i = 0; i < 6; i++)
	{
		AVLNode* temp = new AVLNode();
		temp->val = arr[i];
		insertAVL(root, temp);
	}
		
	


	cout << "Heap Sort" << endl;
	vector<int>D = {12,25,11,18,6,9,4,3,16,12,20,30,15};
	HeapSort(D);

	for (int i = 1; i < D.size(); i++)
		cout << D[i] << " ";

	cout << endl;


	/*
	//Merge Sort
	cout << "Merge Sort" << endl;
	vector<int>VMS = { 15,9,3,20,8,5,16,7 };

	mergesort(VMS, 0, 7);

	cout << endl;


	cout << "Quick Sort" << endl;

	vector<int>A = { 9,15,6,11,21,14,1,7,19,5,3 };
	QuickSort(A, 0, 10);
	
	cout << endl;

	vector<int>B = { 2,19,6,13,21,15,27,3,18,4,7,9};

	QuickSort(B, 0, 11);

	*/
	//Graph G(10);

	//vector<vector<int>>edges{ {0,9}, {1,4},{1,5},{2,4},{3,4},{4,5},{5,6},{6,1},{6,4},{6,7},{7,2},{7,4},{8,2},{8,3},{8,7} };

	//for (int i = 0; i < edges.size(); i++)
	//{
		//G.addEdge(edges[i][0], edges[i][1]);
	//}
	//G.printAdjMatrix();

	//cout << endl;
	
	//G.DFS(6);
	//cout << endl;
	//G.BFS(6);


	vector<vector<int>>edges = { {1,0},{2,0},{2,1} };

	Graph G(3);

	for (int i = 0; i < edges.size(); i++)
	{
		G.addEdge(edges[i][0], edges[i][1]);
	}

	//G.addEdge(edges[0][0], edges[0][1]);
	//G.addEdge(edges[0][1], edges[0][0]);


	cout << endl;
	//Floyd-Warshall
	
	vector<vector<int>> cnnedges = { {1,3},{2,4},{4,2},{2,1} };
	MGraph GM(4);

	for (vector<int>p : cnnedges)
		GM.addEdge(p[0], p[1], false);

	GM.printAdjMatrix();
	cout << endl;
	cout << "Floyd-Warshall" << endl;
	MGraph GM_aster = Floyd_Warshall_TrsCls(GM);

	cout << endl;
	cout << "Topological Order" << endl;
	vector<int> topoDFS = DFSTopological(G);
	cout << endl;


	//vector<vector<int>>edgesDJ = { {0,2,9},{0,6,14},{0,7,15},{2,3,24},{3,5,2},{3,1,19},{4,3,6},{4,1,6},{5,4,11},{5,1,16},{6,3,18},{6,5,30},{6,7,5},{7,5,20},{7,1,44} };
	vector<vector<int>>edgesDJ = { {0,1,8},{0,2,2},{0,3,4}, {1,2,7},{1,4,2},{2,4,3},{2,5,9},{2,3,1},{3,5,5} };
	SPTGraph DJGraph(6);

	for (int i = 0; i<edgesDJ.size(); i++)
	{
		DJGraph.addEdge(edgesDJ[i][0], edgesDJ[i][1], edgesDJ[i][2],true);
	}

	cout << "Dijkstra" << endl;
	SPTGraph DJGraphSPT = Dijkstra(DJGraph, 0);


	cout << endl;


	//vector<vector<int>>edgesBF = { {1,3,6},{1,4,3},{2,1,3},{4,2,1},{4,3,1},{5,2,4},{5,4,2}};

	vector<vector<int>>edgesBF = { {1,2,6},{1,4,7},{2,3,5},{2,4,8},{2,5,-4},{3,2,-2},{4,3,-3},{4,5,9},{5,1,2}, {5,3,7} };
	
	cout << "Bellman Ford" << endl;
	BellmanFord(edgesBF,1, 5);
	vector<string>hash_words = hashtable_insert(words,0,31);
	return 0;
}


