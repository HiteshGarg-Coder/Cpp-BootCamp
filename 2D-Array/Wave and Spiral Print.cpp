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
	cout<<"\n Wave: \n";
	
	//waveprint(a,row,col);

	//Iterate Over Columns
	for(int j = 0;j<col;j++)
	{
		//odd or even
		if(j&1)
		{
			//Odd Column
			
			for(int i = row-1;i>=0;i--)
			{
				cout<<a[i][j]<<" ";
			}
		}
		else
		{
			for(int i = 0;i<row;i++)
			{
				cout<<a[i][j]<<" ";
			}
		}
	}
	
	cout<<"\n\n Spiral : \n";
	
	//Spiral Print
	
	int startRow = 0,endRow = row -1 ,startcol = 0,endcol = col -1 ;
	
	while(startRow <= endRow && startcol <= endcol)
	{
		//Print start row first
		
		for(int j = startcol; j<= endcol;j++)
		{
			cout<<a[startRow][j]<<" ";
		}
		startRow++;
		
		//Print endcol
		for(int j = startRow; j<= endRow;j++)
		{
			cout<<a[j][endcol]<<" ";
		}	
		endcol--;
			
		//Print endRow   - 
		if(startRow < endRow)
		{
		 for(int j = endcol; j>= startcol;j--)
		 {
			cout<<a[endRow][j]<<" ";
		 }
		endRow--;
		}
		
		//Print startCol
		if(startcol < endcol)
		{
		 for(int j = endRow; j>= startRow;j--)
		 {
			cout<<a[j][startcol]<<" ";
		 }
		startcol++;
		}
	}
}
