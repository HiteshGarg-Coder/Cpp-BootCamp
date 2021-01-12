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


class Pair {
public:
	int height;
	int diameter;
};

Pair fastDiameter(node* root) {
	Pair p;
	if (root == NULL) {
		p.diameter = p.height = 0;
		return p;
	}
	
	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);
	
	p.height = max(left.height,right.height)+1;
	
	//Diameter pass throught root
	int op1 = left.height + right.height;
	
	//Diameter pass throught left subtree
	int op2 = left.diameter;
	
	//Diameter pass throught right subtree
	int op3 = right.diameter;
	
	p.diameter =  max(op1, max(op2, op3));
	
	return p;
}

int main(){ 
    node* root = buildTree();
    
    print(root);
    cout<<endl;
    
    Pair p = fastDiameter(root);
    cout<<p.height<<endl<<p.diameter;

    
      /*
	   
	   8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
	   */
	   
}
