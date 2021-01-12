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
	insert_at_Front(head,tail,3);
	insert_at_Front(head,tail,4);
	insert_at_Front(head,tail,5);
	insert_at_Front(head,tail,6);
	
	print(head);
	
}
