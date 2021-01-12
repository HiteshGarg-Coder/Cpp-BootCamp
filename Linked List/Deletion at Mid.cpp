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

void Deletion_At_End(node *&head,node *&tail)
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
	
		while(temp->next != tail)
		{
			temp = temp->next;
		}
		
		delete tail;
    	tail = temp;
    	temp->next = NULL;
	}
}

int length(node *head)
{
    int len = 0;
    
	while(head != NULL)
    {
        len++;
        head = head->next;
    }
    
	return len;
}

void Deletion_At_Mid(node *&head,node *&tail,int pos)
{
	if(pos == 0)
	{
		Deletion_At_Front(head,tail);
	}
	else if(pos>=length(head)-1)
	{
		Deletion_At_End(head,tail);
	}
	else
	{
		node *temp = head;
		int count = 1;
		
		while(count <= pos-1)
		{
			count++;
			temp = temp->next;
		}
		
		node* n = temp->next;
		temp->next = n->next;
		delete n;
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
	
	Deletion_At_Mid(head,tail,0);
	Deletion_At_Mid(head,tail,3);
	Deletion_At_Mid(head,tail,100);
	
	print(head);

	
}
