// topological.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include "stdafx.h"
using namespace std;

int arr[10][10];
int indegree[10];
int v,e;

int queue[10];
int queuePointer;

void topological(int a)
{
	for(int i=1;i<=v;i++)
	{
		if(arr[a][i])
		{
			indegree[i]-=1;
			if(indegree[i] == 0)
			{
				queue[queuePointer++] = i;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cin >> v >> e;
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin >> a >> b;
		arr[a][b] = 1;
		indegree[b]+=1;
	}

	for(int i=1;i<=v;i++)
	{
		if(indegree[i] == 0)
			queue[queuePointer++] = i;
	}

	for(int i=0;i<queuePointer;i++)
	{
		topological(queue[i]);
	}
	cout<<endl;
	for(int i=0;i<queuePointer;i++)
	{
		cout << queue[i] << " ,"; 
	}
	cout<<endl;
	return 0;
}

