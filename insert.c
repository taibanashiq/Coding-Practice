#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

/* Traversal */
void linkedlistTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

/* Insert at first */
struct Node *insertATFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

/* Insert after a given node */
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    if(prevNode == NULL)
        return head;

    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

/* Insert at end */
struct Node *insertATEND(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    struct Node *p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

/* Insert at index */
struct Node *insertATIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while(i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 67;
    head->next = second;

    second->data = 35;
    second->next = third;

    third->data = 17;
    third->next = NULL;

    printf("Linked list before insertion:\n");
    linkedlistTraversal(head);

    /* insert after second node */
    head = insertAfterNode(head, third, 45);

    printf("\nLinked list after insertion:\n");
    linkedlistTraversal(head);

    return 0;
}

