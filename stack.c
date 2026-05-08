#include <stdio.h>
#include <stdlib.h>
#define max 10
int top=-1,s[max];
void push();
void pop();
void peek();
void traverse();
int isfull();
int isempty();
void main()
{
    char ch;
    int choice;
    do {
        printf("Menu\n1.push\n2.pop\n3.peek\n4.traverse\n5.isfull\n6.isempty\n7.exit\n");
        printf("enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:peek();
            break;
            case 4:traverse();
            break;
            case 5:isfull();
            break;
            case 6: isempty();
            break;
            case 7:
            exit(0);
            default:
            printf("invalid choice\n");
        } printf("would you lke to continue \n");
        scanf("%c",&ch);
 }while(ch=='y'|| ch=='Y');
}void push()
{
    int val;
    if(isfull())
    {
        printf("stack is full\n");
    }
    else
    {
        printf("enter the element \n");
        scanf("%d",&val);
        top++;
        s[top]=val;

    }
}
void pop()
{
int val;
if(isempty())
{
    printf("stack is empty\n");
}
else{
    val=s[top];
    top--;
    printf("value deleted %d\n",val);

}
}
void traverse()
{
    int i;
    if(isempty())
    {
        printf("stack is empty\n");
    }else{
        for(i=0;i<=top;i++)
        {
            printf("%d\n",s[i]);
        }
    }
}
void peek()
    {
        int t;
        if(isempty())
        {
            printf("stack is empty\n");
        }
        else{
            t=s[top];
            printf("top element is %d\n",t);

        }
        
    }
    int isempty()
        
    {
        if(top==-1)
        return 1;
        else 
        return 0;

    }int  isfull()
    {
        if(top>=max-1)
        return 1;
        else 
        return 0;
    }
    
