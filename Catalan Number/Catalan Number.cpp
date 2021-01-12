#include<bits/stdc++.h>
using namespace std;

int dp[100] = {0};

int catalan(int n)
{
	if(n == 0) return 1;
	
	if(dp[n]!= 0) return dp[n];
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		ans += catalan(i-1)*catalan(n-i);
	}
	
	dp[n] = ans;
	return ans;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<catalan(i)<<" ";
	}
}
