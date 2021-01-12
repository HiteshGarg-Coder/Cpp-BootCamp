#include<bits/stdc++.h>
using namespace std;

void ReverseQueue(queue<int> &q)
{
	if(q.empty())
	{
		return;
	}
	int element = q.front();
	q.pop();
	ReverseQueue(q);
	q.push(element);
}

void Print(queue<int>q)
{
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

int main()
{
	queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	
	Print(q);
	
	ReverseQueue(q);
	
	Print(q);
}
