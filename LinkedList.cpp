#include <bits/stdc++.h> 
using namespace std; 

class Node
{
    public:
      int data;
      Node *next;
      Node(int data)
      {
        this->data = data;
        this->next = NULL;
      }
};  

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}



int length(Node *head) {
    int l=0;
    while(head!=NULL)
    {
        l++;
        head=head->next;
    }
    return l;
}



void printIthNode(Node *head,int i) 
{
    int l=0;
    Node *temp=head;
    Node *t=head;
    while(temp!=NULL)
    {  
        l++;
        temp=temp->next;
    }
    
    if(i<l)
    {
      for(int j=0;j<i;j++)
      {
          t=t->next;
      }
        cout<<t->data;
    }
    
}


Node* deleteNode(Node *head, int index) {   
      
      if(index==0)
      {
        head=head->next;
        return head;
      }
      int l=0;
      Node *temp=head;
      while(temp!=NULL)
      {
        l++;
        temp=temp->next;
      }
      if(index<l)
      {
      if(index==l-1)
      { temp=head;
        Node *preptr=NULL;
        while(temp->next!=NULL)
        { 
          preptr=temp;
          temp=temp->next;
        }
        preptr->next=NULL;
      }
      else
      {
        temp=head;
        int c=0;
        while(c<index-1)
        {
          temp=temp->next;
          c++;
        }
        temp->next=temp->next->next;
      }
      }
      else
      {
        return head;
      }
      return head;
}

Node* append_LinkedList(Node* head,int n)
{
    Node *temp=head;
    int l=0;
    while(temp->next!=NULL)
    {
        l++;
        temp=temp->next;
    }
    temp->next=head;
    
    int x=l-n;
    
    Node *temp1=head;
    for(int i=0;i<x;i++)
    {
        temp1=temp1->next;
    }
    head=temp1->next;
    temp1->next=NULL;
    return head;
}

bool check_palindrome(Node* head)
{
    
    Node *temp=head;
    int l=0;
    
    while(temp!=NULL) //to find the length
    {
        l++;
        temp=temp->next;
    }
    
    temp=head;
    for(int i=0;i<l/2-1;i++) //to divide into two halves
    {
        temp=temp->next;
    }
    Node *head1=head;
    Node *head2=temp->next;
    temp->next=NULL;
    
    
    Node *current=head2; //to reverse the second half
    Node *prev, *nextt;
    prev=NULL;
    nextt=NULL;
    while(current !=NULL)
    {
      nextt=current->next;
      current->next=prev;
      prev=current;
      current=nextt;
    }
    head2= prev;
    
    while(head1!=NULL && head2!=NULL)
    {    
      if(head1->data == head2->data)
      {   
        head1=head1->next;
        head2=head2->next;
      }
      else
        return false;
    }
    return true;
    
}

int main(){
  Node* head= takeinput();
  cout<<"Length of the linked list is: "<<length(head);
  printIthNode(head, 2);

}