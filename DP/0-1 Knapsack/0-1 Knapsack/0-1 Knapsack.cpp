#include<iostream>
using namespace std;
#define MAX(a,b) (((a)>(b))?(a):(b))
int arr[5][8];

int main()
{
	int Wt = 7;
	int weight[5] = {0,1,3,4,5};
	int value[5] = {0,1,4,5,7};

	for(int i=0;i<5;i++)
		arr[i][0] = 0;

	for(int i=0;i<8;i++)
		arr[0][i] = 0;

	for(int i = 1;i<5;i++)
	{
		for(int j = 1; j<8;j++)
		{
			if(weight[i] > j)
				arr[i][j] = arr[i-1][j];
			else
				arr[i][j] = MAX(arr[i-1][j], (value[i] + arr[i-1][j-weight[i]]));
		}
	}
	cout << "Max value = "<<arr[4][7];
	return 0;
}