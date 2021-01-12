#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[5][6];
	
	int value = 0;
	
	for(int i=0;i<5;i++)
	{
		for(int k=0;k<6;k++)
		{
			arr[i][k] = value;
			value++;
		}
	}
	
	for(int i=0;i<5;i++)
	{
		for(int k=0;k<6;k++)
		{
			cout<<arr[i][k]<<" ";
		}
		cout<<endl;
	}
	
	int i = 0,j = 5;
	int key = 29;
	
	while(i<=4 or j>=0)
	{
		if(arr[i][j] > key)
		{
			j--;
		}
		else if(arr[i][j]<key)
		{
			i++;
		}
		else if(arr[i][j] == key)
		{
			cout<<i<<" "<<j<<" "<<arr[i][j]<<endl;
			return 0;
		}
	}
	cout<<"Not in array";
	
	
}
