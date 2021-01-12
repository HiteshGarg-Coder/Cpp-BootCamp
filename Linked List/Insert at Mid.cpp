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

void insert_at_Front(node *&head,node *&tail,int data)
{
	if(head == NULL)
	{
		head = tail = new node(data);
		
		return;
	}
    node *n = new node(data);
    n->next = head;
    head = n;
}

void insert_at_End(node *&head,node *&tail,int data)
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

void insert_at_Mid(node *&head,node *&tail,int pos,int data)
{
	if(pos == 0)
	{
		insert_at_Front(head,tail,data);
	}
	else if(pos>=length(head)-1)
	{
		insert_at_End(head,tail,data);
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
		
		node *n = new node(data);
    	n->next = temp->next;
    	temp->next = n;
	}
    
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


int main()
{
	node * head = NULL;
	node * tail = NULL;
	
	insert_at_Front(head,tail,1);
	insert_at_Front(head,tail,2);
	insert_at_End(head,tail,3);
	insert_at_End(head,tail,4);
	insert_at_Mid(head,tail,5,5);
	insert_at_Mid(head,tail,0,6);
	insert_at_Mid(head,tail,3,7);
	
	print(head);
	
}
