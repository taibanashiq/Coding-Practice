#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct  Node* left,*right;
};
struct Node* createNode(int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int height(struct Node* node){
    if(node==NULL)
    return 0;
    int leftheight=height(node->left);
    int rightheight=height(node->right);
    if(leftheight>rightheight)
    return leftheight +1;
    else
    return rightheight +1;

}int main()
{
    struct Node* root=createNode(1);
    root->left=createNode(2);
    root->left->left=createNode(3);
    printf("height of binary tree is %d",height(root));
    return 0;

}

