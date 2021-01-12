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


node* mergeSort(node *head)
{
	//Base Case
	if(head == NULL || head->next == NULL)
	{
		return head;
	}
	
	//Recursive Case
	
	//1.Divide
	
	node *mid1 = mid(head);
	
	node *a = head;
	node *b = mid1->next;
	mid1->next = NULL;
	
	//2.Sort
	a = mergeSort(a);
	b = mergeSort(b);
	
	//3.Merge
	node *ans = merge(a,b);
	return ans;
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
		
		mergeSort(head);
		
		print(head);
        cout<<endl;
        
   return 0;
}
