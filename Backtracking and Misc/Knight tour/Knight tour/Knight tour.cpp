#include<iostream>
using namespace std;

int N;
int visited[10][10];

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

int NotValid(int row,int col)
{
	if(row < 0 || row > 8 || col < 0 || col > 8 || visited[row][col] != -1)
		return 1;

	return 0;
}

int Recurse(int row,int col,int val)
{	
	if(val == 64)
	{
		cout << "solution found" << endl;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				cout << visited[i][j] << "\t";
			}
			cout << endl;
		}
		return 1;
	}

	for(int i=0;i<8;i++)
	{
		int nextX = row+xMove[i];
		int nextY = col+yMove[i];
		if(NotValid(nextX,nextY))
		{
			continue;
		}
		else
		{
			visited[nextX][nextY] = val;
			if(Recurse(nextX,nextY,val+1))
			{
				return 1;
			}
			else
			{
				visited[nextX][nextY] = -1;
			}
		}
	}

	return 0;
}

int main()
{
	N = 8;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			visited[i][j] = -1;
		}
	
	}
	visited[0][0] = 0;
	Recurse(0,0,1);

	return 0;
}
