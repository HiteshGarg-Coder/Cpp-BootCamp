#include<bits/stdc++.h>
using namespace std;

void permute(char *in,int i)
{
	//Base Case
	if(in[i] == '\0')
	{
		cout<<in<<" ";
		return;
	}
	
	//Recursive case
	
	for(int j = i;in[j]!='\0';j++)
	{
		swap(in[i],in[j]);
		permute(in,i+1);
		swap(in[i],in[j]);
	}
}

int main()
{
 	char in[100] = "abcd";
	permute(in,0);
}
