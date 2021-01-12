#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
	long long int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(k>=n)
	{
		int p = (k/n)%3;
		if(p == 0)
		{
			if(n%2 == 1)
			{
				a[n/2] = 0;
			}
		}
		else if(p == 2)
		{
			
			long long int m= n/2;
			for(int j=n-1,i=0;i<m;i++,j--)
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] ^= tmp;
			}	
			if(n%2 == 1)
			{
				a[m] = 0;
			}
		}
		else if(p == 1)
		{
			long long int m= n/2;
			for(int j=n-1,i=0;i<m;i++,j--)
			{
				int tmp = a[j];
				a[j] = a[i];
				a[i] ^= tmp;
			}
			if(n%2 == 1)
			{
				a[m] = 0;
			}	
		}
	}
	k %= n;
	for(int i=0;i<k;i++)
	{
		a[i] = a[i]^a[n-i-1]; 
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
}
