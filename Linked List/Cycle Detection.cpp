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

bool isCyclic(node *head)
{
	node* slow = head;
	node* fast = head;
	
	while(fast and fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		
		if(fast == slow)  return true;
	}
	
	return false;
}

void CreateCycle(node * &head)
{
 	 node *temp = head;
	   while(temp and temp->next)
	   {
	   	temp = temp->next;
	   }
	   
	   temp->next = head;
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
	   
	   CreateCycle(head);
	          
		if(isCyclic(head))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
			print(head);
			cout<<endl;
		}
        
   return 0;
}
