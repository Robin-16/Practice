#include<iostream>
using namespace std;

int input[100];
int size;
int arr[100];
int maxVal = 1;
int main()
{
	cin >> size;
	if(size == 0)
	{
		cout <<"Max sequence = 0" << endl;
		return 0;
	}
	for(int i=0;i<size;i++)
	{
		cin >> input[i];
		arr[i] = 1;
	}
	int i = 1,j=0;
	while(i<size)
	{
		if(input[i] > input[j])
		{
			arr[i]= arr[j]+1;	// longest increasing subseq at i would "atleast" be 1 greater than that at j in this case
			if(arr[i] > maxVal)
				maxVal = arr[i];
		}
		if(i == j)
		{
			i++;
			j=0;
			continue;
		}
		j++;
	}
	cout <<"Max sequence = "<< maxVal << endl;
	return 0;
}

/*
IP:
7
3 4 -1 0 6 2 3
*/