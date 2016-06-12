// Basic DP solutions without use of any STL

#include<iostream>
using namespace std;

char str1[100];
char str2[100];
int maxVal,str1Size,str2Size;

int dp[101][101]; // array of size 1 + str1,2

int main()
{
	cout << "Enter 2 strings of length less than 100" << endl;
	cin >>str1 >> str2;
	
	while(str1[str1Size]!='\0')
		str1Size++;
	
	while(str2[str2Size]!='\0')
		str2Size++;

	for(int i=1;i<=str2Size;i++)
	{
		for(int j=1;j<=str1Size;j++)
		{
			if(str1[j] == str2[i])
			{
				dp[i][j] = dp[i-1][j-1]+1;
				if(dp[i][j] > maxVal)
					maxVal = dp[i][j];
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}

	cout << "Max substring size ="<< maxVal << endl;
	return 0;
}