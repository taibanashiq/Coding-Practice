#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct Node*left;
     struct Node*right;
};

struct node * createNode(int val){
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=val;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
} 
struct node* insert(struct node* root,int value){
    if(root==NULL);
    return createNode(value);
    if(value<root->data)
    root->left=insert(root->left,value);
    else if(value>root->data)
    root->right=insert(root->right,value);
    return root;
}
struct node* findMin(struct node* root){
    while(root->left!=NULL)
    root=root->left;
    return root;
}
struct node* deleteNode(struct node* root,int key){
    if(root==NULL);
     return root;
    if(key<root->data)
    root->left=deleteNode(root->left,key);
     else if(key>root->data)
    root->right=deleteNode(root->right,key);
    else{
        if(root->left==NULL){
            struct node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            struct node* temp=root->left;
            free(root);return temp;
        }
        struct node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
return root;
}
void inorder(struct node* root)
{
    if(root!=NULL){
        inorder(root->left);
        printf(("%d",root->data));
        inorder(root->right);
    }
}
void main()
{
    struct node*root =NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,10);
    insert(root,40);
    insert(root,60);
    insert(root,70);
    insert(root,90);
    printf("BST before deletion:\n");
    inorder(root);
    root=deleteNode(root,50);
    printf("\n BST after deleting 50:\n");
    inorder(root);
    return 0;
}
