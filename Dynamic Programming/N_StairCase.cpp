// N_StairCase
#include <iostream>
using namespace std;

int NStairs(int n,int k,int *dp){
	if(n==0){
		dp[n] = 1;
		return 1;
	}
	if(n<0){
		return 0;
	}
	if(dp[n]!=-1){
		return dp[n];
	}

	int ans = 0;
	for(int i=1;i<=k;i++){
		ans += NStairs(n-i,k,dp);
	}
	dp[n] = ans;
	return ans;
}

int FastStairs(int n,int k){
	int *dp = new int[n+1];
	dp[0] = dp[1] = 1;

	for(int stair = 2;stair<=n;stair++){
		if(stair-k-1>=0){
			dp[stair] = 2*dp[stair-1]-dp[stair-k-1];
		}
		else{
			dp[stair] = 2*dp[stair-1];
		}
	}
	for(int i=0;i<=n;i++){
		cout<<dp[i]<<' ';
	}
	cout<<endl;
	return dp[n];	
}

int main(){
	int n;
	cin>>n;
	
	int dp[10001];
	for(int i = 0;i<=10000;i++){
		dp[i] = -1;
	}

	int k;
	cin>>k;
	
	cout<<NStairs(n,k,dp)<<endl;
	cout<<FastStairs(n,k)<<endl;

	return 0;
}
