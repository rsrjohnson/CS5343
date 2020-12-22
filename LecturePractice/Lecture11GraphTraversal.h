#pragma once
#include<vector>
#include<queue>

using namespace std;
class Graph {
public:
	int novertex;	
	vector<vector<int>>adjL;


	Graph(int n)
	{
		novertex = n;
		adjL.resize(n);
	}


	void addEdge(int u, int v)
	{
		adjL[u].push_back(v);
	}

	/*
	void printAdjMatrix()
	{
		for (int i = 0; i < novertex; i++) {
			for (int j = 0; j < novertex; j++)
				cout << M[i][j] << " ";
			cout << endl;
		}
	}
	
	
	void addEdge(int u, int v,bool undirected)
	{
		M[u - 1][v - 1] = 1;
		if(undirected)
			M[v - 1][u - 1] = 1;
	}

	void DFShelper(int start,vector<bool> &visited)
	{
		if (visited[start - 1] == false)
		{
			cout << start << " ";
			visited[start - 1] = true;

			for (int i = 1; i < novertex + 1; i++)
			{
				if (M[start - 1][i - 1] > 0 && !visited[i])
				{
					DFShelper (i, visited);

				}

			}
		}
		else
			return;

		for (int i = 0; i < novertex; i++)
		{
			if (!visited[i])
				DFShelper(i, visited);
		}

		return;

	}

	*/

	void DFShelper(int start,vector<bool> &visited)
	{
			cout << start << " ";
			visited[start] = true;

			for (int i = 0; i < adjL[start].size(); i++)
			{
				int vertex = adjL[start][i];

				if (!visited[vertex])
					DFShelper(vertex, visited);
			}
		
	}

	void DFS(int start)
	{
		vector<bool> visited(novertex, false);

		DFShelper(start, visited);

		for (int i = 0; i < novertex; i++)
		{
			if (!visited[i])
				DFShelper(i, visited);
		}
	}

	void BFShelper(int start,vector<bool> &visited)
	{
		queue <int>q;
		visited[start] = true;
		q.push(start);


		while (!q.empty())
		{
			int current = q.front();			
			cout << current << " ";
			q.pop();

			vector<int> adjacentvertex = adjL[current];

			for (int i = 0; i < adjacentvertex.size(); i++)
			{
				if (!visited[adjacentvertex[i]])
				{
					visited[adjacentvertex[i]] = true;
					q.push(adjacentvertex[i]);
				}
					
			}
		}
	
	}


	void BFS(int start)
	{
		vector<bool> visited(novertex, false);
		BFShelper(start, visited);

		for (int i = 0; i < novertex; i++)
		{
			if (!visited[i])
				BFShelper(i, visited);
		}
	}

};