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


node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}


void print(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int count(node*root){
    if(root==NULL){
        return 0;
    }
    int leftSize = count(root->left);
	int rightSize = count(root->right);

	int total = leftSize + 1 + rightSize;
	return total;
}


int main(){ 
    node* root = buildTree();
    
    print(root);
    cout<<endl;
    
    cout<<count(root);    
      /*
	   
	   8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
	   
	   */
}
