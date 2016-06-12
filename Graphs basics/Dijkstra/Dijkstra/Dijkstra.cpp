// Dijkstra.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include "stdafx.h"
using namespace std;
int adj[9][9]={{0, 4, 0, 0, 0, 0, 0, 8, 0},
                 {4, 0, 8, 0, 0, 0, 0, 11, 0},
                 {0, 8, 0, 7, 0, 4, 0, 0, 2},
                 {0, 0, 7, 0, 9, 14, 0, 0, 0},
                 {0, 0, 0, 9, 0, 10, 0, 0, 0},
                 {0, 0, 4, 0, 10, 0, 2, 0, 0},
                 {0, 0, 0, 14, 0, 2, 0, 1, 6},
                 {8, 11, 0, 0, 0, 0, 1, 0, 7},
                 {0, 0, 2, 0, 0, 0, 6, 7, 0}
};
int N,src,dest;
int visited[9],path[9],dist[9];

int GetMin()
{
	int ret = INT_MAX,ret_node=-1;
	for(int i=0;i<N;i++)
	{
		if(dist[i] < ret && (visited[i] == 0)){
			ret = dist[i];
			ret_node = i;
		}
	}

	return ret_node;
}

void Print()
{
	for(int i=0;i<N;i++)
	{
		cout << "Minimum distance for node = "<<i<<" is = "<<dist[i]<<endl;
	}
}

void dijkstra()
{
	for(int i=0;i<N;i++)
	{
		visited[i] = 0;
		path[i] = -1;
		dist[i] = INT_MAX;
	}

	dist[src] = 0;

	for(int i=0;i<N;i++)
	{
		int u = GetMin();
		if(u == dest)
			break;
		visited[u] = 1;
		for(int v=0;v<N;v++)
		{
			if((!visited[v]) && adj[u][v] && (dist[u] != INT_MAX) && (dist[v] > dist[u] + adj[u][v]))
			{
				dist[v] = dist[u] + adj[u][v];
				path[v] = u;
			}
		}
	}
	Print();
}

int _tmain(int argc, _TCHAR* argv[])
{	
	N=9;
	cin >> src >> dest;
	dijkstra();
	return 0;
}

