#include<bits/stdc++.h>
using namespace std;
bool are(string s)
{
	stack<char>c;
	char x;
	for(int i = 0;i<s.length();i++)
	{
		if(s[i] == '(' || s[i] =='{' || s[i] == '[')
		{
			c.push(s[i]);
			continue;
		}
		if(s.empty()) return false;
		switch(s[i])
		{
			case ')' : 
					x = c.top();
					c.pop();
					if(x == '{' || x == '[')
					{
						return false;
					}
					break;
			case '}' : 
					x = c.top();
					c.pop();
					if(x == '(' || x == '[')
					{
						return false;
					}
					break;
			case ']' : 
					x = c.top();
					c.pop();
					if(x == '{' || x == '(')
					{
						return false;
					}
					break;
		}
	}
	return c.empty();
}
int main()
{
	string s;
	cin>>s;
	if(are(s))
	{
		cout<<"Balanced";
	}
	else
	{
		cout<<"Not Balanced";

	}
}
