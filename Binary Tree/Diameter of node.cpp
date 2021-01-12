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

int height(node*root){
    if(root==NULL){
        return 0;
    }
   	
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	return max(leftHeight, rightHeight) + 1;

}


int diameter(node *root)
{
	if (root == NULL) {
		return 0;
	}

	//Diameter pass throught root
	int op1 = height(root->left) + height(root->right);
	
	//Diameter pass throught left subtree
	int op2 = diameter(root->left);
	
	//Diameter pass throught right subtree
	int op3 = diameter(root->right);
	
	return max(op1, max(op2, op3));
	
}


int main(){ 
    node* root = buildTree();
    
    print(root);
    cout<<endl;
    
    cout<<height(root);
    cout<<endl;
    
    cout<<diameter(root);

    
      /*
	   
	   8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
	   */
	   
}
