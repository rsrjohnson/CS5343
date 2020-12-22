#pragma once
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//struct GraphNode
//{
	//int indegree=0;
	//int outdegree=0;
//};

class Graph {
public:
	int numVertex;
	vector<vector<int>> adjList;

	Graph(int n)
	{
		numVertex = n;
		adjList.resize(n);
	}


	void addEdge(int u, int v)
	{
		adjList[u].push_back(v);

	}
};

void DFSTopologicalHelper(Graph G, int start, vector<int>& visited, vector<int>& order,bool &stop)
{
	
	visited[start] = 1;
	vector<int> adj = G.adjList[start];
	for (int i = 0; i < adj.size(); i++)
	{
		if (visited[adj[i]] == 0)
			DFSTopologicalHelper(G, adj[i], visited, order,stop);
		else
			if (visited[adj[i]] == 1)
				return;
	}

	order.insert(order.begin(), start);
	visited[start] = 2;
	return;
}
vector<int> DFSTopological(Graph G)
{
	vector<int> visited(G.numVertex, 0);

	vector<int>order;

	bool stop = false;
	for (int i = 0; i < G.numVertex; i++)
	{
		if (visited[i] == 0)
			DFSTopologicalHelper(G, i, visited, order,stop);
	}
	if (order.size() < G.numVertex)
	{
		vector<int>a;
		return a;
	}
	return order;
}


/*
for (int i = 0; i < numVertex; i++)
{
	if (vertex[i].indegree == 0)
	{
		start = i;
		break;
	}
}
*/
/*
void DFSTopological(Graph G)
{
	int start = -1;
	if (start != -1)
	{
		vector<bool> visited(G.numVertex, false);
		vector<int>order(G.numVertex, 0);
		int label = G.numVertex - 1;
		DFSTopologicalHelper(start, visited, order);

		for (int i = 0; i < G.numVertex; i++)
		{
			if (!visited[i])
			{
				DFSTopologicalHelper(i, visited);

			}
		}
	}
	else
		cout << "There is not a vertex with only outgoing edges, so we cannot start the Topological order process" << endl;
	return;
}*/