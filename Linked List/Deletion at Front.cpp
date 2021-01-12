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

void insert_at_last(node *&head,node *&tail,int data)
{
	if(head == NULL)
	{
		head = tail = new node(data);
		
		return;
	}
    node *n = new node(data);
    tail->next = n;
    tail = n;
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

void Deletion_At_Front(node *&head,node *&tail)
{
	if(head == NULL)
	{
		return;
	}
	else if(head->next==NULL)
	{
		delete head;
		head = tail = NULL;
	}
	else
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}
}


int main()
{
	node *head = NULL;
	node *tail = NULL;
       
 	   int n;
       cin>>n;
       
	   while(n--)
       {
           int data;
           cin>>data;
           insert_at_last(head,tail,data);
       }
	
	print(head);
	
	Deletion_At_Front(head,tail);
	Deletion_At_Front(head,tail);
	
	print(head);
	
}
