#include<bits/stdc++.h>
using namespace std;

int ways(int n,int k)
{
	//Base Case
	if(n<0 || k<0) return 0;
	
	if(n == 0 and k ==0) return 1;
	
	//Recursive Case
	return ways(n-1,k) + ways(n,k-1);
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
