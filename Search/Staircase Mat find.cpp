#include<bits/stdc++.h>
using namespace std;

int main()
{

 	int row,col;
	cin>>row>>col;
	
	int a[row][col], cnt = 1;
	for(int i = 0;i<row;i++)
	{
		for(int j = 0;j<col;j++)
		{
			a[i][j] = cnt;
			cnt++;
		}
	}
	
	for(int i = 0;i<row;i++)
	{
		for(int j = 0;j<col;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int key;
	cin>>key;
	
	
	int i = 0, j = col - 1;  

	while(i<row && j>= 0){
	if(a[i][j] == key)
	{
		cout<<"Found at "<<i<<" and "<<j<<endl;
		break;
	}
	else if(a[i][j]>key)
	{
		j--;
	}
	else
	{
		i++;
	}
}
}
