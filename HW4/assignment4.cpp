//Student Name: Randy Suarez Rodes
//Course: CS 5343
//Assignment #4
//July 17, 2020
//This program was written on c++, run on Visual Studio Community 2019 on Windows 10.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//Undirected Graph Class
class Graph {

public:
	int numVertex;	//Variable to store the number of vertices in the graph
	vector<vector<int>>adjMatrix; //Variable to store the adjacency matrix of the graph

	Graph(int n) //Graph constructor
	{
		numVertex = n;
		adjMatrix.resize(n,vector<int>(n,0));
	}

	void addEdge(int u, int v) //Add an edge between the specified vertices
	{
		
		//Since the graph is undirected we add in both rows
		adjMatrix[u][v] = 1;
		adjMatrix[v][u] = 1;
	}
	
	//Performs a DFS starting from a specified vertex(start), it follows lexicographic order when visiting the adjacent vertices
	void DFSHelper(int start, vector<bool>& visited)
	{
		cout << start << " ";
		visited[start] = true; //Marking the vertex as visited
		vector<int>cur_row = adjMatrix[start];
			
		for (int i = 0; i < numVertex; i++)
		{
			//Visiting adjacent vertices that have not been visited
			if (cur_row[i]>0 && !visited[i])
				DFSHelper(i, visited);
		}

		return;
	}

	//Performs a DFS from the start vertex and then from every other vertex not reachable from it, following lexicographic order
	void DFS(int start)
	{
		vector<bool> visited(numVertex, false); //Vector to keep track of the visited vertices to avoid cicles
		DFSHelper(start, visited);
		cout << "|" << " "; //We print "|" to separate DFS(s) of not connected subgraphs

		//Starting a new DFS search from every vertex that has not been visited
		for (int i = 0; i < numVertex; i++)
		{
			if (!visited[i])
			{
				DFSHelper(i, visited);
				cout << "|" << " "; //We print "|" to separate DFS(s) of not connected subgraphs
			}
		}
		return;
	}

	//Performs a BFS starting from a specified vertex(start), it follows lexicographic order when visiting the adjacent vertices
	void BFSHelper(int start, vector<bool>& visited)
	{
		queue<int> q; //Queue to store the vertex in the order to be visited
		visited[start] = true; //Marking the vertex as visited
		q.push(start);

		while (!q.empty())
		{
			int current = q.front();
			cout << current << " ";
			q.pop();

			vector<int> cur_row = adjMatrix[current];
			
			for (int i = 0; i < numVertex ; i++)
			{
				//Enqueue every vertex adjacent that has not been visited
				if (cur_row[i] > 0 && !visited[i])
				{
					visited[i] = true;
					q.push(i);
				}
			}
		}
		return;
	}

	//Performs a BFS from the start vertex and then from every other vertex not reachable from it, following lexicographic order
	void BFS(int start)
	{
		vector<bool> visited(numVertex, false); //Vector to keep track of the visited vertices to avoid cicles
		BFSHelper(start, visited);
		cout << "|" << " "; //We print "|" to separate BFS(s) of not connected subgraphs

		//Starting a new BFS search from every vertex that has not been visited
		for (int i = 0; i < numVertex; i++)
		{
			if (!visited[i])
			{
				BFSHelper(i, visited);
				cout << "|" << " "; //We print "|" to separate BFS(s) of not connected subgraphs
			}
		}
		return;
	}
};

int main()
{
	int NumOfVertex = 19; //Modify the number of vertices to generate other examples

	Graph G(NumOfVertex); //Creating a graph with the desired number of vertices

	//Vector of edges, modify to generate other examples, use vertices' numbers from 0 to NumOfVertex - 1
	vector <vector<int>> edges = { {0,1}, {0,3}, {0,4}, {1,2}, {1,5}, {3,6}, {5,8}, {6,7}, {6,9}, {7,8}, {7,9}, {7,10}, {8,10}, {9,10}, {11,12}, {11,14}, {12,13}, {12,14}, {13,15}, {13,16}, {13,18}, {14,15}, {14,17}, {15,17}, {16,18} };

	for (int i = 0; i < edges.size(); i++)
		G.addEdge(edges[i][0], edges[i][1]); //Adding each edge	
	
	int startvertex = 0; //Starting vertex to start the traversals, edit to generate other examples

	cout << "DFS traversal starting from " << startvertex << endl;
	G.DFS(startvertex); //DFS from the start node and prints the result
	cout << endl;

	cout << "BFS traversal starting from " << startvertex << endl;
	G.BFS(startvertex); //BFS from the start node and prints the result		
	
	return 0;
}