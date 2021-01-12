#include<bits/stdc++.h>
using namespace std;

int length(char *a)
{
	int i;
	while(a[i]!='\0')
	{
		i++;
	}
	return i;
}

void rotate(char *a,int k)
{
	int l = length(a);
	
	int i = l;
	
	cout<<a<<endl;
	while(i>=0)
	{
		a[i+k] = a[i];
		i--;
	}
	int j=0;
	i = l;
	while(j!=k)
	{
		a[j] = a[i];
		i++;
		j++;
	}
	a[l] = '\0';
	cout<<a<<endl;
}

int main()
{
	char a[100];
	int k;
	
	cin>>a>>k;
	
	rotate(a,k);
	
	return 0;
}
