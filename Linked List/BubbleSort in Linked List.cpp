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

void BubbleSort(node *&head)
{
	int n = length(head);
	
	for(int i = 1;i<=n-1;i++)
	{
		node *c = head;
		node *p = NULL;
		node *n;
		while(c and c->next)
		{
			n = c->next;
			
			if(c->data > n->data)
			{
				//Swapping will happen
				if(p == NULL)
				{
					//Head will change
					c->next = n->next;
					n->next = c;
					head = p = n;
				}
				else
				{
					//Head won't change
					c->next = n->next;
					n->next = c;
					p->next = n;
					p = n;
				}
			}
			else
			{
				//Swapping won't occur
				p = c;
				c = n;
			}
	 	} 
		
		
	}
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
		cout<<endl;
		
		BubbleSort(head);
		
		print(head);
        cout<<endl;
        
   return 0;
}
