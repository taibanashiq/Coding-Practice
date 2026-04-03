// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// };

// struct node* createNode(int data){
//     struct node *n; // creating a node pointer
//     n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
//     n->data = data; // Setting the data
//     n->left = NULL; // Setting the left and right children to NULL
//     n->right = NULL; // Setting the left and right children to NULL
//     return n; // Finally returning the created node
// }

// int main(){
   
//     // Constructing the root node - Using Function (Recommended)
//     struct node *p = createNode(2);
//     struct node *p1 = createNode(1);
//     struct node *p2 = createNode(4);
     

//     // Linking the root node with left and right children
//     p->left = p1;
//     p->right = p2;

//     printf("Root: %d\n", p->data);
//     printf("Left: %d\n", p->left->data);
//     printf("Right: %d\n", p->right->data);
//     return 0;
// }

