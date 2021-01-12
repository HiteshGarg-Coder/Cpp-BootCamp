#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};


void print(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}


void bfs(node *root){
	if(root == NULL) return;
	
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}


node* LevelOrderInput()
{
	node* root = NULL;
	
	int data;
	cin>>data;
	
	if(data==-1) {
	   return root;	
	}
	
	root = new node(data);
	queue<node*>q;
	q.push(root);
	
	while(!q.empty())
	{
		node* t = q.front();
		q.pop();
		
		cout<<"Enter the child of "<<t->data<<" : ";
		int c1,c2;
		cin>>c1>>c2;
		
		if(c1 != -1)
		{
			t->left = new node(c1);
			q.push(t->left);
		}
		
		if(c2 != -1)
		{
			t->right = new node(c2);
			q.push(t->right);
		}
	}
	return root;
}



int main(){ 
    node* root = LevelOrderInput();
    
    print(root);
    cout<<endl;
    
    bfs(root);
    

    
      /*
	   
	   8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
	   
	   */
}
