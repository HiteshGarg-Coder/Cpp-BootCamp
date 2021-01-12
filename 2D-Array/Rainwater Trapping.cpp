#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int height[n];
	
	for(int i = 0;i<n;i++)
	{
		cin>>height[i];
	}
	
	int left[n],right[n];
	left[0] = height[0];
	right[n-1] = height[n-1]; 
	
	for(int i = 1;i<n;i++)
	{
		left[i] = max(left[i-1],height[i]);
		
		right[n-i-1] = max(right[n-i],height[n-i-1]);
	}
	
	int sum = 0;
	for(int i = 0;i<n;i++)
	{
		sum = sum +  min(left[i],right[i]) - height[i];
	}
	
	cout<<sum<<endl;
}

/*
10
0 2 1 3 0 1 2 1 2 1
*/ 
