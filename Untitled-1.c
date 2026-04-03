#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    printf("%d",ptr->data);
    while(ptr!= NULL);
    {
        printf("elements:%d\n",ptr->data);
        ptr =ptr->next;
    }
}

struct Node *insertATFirst(struct Node *head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=data;
    ptr->data=head;
    return ptr;
}
struct Node *insertATEND(struct Node *head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=data;
    struct Node *ptr=head;
    while(p->next=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct Node *insertATEND(struct Node *head,int data,int index)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=ptr->next;
    p->next=ptr;
    return head;
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head=(struct Node*)malloc(sizeof(struct Node));
     second=(struct Node*)malloc(sizeof(struct Node));
      third=(struct Node*)malloc(sizeof(struct Node));
       head->data=67;
       head->next=second;

        second->data=35;
       second->next=third;

        third->data=17;
       third->next=NULL;
       printf("linked linked before isertion\n");
       linkedlistTraversal(head);
       head=insertATEND(head,78);
       printf("linked linked after isertion\n");
       linkedlistTraversal(head);
       return 0;
}