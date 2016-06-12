// Strings permute.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include "stdafx.h"
using namespace std;
int t;

void Print(char arr[])
{
	for(int i=0;i<t;i++)
		cout<<arr[i];

	cout << endl;
}

void Permute(char input[],int count[],char result[],int length,int depth)
{
	if(depth == t)
	{
		Print(result);
		return;
	}

	for(int i=0;i<length;i++)
	{
		if(count[i] == 0)
			continue;

		result[depth] = input[i];
		count[i]-=1;
		Permute(input,count,result,length,depth+1);
		count[i]+=1;	// IMPORTANT: increment the count by one again, as we are back to old depth and here the count was +1
	}
}

int Present(char a,char ip[],int len)
{
	int ret = -1;
	for(int i=0;i<len;i++)
	{
		if(ip[i] == a)
			return i;
	}
	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char ip[10], input[10], result[10];
	int count[10];

	for(int i=0;i<10;i++)
		count[i] = 0;

	cin >> ip;
	int len = 0;	// total length of input string
	int length = 0; // current pointer for input[] and count[]
	while(ip[len] != '\0')
		len++;
	
	for(int i=0;i<len;i++)
	{
		int res = -1;
		res = Present(ip[i],input,len);
		if(res == -1)
		{
			input[length] = ip[i];
			count[length]+=1;
			length++;
		}
		else
		{
			count[res]++;
		}
	}

	input[length+1] = '\0';
	t = len;
	Permute(input,count,result,length,0);
	return 0;
}

