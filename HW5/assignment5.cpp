//Student Name: Randy Suarez Rodes
//Course: CS 5343
//Assignment #5
//July 24, 2020
//This program was written on c++, run on Visual Studio Community 2019 on Windows 10.

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include <string>
#include <unordered_map>

using namespace std;

//Graph class for vertices of generic type
template <typename T>
class Graph {
public:
	int numVertex; //variable to hold the number of vertices
	vector<T> vertices; //vector of vertices
	unordered_map< T, vector<T> > adjList; //map to hold the adjacency list of each vertex
	unordered_map< T, int > indegree;	//map to hold the indegree of each vertex
		
	//Graph constructor
	Graph(vector<T>verticesList)
	{
		numVertex = verticesList.size();
		vertices = verticesList;

		//Initializing the indegree of each vertex as 0
		for (int i = 0; i < numVertex; i++)
			indegree[verticesList[i]] = 0;
	}

	//Method to add an edge from vertex u to vertex v
	void addEdge(T u, T v)
	{	
		adjList[u].push_back(v); //adding vertex v to adjacency list of u
		indegree[v]++;	//we increase the indegree of the destination vertex
	}
};

//Declarations
template <typename T>
void DFSTopologicalHelper(Graph<T> G, T curr_vertex, unordered_map<T, bool>& visited, unordered_map<T, bool>& safe, stack<T>& s, bool& stop);
template <typename T>
void DFSTopological(Graph<T> G);
template <typename T>
void BFStopological(Graph<T> G);

int main()
{
	//vertices of the first graph
	vector<int> vertices1 = { 1,2,3,4,5,6,7,8 }; 
	//edges of the first graph
	vector<vector<int>> edge1 = {{1,2},{1,5},{1,6},{2,3},{2,5},{2,7},{3,4},{4,5},{5,7},{5,8},{6,5},{6,8},{7,4},{7,8}}; 

	//vertices of the second graph
	vector<string> vertices2 = { "m","n","o","p","q","r","s","t","u","v","w","x","y","z" }; 
	//edges of the second graph
	vector<vector<string>> edge2 = {{"m","q"},{"m","r"},{"m","x"},{"n","o"},{"n","q"},{"n","u"},{"o","r"},{"o","s"},
									{"o","v"},{"p","o"},{"p","s"},{"p","z"},{"q","t"},{"r","u"},{"r","y"},{"s","r"},
									{"u","t"},{"v","w"},{"v","x"},{"w","z"},{"y","v"}};

	Graph<int> G1(vertices1); //initializing the first graph
	Graph<string> G2(vertices2); //initializing the second graph

	//adding edges of the first graph
	for (int i = 0; i < edge1.size(); i++)	
		G1.addEdge(edge1[i][0], edge1[i][1]);
	
	//adding edges of the second graph
	for (int i = 0; i < edge2.size(); i++)	
		G2.addEdge(edge2[i][0], edge2[i][1]);	

	cout << "DFS topological order of the sample graphs" << endl;

	cout << "First graph:" << " ";
	DFSTopological(G1);
	cout << endl;

	cout << "Second graph:" << " ";
	DFSTopological(G2);
	cout << endl;
	cout << endl;

	cout << "BFS topological order of the sample graphs" << endl;

	cout << "First graph:" << " ";
	BFStopological(G1);
	cout << endl;

	cout << "Second graph:" << " ";
	BFStopological(G2);	

	return 0;
}

//Definitions

//Performs a DFS from a specified vertex(curr_vertex), it follows the order of the adjacency list when visiting the adjacent vertices
template <typename T>
void DFSTopologicalHelper(Graph<T> G, T curr_vertex, unordered_map<T, bool>& visited, unordered_map<T, bool>& safe, stack<T>& s, bool& stop)
{
	if (stop) //this boolean will flag if there is a cycle in the graph
		return;

	visited[curr_vertex] = true; //marking current vertex as visited
	safe[curr_vertex] = false; //we mark this vertex unsafe, in order to detect a possible cycle

	for (T v : G.adjList[curr_vertex])
	{
		if (!safe[v]) //we reached an unsafe vertex, so we found a cycle		
			stop = true; //boolean set to flag the presence of a cycle		
			
		//performing DFS in a safe and unvisited adjacent vertex 
		if (!visited[v])
			DFSTopologicalHelper(G, v, visited, safe, s, stop);
	}

	s.push(curr_vertex); //adding curr_vertex to a stack to hold the correct topological order
	safe[curr_vertex] = true; //after finding the vertex's order, it is safe to visit it again
}

//Finds a DFS topological order of a Graph, it detects a cycle if present
template <typename T>
void DFSTopological(Graph<T> G)
{
	unordered_map<T, bool> visited; //map to mark the visited vertices
	unordered_map<T, bool> safe;	//map to mark safe vertices to visit
	stack<T>s;	//stack to store the topological order

	for (T v : G.vertices)
	{
		visited[v] = false; //marking all vertices as not visited
		safe[v] = true; //marking all vertices as safe
	}

	bool stop = false; //boolean to flag the presence of a cycle

	for (T v : G.vertices)
	{
		if (stop) //a cycle is present, we stop the program execution
		{
			cout << "There's a cycle, topological order cannot be found";
			return;
		}
		if (!visited[v]) //performing DFS for each unvisited vertex
			DFSTopologicalHelper(G, v, visited, safe, s, stop);
	}

	//printing the DFS topological order
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

}

//Performs a BFS topological order of a Graph, it detects a cycle if present
template <typename T>
void BFStopological(Graph<T> G)
{
	unordered_map<T, bool> visited;  //map to mark the visited vertices

	for (T v : G.vertices)
		visited[v] = false; //marking all vertices as not visited

	queue<T>q; //queue to hold the vertices for the BFS

	//adding to the queue the vertices of indegree 0 to start the topological order
	for (T v : G.vertices)
	{
		if (G.indegree[v] == 0)
		{
			q.push(v);
			visited[v] = true; //marking vertices as visited
		}
	}

	vector<T>order; //vector to store the topological order

	while (!q.empty())
	{
		T curr = q.front();
		order.push_back(curr);
		q.pop();

		for (T v : G.adjList[curr])
		{
			G.indegree.at(v)--; //decreasing the indegree of the adjacent vertex
			if (!visited[v] && G.indegree[v] == 0)
			{
				q.push(v); //adding to q unvisited vertices of indegree 0
				visited[v] = true; //marking the adjacent vertex with indegree 0 as visited
			}
		}
	}

	if (order.size() < G.numVertex) //if all vertices cannot be visited, hence their indegree will not be 0, this means we have the presence of a cycle
		cout << "There's a cycle, topological order cannot be found";
	else
		for (T v : order) //otherwise we print the BFS topological order
			cout << v << " ";
	return;
}