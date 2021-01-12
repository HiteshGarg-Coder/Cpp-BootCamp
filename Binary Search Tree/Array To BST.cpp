#include <iostream>
#include<queue>
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

node* ArrayToBst(int *a,int s,int e)
{
	//Base Case
	if(s>e)
	{
		return NULL;
	}
	
	int mid = (s+e)/2;
	
	node* root = new node(a[mid]);
	root->left = ArrayToBst(a,s,mid-1);
	root->right = ArrayToBst(a,mid+1,e);
	
	return root;
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


int main(){ 

	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(int);
	
    node* root = ArrayToBst(arr,0,n-1);
    print(root);
    cout<<endl;
    
    bfs(root);

return 0;
}
