#pragma once
#include <vector>
#include <queue>



class Min_Heap
{
public:

	vector<pair<int,int>> arrayheap;

	Min_Heap()
	{
		arrayheap.push_back({-1,0});		
	}


	void percolateDown(int ind_par)
	{
		int lc = 2 * ind_par;
		int rc = 2 * ind_par + 1;
		int greatest_index = ind_par; //for maxHeap, largest_index for minHeap
		if (lc <= arrayheap[0].second)
		{
			if (arrayheap[ind_par].second > arrayheap[lc].second)//< for maxHeap
				greatest_index = lc;
			if (rc <= arrayheap[0].second)
			{
				if (arrayheap[greatest_index].second > arrayheap[rc].second)
					greatest_index = rc;

			}
			if (greatest_index != ind_par)
				swap(arrayheap[ind_par], arrayheap[greatest_index]);
			else
				return;

			percolateDown(greatest_index);
		}

		return;
	}


	void FloydHeapify()
	{
		int last_par = arrayheap[0].second / 2;

		while (last_par > 0)
		{
			percolateDown(last_par);

			last_par--;
		}
	}

	void insert(int label,int value)
	{
		arrayheap.push_back({ label ,value });
		arrayheap[0].second++;

		this->FloydHeapify();
	}


	void dequeueHeap()
	{
		int indx = arrayheap[0].second;
		arrayheap[1] = arrayheap[indx];
		arrayheap[0].second--;

		percolateDown(1);
	}

	bool isempty()
	{
		return arrayheap[0].second == 0;
	}

	pair<int,int> top()
	{
		return arrayheap[1];
	}

	void printheap()
	{
		for (int i = 1; i < arrayheap[0].second;i++)
		{
			cout << arrayheap[i].first << " ";
		}
		cout << endl;
		for (int i = 1; i < arrayheap[0].second;i++)
		{
			cout << arrayheap[i].second<<" ";
		}
		cout << endl;
	}


	void correctKey(int label, int value)
	{
		for (int i= 1; i < arrayheap[0].second+1; i++)
		{
			if (arrayheap[i].first == label)
			{
				arrayheap[i].second = value;
				this->FloydHeapify();
				return;
			}
		}
	}

};

struct GraphNode
{
	int dist=INT32_MAX;
	int label;
	GraphNode *parent=NULL;
};

class SPTGraph
{
public:
	int NumVertex;
	vector<GraphNode*> vertices;
	vector<vector<int>>adjList;
	vector<vector<int>>weights;

	SPTGraph(int n)
	{
		NumVertex = n;
		vertices.resize(n);
		adjList.resize(n);
		weights.assign(n,vector<int>(n,0));
	}


	void addEdge(int u, int v, int w,bool undirected)
	{
		adjList[u].push_back(v);		
		//vertices[v]->parent = vertices[u];
		//edges[v].push_back(u);
		weights[u][v]=w;
		//weights[w].push_back(u);

		if (undirected)
		{
			adjList[v].push_back(u);
			//vertices[u]->parent = vertices[v];
			weights[v][u] = w;
		}
	}	

	void print()
	{
		for (int i = 0; i < NumVertex; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < NumVertex; i++)
		{
			if (vertices[i]->dist == INT32_MAX)
				cout << "inf" << " ";
			else
				cout << vertices[i]->dist << " ";			
		}
		cout << endl;
	}

};


SPTGraph Dijkstra(SPTGraph J,int s)
{
	SPTGraph G=J;

	//priority_queue <int, vector<int>, greater<int> > pq;

	Min_Heap pq;
	

	for (int i = 0; i < G.NumVertex; i++)
	{
		if (i == s)
		{
			pq.insert(i, 0);
			G.vertices[s] = new GraphNode;
			G.vertices[s]->label = i;
			G.vertices[s]->dist = 0;
		}
		else {
			pq.insert(i, INT32_MAX);
			G.vertices[i] = new GraphNode;
			G.vertices[i]->label = i;
			G.vertices[i]->dist = INT32_MAX;
		}
	}

	vector<bool> visited(G.NumVertex, false);
	//pq.printheap();
	G.print();
	while(!pq.isempty())
	{		
		pair<int,int> l = pq.top();
		pq.dequeueHeap();
		
		int u = l.first;
		visited[u] = true;
		for (int v : G.adjList[u])
		{
			if (!visited[v])
			{
				int r = INT32_MAX;
				GraphNode* z = G.vertices[v];
				if(G.vertices[u]->dist< INT32_MAX)
					r = G.vertices[u]->dist + G.weights[u][v];

				if (r < z->dist)
				{
					z->dist = r;
					z->parent = G.vertices[u];
					G.vertices[v] = z;
					pq.correctKey(v,r);
				}

			}
		}
		G.print();
		//pq.printheap();
	}

	return G;
}







void BellmanFordHelper(vector<vector<int>> edges,bool &swaps,vector<int>&d,vector<int>&parents)
{
	for (int i = 0; i < edges.size(); i++)
		{
			int source = edges[i][0];
			int destination = edges[i][1];
			int weight = edges[i][2];
			int current = 0;
			if (d[source-1] != INT32_MAX)
			{
				current += d[source-1] + weight;
				if (current< d[destination - 1])
				{
					d[destination-1] = current;
					swaps = true;
					parents[destination-1] = source;
				}
			}

		}
}

void printBF(vector<int>d, vector<int>parents,int n)
{
	for (int i = 0; i < n; i++)
	{
		if(d[i]==INT32_MAX)
			cout << "inf" << " ";
		else
			cout << d[i] << " ";
	
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << parents[i] << " ";
	}

	cout << endl;

}

void BellmanFord(vector<vector<int>>edges, int start,int n)
{
	vector<int>d(n, INT32_MAX);
	d[start-1] = 0;
	int m = n;
	vector<int>parents(n, -1);
	bool swaps = true;
	while(n>1 && swaps)
	{
		swaps = false;
		BellmanFordHelper(edges, swaps, d, parents);

		printBF(d, parents, m);
		cout << endl;
		n--;
		
	}

	
	BellmanFordHelper(edges, swaps, d, parents);
	if (swaps == true)
		cout << "CYCLE" << endl;

}
