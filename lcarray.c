#include<stdio.h>
#include<stdlib.h>
typedef streuct circularQueue {
    int data
    struct circularQueue *ptr;
}
QCSLL *front=NULL,*raer=NULL;
void insert(){
    int val;
    QCSLL *newnode=malloc(sizeof(QCSLL));
    if(newnode==NULL){
        printf("error");
        return;

    }
    printf("val");
    scanf("%d",&val);i
    if(front=NULL && rear==NULL){
        front=rear=newnode;
        rear->ptr=newnode;

    }else {
        raer->ptr=newnode;
        rear=newnode;
        rear->ptr=front;
    }
    count++;
}