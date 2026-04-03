// #include<stdio.h>
// #include<malloc.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// };
// struct node* createNode(int data){
//     struct node *n;
//     n=(struct node*)malloc(sizeof(struct node));
//     n->data=data;
//     n->left=NULL;
//     n->right=NULL;
//     return n;
// }
// void preorder(struct node* root){
//     if (root!=NULL){
//         printf("%d",root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }


//         int main(){
//             struct node *p=createNode(4);
//             struct node *p1=createNode(1);
//             struct node *p2=createNode(6);
//             struct node *p3=createNode(5);
//             struct node *p4=createNode(2);
//             p->left=p1;
//             p->right=p2;
//             p1->left=p3;
//             p1->right=p4;
//             preorder(p);
//         return 0;
            
//         }
// 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* createNode(int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insert(struct node* root,int value){
    if(root==NULL)
    return createNode(value);
    if(value<root->data)
    root->left=insert(root->left,value);
    else if(value>root->data)
         root->right=insert(root->right,value);
         return root;

}
int height(struct node* root)
{
    if(root==NULL)
    return -1;
    int leftHeight=height(root->left);
      int rightHeight=height(root->right);
      if(leftHeight>rightHeight)
      return  leftHeight+1;
      else return rightHeight+1;
}
int main(){
    struct node* root=NULL;
    root=insert(root,50);
    insert(root,30);
     insert(root,70);
      insert(root,10);
       insert(root,40);
        insert(root,60);
         insert(root,80);
         printf("Height of BST=%d",height(root));
         return 0;
}