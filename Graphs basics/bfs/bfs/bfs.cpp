// bfs.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include "stdafx.h"
using namespace std;

int arr[10][10];
int V, E;

class Queue
{
	public:
	int count;
	Queue(const int i = 0,const int j = 1);
	int queue[100];
	int curPointer;
	int endPointer;
	void Add(int a);
	int Pop();
	bool Exists(int a);
}

Queue::Queue(int _i, int _j): curPointer(_i), endPointer(_j){
}

void Queue::Add(int a)
{
	queue[endPointer++] = a;
}

int Queue::Pop()
{
	if(curPointer != endPointer)
		return queue[curPointer++];
}

bool Queue::Exists(int a)
{
	bool retVal = false;
	for(int i = curPointer; i <endPointer;i++)
		if(queue[i] == a)
			return true;

	return retVal;

}

int _tmain(int argc, _TCHAR* argv[])
{
	cin >> V >> E;
	for(int i=0;i<E;i++)
	{
		int a,b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}



	return 0;
}

