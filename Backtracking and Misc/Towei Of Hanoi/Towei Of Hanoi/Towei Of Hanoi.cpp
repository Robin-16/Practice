// Towei Of Hanoi.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include "stdafx.h"
using namespace std;

struct node{
	int val;
	struct node *next;
	struct node *prev;
};

class Stack
{
public:
void Push(node n, node *head);
node Pop(node *head);
};

void Stack::Push()
{

}

Stack stack;

void TOH(int size, int from[], int to[], int aux)
{

}

int _tmain(int argc, _TCHAR* argv[])
{
	int rings;
	cin >> rings;
	int from[5],to[5],aux[5];
	return 0;
}

