#include <iostream>
using namespace std;
class node{
    public:
    
	int data;
    node *next;
    
	node(int d)
    {
        data = d;
        next=NULL;
    }
};

void insert_at_head(node *&head,int data)
{
    node *n = new node(data);
    n->next = head;
    head = n;
}


void insert_at_last(node *&head,int data)
{
   if(head==NULL){
        insert_at_head(head,data);
        return;
    }
    
	node*temp=head;
    
	while(temp->next!=NULL){
        temp=temp->next;  
    }
    
	node*n=new node(data);
    
	n->next=temp->next;
    temp->next=n;
    
	return;
}

void print(node *head)
{
    node*temp=head;
    
	while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}

node* merge(node *a,node *b){
    
	if(a==NULL){
        return b;
    }
    
	else if(b==NULL){
        return a;
    }
    
	node *c;
    
	if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    
	else{
        c = b;
        c->next = merge(a,b->next);
    }
    
	return c;
}
int main() {

       node *head1 = NULL;
       node *head2 = NULL;
       
	   int n;
       cin>>n;
       
	   while(n--)
       {
           int data;
           cin>>data;
           insert_at_last(head1,data);
       }
       
	   
	   int m;
       cin>>m;
       
	   while(m--)
       {
           int data;
           cin>>data;
           insert_at_last(head2,data);
       }
        
		node *merged = merge(head1,head2);
        
		print(merged);
        cout<<endl;

  
   
   return 0;
}

