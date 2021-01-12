#include<bits/stdc++.h>
using namespace std;
#define bool int

class node
{
	public:
		int data;
		node * left;
		node * right;
};

bool isBal(node *root,int *height)
{
	int lh = 0, rh = 0;
	int l = 0, r = 0;
	
	if(root == NULL)
	{
		*height = 0;
		return 1;
	}
	
	l = isBal(root->left,&lh);
	r = isBal(root->right,&rh);
	
	*height = (lh>rh ? lh : rh) + 1;
	
	if(abs(lh - rh )>=2)
	{
		return 0;
	}
	else
		return 1;
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}

int main()
{
	int height = 0;
	node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(6);
	
	if(isBal(root,&height)){
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
}
