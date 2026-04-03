#include<stdio.h>
#include<stdlib.h>
typedef struct node
{

     int data ;
     struct node *next;
}node;
node *head = NULL;
int count=0;
void insertSLLVal();
void display();
int main()
{
    int choice;
    while(1)
    {
        printf("\n.insert(sorted)");
        printf("\n2. display");
        printf("\n3. exit");
        printf("\n enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insertSLLVal();
            break;
            case 2:
            display();
            break;
            case 3:
            exit(0);
            default:printf("invalid choice\n");
        }
    }
    return 0;
} 
void insertSLLVal()
{
    int val;
    node *newnode,*temp=head;
    newnode=(node*)malloc(sizeof(node));
    if (newnode==NULL)
    {
        printf("memory allocation failed\n");
        return;
    }
    printf("enter the value\n");
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else if(newnode->data<head->data)
    {
        newnode->next=head;
        head=newnode;
    }
    else{

        while (temp->next != NULL && newnode->data >= temp->next->data)

        {
            temp=temp->next;
        }
            newnode->next=temp->next;
            temp->next=newnode;
        
        count++;
    }
}
void display()
{
    node *temp = head;
if (head==NULL)
{
    printf("list is empty\n");
    return;
}
printf("linked list:");
while(temp!=NULL)
{
    printf("%d->",temp->data);
    temp=temp->next;
}
printf("NULL\n");
}