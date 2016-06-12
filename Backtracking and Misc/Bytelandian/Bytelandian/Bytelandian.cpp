#include<iostream>
#include<map>
using namespace std;

map<int,long long int> arr;

long long int Find(long long int val)
{
	if(val < 12)
		return val;
 
	if(arr[val] != 0)
		return arr[val];
 
	long long int temp = (Find(val/2) + Find(val/3) + Find(val/4));
	
	if(temp > val)
		arr[val] = temp;
	else
	arr[val] = val;

	return temp;
	
}
 
int main()
{
	for(int i = 0; i < 12; i++)
		arr[i] = i;
	
	long long int coin;
	cin >> coin;
	while(!cin.fail())
	{
		cout << Find(coin) << endl;
		cin >> coin;
	}
	return 0;
} 