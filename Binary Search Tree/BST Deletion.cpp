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

//Accepts the old root node & data and returns the new root node 
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}


node* build(){
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;

    node*root = NULL;

    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}


//Print the BST Level By Level
void bfs(node *root){
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


//Inorder Print
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}

node* deleteInBst(node* root,int data)
{
	if(root==NULL){
        return NULL;
    }
	else if(data<root->data){
        root->left = deleteInBst(root->left,data);
        return root; 
    }
	else if(root->data == data)
	{
		//Case 1: NO Child
		if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
		
		//Case 2: Only 1 Child
		
		if(root->left!=NULL && root->right==NULL){
                node* temp = root->left;
                delete root;
                return temp;
        }		
		if(root->right!=NULL && root->left==NULL){
                node* temp = root->right;
                delete root;
                return temp;
        }
		
		//Case 3: 2 Child
		
		node *replace = root->right;
            //Find the inorder successor from right subtree
            while(replace->left!=NULL){
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteInBst(root->right,replace->data);
            return root;
	}
	else
	{
		root->right = deleteInBst(root->right,data);
		return root;
	}
}

int main(){ 
    node*root = build();
    
	inorder(root);
    cout<<endl;
    
	bfs(root);
    cout<<endl;
    
    int s;
    cin>>s;

    root = deleteInBst(root,s);
    
    cout<<endl;
    inorder(root);
    cout<<endl;
    
	bfs(root);
    cout<<endl;
    
    
    /*
        5 3 7 1 6 8 -1
    */

return 0;
}
