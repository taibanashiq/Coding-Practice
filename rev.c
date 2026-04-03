#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
     struct node *next ;
};
struct node *head,*temp;
void insert(int value);
void reverse();
void traverse();
void main()
{
	insert(10);	insert(20); insert(30);
	insert(40);	insert(50); insert(60);
	traverse();
	reverse();
	traverse();

}
void insert(int value)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));  
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
     {
               head=newnode;
               temp=newnode;
      }
      else
      {
      temp->next=newnode;
      temp=newnode;
      }
         
}
void traverse()
{
	struct node * ptr;
    ptr=head;
    printf("list is\n");
    while(ptr!=NULL)
   {
	printf("%d->",ptr->data);
	ptr=ptr->next;
   }
   printf("NULL");
  
}
void reverse()
{
	struct node *prev=NULL,*curr=NULL,*next=NULL;
	curr=head;
	while(curr!=NULL)
	{
	next=curr->next;
	curr->next=prev;
	prev=curr;
	curr=next;
	}
	head=prev;
}