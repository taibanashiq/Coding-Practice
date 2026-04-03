
// #include <stdio.h>
// #include <stdlib.h>

// /* ===== structure ===== */
// typedef struct sll
// {
//     int data;
//     struct sll *ptr;
// } node;

// /* ===== global variables ===== */
// node *head = NULL;
// int count = 0;

// /* ===== function declarations ===== */
// void createSLL();
// void insertSLLPos();
// void deleteSLLPos();
// void traverseSLL();
// void searchSLL();

// /* ===== main function ===== */
// int main()
// {
//     int choice;
//     char ch;

//     do
//     {
//         printf("\n\n--- MENU ---");
//         printf("\n1. Create");
//         printf("\n2. Insert (by position)");
//         printf("\n3. Delete (by position)");
//         printf("\n4. Traverse");
//         printf("\n5. Search");
//         printf("\n6. Exit");

//         printf("\nEnter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             createSLL();
//             break;
//         case 2:
//             insertSLLPos();
//             break;
//         case 3:
//             deleteSLLPos();
//             break;
//         case 4:
//             traverseSLL();
//             break;
//         case 5:
//             searchSLL();
//             break;
//         case 6:
//             exit(0);
//         default:
//             printf("Invalid choice");
//         }

//         printf("\nContinue (y/n): ");
//         scanf(" %c", &ch);

//     } while (ch == 'y' || ch == 'Y');

//     return 0;
// }

// /* ===== create ===== */
// void createSLL()
// {
//     node *newnode, *temp;
//     int val;
//     char ch;

//     do
//     {
//         newnode = (node *)malloc(sizeof(node));
//         if (newnode == NULL)
//         {
//             printf("Memory allocation failed\n");
//             return;
//         }

//         printf("Enter data: ");
//         scanf("%d", &val);

//         newnode->data = val;
//         newnode->ptr = NULL;

//         if (head == NULL)
//             head = newnode;
//         else
//         {
//             temp = head;
//             while (temp->ptr != NULL)
//                 temp = temp->ptr;
//             temp->ptr = newnode;
//         }

//         count++;

//         printf("Add more nodes (y/n): ");
//         scanf(" %c", &ch);

//     } while (ch == 'y' || ch == 'Y');
// }

// /* ===== insert by position ===== */
// void insertSLLPos()
// {
//     node *newnode, *temp;
//     int pos, val, i;

//     printf("Enter position: ");
//     scanf("%d", &pos);

//     if (pos < 1 || pos > count + 1)
//     {
//         printf("Invalid position\n");
//         return;
//     }

//     newnode = (node *)malloc(sizeof(node));
//     if (newnode == NULL)
//     {
//         printf("Memory allocation failed\n");
//         return;
//     }

//     printf("Enter data: ");
//     scanf("%d", &val);

//     newnode->data = val;

//     if (pos == 1)
//     {
//         newnode->ptr = head;
//         head = newnode;
//     }
//     else
//     {
//         temp = head;
//         for (i = 1; i < pos - 1; i++)
//             temp = temp->ptr;

//         newnode->ptr = temp->ptr;
//         temp->ptr = newnode;
//     }

//     count++;
// }

// /* ===== delete by position ===== */
// void deleteSLLPos()
// {
//     node *temp, *prev;
//     int pos, i;

//     if (head == NULL)
//     {
//         printf("List is empty\n");
//         return;
//     }

//     printf("Enter position: ");
//     scanf("%d", &pos);

//     if (pos < 1 || pos > count)
//     {
//         printf("Invalid position\n");
//         return;
//     }

//     if (pos == 1)
//     {
//         temp = head;
//         head = head->ptr;
//         free(temp);
//     }
//     else
//     {
//         temp = head;
//         for (i = 1; i < pos; i++)
//         {
//             prev = temp;
//             temp = temp->ptr;
//         }
//         prev->ptr = temp->ptr;
//         free(temp);
//     }

//     count--;
// }

// /* ===== traverse ===== */
// void traverseSLL()
// {
//     node *temp;

//     if (head == NULL)
//     {
//         printf("List is empty\n");
//         return;
//     }

//     temp = head;
//     printf("SLL elements: ");
//     while (temp != NULL)
//     {
//         printf("%d -> ", temp->data);
//         temp = temp->ptr;
//     }
//     printf("NULL\n");
// }

// /* ===== search ===== */
// void searchSLL()
// {
//     node *temp;
//     int key, pos = 1, found = 0;

//     printf("Enter element to search: ");
//     scanf("%d", &key);

//     temp = head;
//     while (temp != NULL)
//     {
//         if (temp->data == key)
//         {
//             printf("Element found at position %d\n", pos);
//             found = 1;
//             break;
//         }
//         temp = temp->ptr;
//         pos++;
//     }

//     if (!found)
//         printf("Element not found\n");
// }
#include <stdio.h>
#include <stdlib.h>

/* ===== structure ===== */
typedef struct sll
{
    int data;
    struct sll *ptr;
} node;

/* ===== global variables ===== */
node *head = NULL;
int count = 0;

/* ===== function declarations ===== */
void createSLL();
void insertSLLPos();
void deleteSLLPos();
void traverseSLL();
void searchSLL();

/* ===== main function ===== */
int main()
{
    int choice;
    char ch;

    do
    {
        printf("\n\n--- MENU ---");
        printf("\n1. Create");
        printf("\n2. Insert (by position)");
        printf("\n3. Delete (by position)");
        printf("\n4. Traverse");
        printf("\n5. Search");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createSLL();
            break;

        case 2:
            insertSLLPos();
            break;

        case 3:
            deleteSLLPos();
            break;

        case 4:
            traverseSLL();
            break;

        case 5:
            searchSLL();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice");
        }

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}

/* ===== create SLL ===== */
void createSLL()
{
    node *newnode, *temp;
    int val;
    char ch;

    do
    {
        newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &val);

        newnode->data = val;
        newnode->ptr = NULL;

        if (head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while (temp->ptr != NULL)
                temp = temp->ptr;
            temp->ptr = newnode;
        }

        count++;

        printf("Add more nodes (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}

/* ===== insert by position ===== */
void insertSLLPos()
{
    node *newnode, *temp;
    int pos, val, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &val);

    newnode->data = val;

    if (pos == 1)
    {
        newnode->ptr = head;
        head = newnode;
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1; i++)
            temp = temp->ptr;

        newnode->ptr = temp->ptr;
        temp->ptr = newnode;
    }

    count++;
}

/* ===== delete by position ===== */
void deleteSLLPos()
{
    node *temp, *prev;
    int pos, i;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        temp = head;
        head = head->ptr;
        free(temp);
    }
    else
    {
        temp = head;
        for (i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->ptr;
        }
        prev->ptr = temp->ptr;
        free(temp);
    }

    count--;
}

/* ===== traverse SLL ===== */
void traverseSLL()
{
    node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("SLL elements: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->ptr;
    }
    printf("NULL\n");
}

/* ===== search SLL ===== */
void searchSLL()
{
    node *temp;
    int key, pos = 1, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            found = 1;
            break;
        }
        temp = temp->ptr;
        pos++;
    }

    if (!found)
        printf("Element not found\n");
}

