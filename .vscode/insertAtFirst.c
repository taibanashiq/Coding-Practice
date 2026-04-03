#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node *next;
};
void linkedlistTraversal(struct node * ptr)
{
    while (ptr != NULL){
    printf("element:%d\n",ptr->data);
    ptr=ptr->next;
}
}
struct node * insertATFirst(struct node *head,int data){
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next= head;
    ptr->data=data;
    return ptr;
}
int main(){
    struct node *head;
     struct node *second;
      struct node *third;
      struct node *fourth;
    //   allocate memory for nodes in the linked list in heap
    head= (struct node *)malloc(sizeof(struct node));
     second= (struct node *)malloc(sizeof(struct node));
    third= (struct node *)malloc(sizeof(struct node));
    fourth= (struct node *)malloc(sizeof(struct node));
    
    // link first and second nodes
    head->data=7;
    head->next=second;

    // link second and third nodes
    second->data=11;
    second->next=third;

    // terminare the list at the third node
    third->data=66;
    third->next = fourth;

    fourth->data=13;
    fourth->next=NULL;
    linkedlistTraversal(head);
    head = insertAtFirst(head,56);
    linkedListTraversal(head);

    return 0;
}


