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

void insert_at_last(node *&head,int data)
{
   if(head==NULL){
        node *n = new node(data);
    	n->next = head;
    	head = n;
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
    
    cout<<"NULL"<<endl;

}

node* reverse(node *&head,node *&tail)
{
	node *p = NULL;
	node *c = head;
	while(c)
	{
		node *n = c->next;
		c->next = p;
		p =c;
		c= n;
	}
	
	tail = head;
	head = p;
}

int main() {
       
	   node *head = NULL;
	   node *tail = NULL;
       
	   int n;
       cin>>n;
       
	   while(n--)
       {
           int data;
           cin>>data;
           insert_at_last(head,data);
       }        
        
		print(head);
		
		reverse(head,tail);
		
		print(head);
        
        
   return 0;
}
