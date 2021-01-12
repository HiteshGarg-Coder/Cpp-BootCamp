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

}

node* search(node *head,int key)
{
	while(head)
	{
		if(head->data == key)
		{
			return head;
		}
		head = head->next;
	}
	
	return NULL;
}

int main() {
       
	   node *head = NULL;
       
	   int n;
       cin>>n;
       
	   while(n--)
       {
           int data;
           cin>>data;
           insert_at_last(head,data);
       }        
        
		print(head);
		
		int key;
		cin>>key;
        
        node *z = search(head,key);
        if(z)
		{
			cout<<z->data;
		}
		else
		{
			cout<<"NO data";
		}
   return 0;
}
