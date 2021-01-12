#include <bits/stdc++.h>
using namespace std;

/*
* Node class definition for your reference. 
* Do not modify this class or your code may not work.
*/


class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

class TreeIterator
{
	void inorder(Node *root){
		if(root == NULL){
			return;
		}
		inorder(root->left);
		v.push_back(root->data);
		inorder(root->right);
	}
	
public:
	vector<int> v;
	int i;
    TreeIterator(Node *root)
    {	i = 0;
    	inorder(root);
    }

    /** @return the next smallest number */
    int next()
    {
    	return v[i++];
    	
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
    	return i < v.size();
    }
};


/*
*
*
*   You do not need to refer or modify any code below this. 
*   Only modify the TreeIterator class definition.
*
*
*/


Node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main()
{
    Node *root = buildTree();

    TreeIterator t(root);
    int c = 0;

    while (t.hasNext())
    {
        if (c / 10 % 2 == 1)
        {
            cout << t.hasNext() << " ";
        }
        if (c % 7 == 0)
        {
            cout << "^ ";
        }
        cout << t.next() << " ";
        c++;
    }

    return 0;
}
