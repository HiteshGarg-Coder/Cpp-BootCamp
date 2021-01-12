#include<bits/stdc++.h>
using namespace std;

int Nstairs(int n)
{
	//Base Case
	if(n<0) return 0;
	
	if(n==0) return 1;
	
	//Recursive Case
	return Nstairs(n-1) + Nstairs(n-2) + Nstairs(n-3);
}

int Nstairs(int n,int k)
{
	//Base Case
	if(n<0) return 0;
	
	if(n == 0) return 1;
	
	//Recursive Case
	int ans = 0;
	for(int i=1;i<=k;i++)
	{
		ans += Nstairs(n-i,k);
	}
	return ans;
}
int main()
{

	int n;
	cin>>n;
	
	int k;
	cin>>k;
		
	cout<<Nstairs(n,k)<<endl;
	
	return 0;
}
