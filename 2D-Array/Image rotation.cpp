#include<bits/stdc++.h>
using namespace std;

void create(int arr[5][5])
{
	int value = 0;
	for(int i=0;i<5;i++)
	{
		for(int k=0;k<5;k++)
		{
			arr[i][k] = value;
			value++;
		}
	}
}

void print(int arr[5][5])
{
	for(int i=0;i<5;i++)
	{
		for(int k=0;k<5;k++)
		{
			cout<<arr[i][k]<<" ";
		}
		cout<<endl;
	}
}

void trans(int arr[5][5])
{
	for(int i=0;i<5;i++)
	{
		for(int k=i;k<5;k++)
		{
			int temp = arr[i][k];
			arr[i][k] = arr[k][i];
			arr[k][i] = temp;
		}
	}
}

void swipe_right(int arr[5][5])
{
	int n = 4,temp;
	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<n/2;j++)
		{
			temp = arr[i][j];
			arr[i][j] = arr[i][n-j];
			arr[i][n-j] = temp;
		}
	}
}

void swipe_left(int arr[5][5])
{
	int n = 4,temp;
	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<n/2;j++)
		{
			temp = arr[j][i];
			arr[j][i] = arr[n-j][i];
			arr[n-j][i] = temp;
		}
	}
}

void right(int arr[5][5])
{
	trans(arr);
	swipe_right(arr);
	
	print(arr);
	cout<<endl<<"--------------------------"<<endl;
}


void left(int arr[5][5])
{
	trans(arr);
	swipe_left(arr);
	
	print(arr);
	cout<<endl<<"--------------------------"<<endl;
}


int main()
{
	int arr[5][5];
	
	create(arr);
	
	print(arr);
	cout<<endl<<"--------------------------"<<endl;

	right(arr);
	
	right(arr);
	
	left(arr);
	
	left(arr);
	
}
