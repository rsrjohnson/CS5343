#pragma once


//write Floyd-Warshal to find transitive closure

class MGraph
{
public:
	int nd;
	vector<vector<int>> adjM;

	MGraph(int n)
	{
		nd = n;
		adjM.assign(n, vector<int>(n, 0));
	}

	void addEdge(int u, int v, bool undirected)
	{
		adjM[u - 1][v - 1] = 1;
		if (undirected)
			adjM[v - 1][u - 1] = 1;
	}


	void printAdjMatrix()
	{
		for (int i = 0; i < nd; i++) {
			for (int j = 0; j < nd; j++)
				cout << adjM[i][j] << " ";
			cout << endl;
		}
	}

};


MGraph Floyd_Warshall_TrsCls(MGraph G)
{
	MGraph G_aster = G;

	for(int k=1 ;k<G.nd+1;k++ )
		for (int i = 1; i < G.nd+1; i++)
			if(i!=k)
				for (int j = 1; j < G.nd+1; j++)
					if (j != i && j != k)
					{
						if (G_aster.adjM[i - 1][k - 1] > 0 && G_aster.adjM[k - 1][j - 1] > 0 && G_aster.adjM[i - 1][j - 1] == 0)
						{
							cout << i << "-->" << k << endl;
							cout << k << "-->" << j << endl;
							cout << "draw " << i << "-->" << j << endl;
							cout << endl;
							G_aster.adjM[i - 1][j - 1] = 1;
						}
					}

	return G_aster;
}