#include<stdio.h>
struct Node{
    int data;
    struct Node *next;
};
int main()
{
    struct Node n1,n2;
    scanf("%d",&n1.data);
    scanf("%d",&n2.data);
    n1.next=&n2;
    n2.next=NULL;
    printf("%d\n",n1.data);
    printf("%d\n",n1.next->data);
    return 0;
}
