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

node *mid(node * head)
{
	if(head==NULL || head->next== NULL)
	{
		return head;
	}
	
	node *slow = head;
	node *fast = head->next;
	
	while(fast!=NULL and fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	
	return slow;
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
		
		node *m = mid(head);
		cout<<m->data;
        cout<<endl;
        
   return 0;
}
