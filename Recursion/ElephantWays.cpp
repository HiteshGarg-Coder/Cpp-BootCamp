#include<bits/stdc++.h>
using namespace std;

int ways(int n,int k)
{
	//Base Case	
	if(n == 0 and k ==0) return 1;
	
	//Recursive Case
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans += ways(i,k);
	}
	for(int i=0;i<k;i++)
	{
		ans += ways(n,i);
	}
	return ans;
}
int main()
{

	int n;
	cin>>n;
	
	int k;
	cin>>k;
		
	cout<<ways(n,k)<<endl;
	
	return 0;
}
