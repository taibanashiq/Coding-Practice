#include<stdio.h>
#include<stdlib.h>
struct circularqueue{
    int size;
    int f;
    int r;
    int* arr;
};
int isempty(struct circularqueue  *q){
    if(q->r==q->f){
    return 1;
}
return 0;
} 
int isFUll(struct circularqueue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    return 0;
} void enqueue(struct circularqueue  *q,int value){
    if(isFull(q)){
        printf("queue is full");
    }else 
    {
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=value;
        printf("enqueued element is %d",value);
    }
}
int dequeue(struct circularqueue *q){
    int a=-1;
    if(isempty(q)){
        printf("this queue is empty");
    }else {
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return 0;
}
int main(){
    struct circularqueue q;
    q.size=5;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,1);
printf("dequeing element is %d", dequeue(&q));
printf("dequeing element is %d", dequeue(&q));
printf("dequeing element is %d", dequeue(&q));
enqueue(&q,45);
enqueue(&q,45);
enqueue(&q,45);
if(isempty(&q)){
    printf("queue is empty");
}if(isfull(&q)){
    printf("queue is full");

}
return 0;
}

