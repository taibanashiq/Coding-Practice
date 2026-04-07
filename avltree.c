#include <stdio.h>
#include <stdlib.h>

// AVL Node Structure
struct Node {
    int data;
    struct Node *left, *right;
    int height;
};

// Utility Functions
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Create Node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Right Rotation
struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left Rotation
struct Node* leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    printf("%d%d",x->height,y->height);
    return y;
}

// Get Balance Factor
int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// INSERTION
struct Node* insert(struct Node* node, int data)
 {

    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // No duplicates
    node->height = 1 + max(height(node->left), height(node->right));
   

    int balance = getBalance(node);
printf("\n\n\t%d\t\n\n",balance);
    // LL Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(1000);

    // LR Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}



// Traversals
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// MAIN
int main() {
    struct Node *root = NULL;
    root = insert(root, 10);
    insert(root,20);
    insert(root,30);
     printf("Inorder: ");
    inorder(root);

    return 0;
}