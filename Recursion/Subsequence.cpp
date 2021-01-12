#include<bits/stdc++.h>
using namespace std;

void gen_subseq(char *in,char *out,int i,int j)
{
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}
	
	out[j] = in[i];
	
	gen_subseq(in,out,i+1,j+1);
	gen_subseq(in,out,i+1,j);
}

int main()
{
	char input[] = "abc";
	
	char output[10];
	
	gen_subseq(input,output,0,0);
}
