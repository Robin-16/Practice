#include<iostream>
using namespace std;

int arr[10][10];
int path[10][10];

int targetR,targetC,N;

int Dfs(int row,int col)
{
	if(row == targetR && col == targetC)
		return 1;
	if(row <0 || row > N || col < 0 || col > N)
		return 0;

	path[row][col] = 1;
	// Move forward
	if(arr[row][col+1])
	{
		int ret = Dfs(row,col+1);
		if(ret)
			return 1;
	}
	
	if(arr[row+1][col])
	{
		int ret = Dfs(row+1,col);
		if(ret)
			return 1;
	}
	
	path[row][col] = 0;
	return 0;
}

int main()
{
	N = 4;
	targetR = 3;
	targetC = 3;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> arr[i][j];

	Dfs(0,0);

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout << path[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}