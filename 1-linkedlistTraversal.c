#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkedlistTraaversal(struct Node *ptr)
{
    while(ptr !=NULL)
{ 
    printf("element: %d\n",ptr->data);
ptr=ptr->next;
}
}

struct Node *insertATfirst(struct Node *head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;};

struct Node *insertAtindex(struct Node *head,int data,int index)
{
struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
struct Node *p=head;
int i=0;
while(i!= index-1)
{p=p->next;
    i++;

}
ptr->data=data;
ptr->next=p->next;
ptr->next=ptr;
return head;
}
struct Node *insertAtEnd(struct Node *head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct Node *insertAtafterNode(struct Node *head,int data,struct Node *prevNode)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}
int main(){
    struct Node *head;
     struct Node *second;
      struct Node *third;
       struct Node *fourth;


    head=(struct Node*)malloc(sizeof(struct Node));
        second=(struct Node*)malloc(sizeof(struct Node));
            third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

head->data=7;
head->next=second;
second->data=21;
second->next=third;
third->data=31;
third->next=fourth;
fourth->data=18;
fourth->next=NULL;
printf("linked list before insertion \n");
head=insertATfirst(head,45);

printf("\n linked list after insertion\n");
printf("linked list after  insertion \n");
return 0;
}


